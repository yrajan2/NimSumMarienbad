#include <iostream>
using namespace std;

int row[2] = { 8, 24 };

void printBoard(int a, int b) {
	int grow = 0;
	int gcol = 24;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (a == i && j == b)
			{
				cout << "R";
			}
			else if (grow == i && gcol == j)
			{
				cout << "G";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}

bool checkStatus(int a, int b) {
	if (a == 0 && b == 24)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Pturn(int &a, int &b) {
	cout << "Do you want to move the rook horizontally or vertically?" << endl << "1. vertically" << endl << "2. Horizontally" << endl;
	int move;
	do
	{
		cin >> move;
	} while (move != 1 && move != 2);
	int steps;
	cout << "How many steps do you want to move?" << endl;
	do
	{
		cin >> steps;
	} while (steps < 1 || steps > row[move-1]);
	row[move - 1] -= steps;
	if (move == 1)
	{
		a -= steps;
	}
	else
	{
		b += steps;
	}
}

void Mturn(int &a, int &b) {
	int steps;
	if (row[0] > row[1])
	{
		steps = row[0] - row[1];
		a -= steps;
		row[0] = row[1];
	}
	else if (row[1] > row[0])
	{
		steps = row[1] - row[0];
		b += steps;
		row[1] = row[0];
	}
	else
	{
		steps = 1;
		if (row[1] != 0)
		{
			row[1] -= steps;
			b += steps;
		}
		else
		{
			row[0] -= steps;
			a -= steps;
		}
	}
}

int main() {
	cout << "Welcome to the rooks game!!" << endl;
	cout << "In this game, you have a 9 * 25 chess board. Your goal is to move the rook from the bottom left to the top right corner. The rook can move in the same manner as it does in chess." << endl;
	cout << "The illustration is shown below. R is the Rook's position" << endl;
	int rrow = 8;
	int rcol = 0;
	int turn = 0;
	printBoard(rrow, rcol);
	cout << "Would you like to take the first turn?" << endl << "1. Yes" << endl << "2. No" << endl;
	while (turn != 1 && turn != 2)
	{
		cin >> turn;
	}
	while (checkStatus(rrow, rcol))
	{
		if (turn == 1)
		{
			Pturn(rrow, rcol);
			printBoard(rrow, rcol);
			turn = 2;
		}
		else
		{
			Mturn(rrow, rcol);
			cout << "My turn" << endl;
			printBoard(rrow, rcol);
			turn = 1;
		}
	}
	if (turn == 1)
	{
		cout << "Sorry you lost!";
	}
	else
	{
		cout << "Congrats! You Won!";
	}
}