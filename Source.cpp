#include <iostream>
#include <cstdlib>
using namespace std;

int row[4] = { 1, 3, 5, 7 };
bool gameover;
char turn;

void Pturn() {
	int crow, cstar;
	cout << "Enter your chosen row." << endl;
	cin >> crow;
	while (crow < 1 || crow > 4 || row[crow-1] == 0)
	{
		cout << "Please enter a valid row number between 1 to 4 which has stars left." << endl;
		cin >> crow;
	}
	cout << "Enter the number of stars you want to remove." << endl;
	cin >> cstar;
	while (cstar < 1 || cstar > row[crow-1])
	{
		cout << "Please enter a valid star number considering the starts left in row " << crow << endl;
		cin >> cstar;
	}
	row[crow-1] -= cstar;
}

void CheckStatus() {
	if (row[0] == 0 && row[1] == 0 && row[2] == 0 && row[3] == 0)
	{
		gameover = true;
		if (turn == 'Y')
		{
			cout << "Sorry, You Lost";
		}
		else
		{
			cout << "Congrats, you won!!";
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < row[i]; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
}

int findBinary(int number) {
	switch (number)
	{
	case 0:
		return 1000;
	case 1:
		return 1001;
	case 2:
		return 1010;
	case 3:
		return 1011;
	case 4:
		return 1100;
	case 5:
		return 1101;
	case 6:
		return 1110;
	case 7:
		return 1111;
	}
}

void Myturn(){
	/*Make Nim Sum Calculator now*/
	int rowbin[4];
	int nimsum, mrow, mstar, emptycount, lastcount, finmove;
	emptycount = 0;
	lastcount = 0;
	finmove = 0;
	for (int i = 0; i < 4; i++)
	{
		rowbin[i] = findBinary(row[i]);
		//cout << rowbin[i] << endl;
	}
	nimsum = rowbin[0] ^ rowbin[1] ^ rowbin[2] ^ rowbin[3];
	//cout << nimsum << endl;
	cout << "Next Move" << endl;
	for (int j = 0; j < 4; j++)
	{
		if (row[j] > 1)
		{
			lastcount += 1;
			finmove = j;
		}
		else if (row[j] == 0)
		{
			emptycount += 1;
		}
	}
	if (lastcount == 1)
	{
		if (emptycount == 3)
		{
			row[finmove] = 1;
		}
		else
		{
			row[finmove] = 0;
		}
	}
	else
	{
		switch (nimsum)
		{
		case 0:
			mrow = rand() % 4;
			while (row[mrow] == 0)
			{
				mrow = rand() % 4;
			}
			mstar = rand() % row[mrow] + 1;
			row[mrow] -= mstar;
			break;
		case 1:
			for (int i = 0; i < 4; i++)
			{
				if (rowbin[i] % 2 != 0)
				{
					mrow = i;
					break;
				}
			}
			mstar = 1;
			row[mrow] -= mstar;
			break;
		case 26:
			mrow = rand() % 4;
			while (row[mrow] <= 1)
			{
				mrow = rand() % 4;
			}
			mstar = 2;
			row[mrow] -= mstar;
			break;
		case 27:
			mrow = 3;
			if (row[mrow] == 7)
			{
				mstar = 3;
			}
			else if (row[mrow] == 3)
			{
				mstar = 2;
			}
			else
			{
				for (int k = 1; k < 3; k++)
				{
					if (row[k] == 3) {
						mrow = k;
						mstar = 3;
						break;
					}
				}
			}
			if (mstar != 3 && mstar != 2)
			{
				mrow = rand() % 4;
				while (row[mrow] != 2)
				{
					mrow = rand() % 4;
				}
				mstar = 1;
			}
			row[mrow] -= mstar;
			break;
		case 1956:
			mrow = rand() % 4;
			while (row[mrow] <= 3)
			{
				mrow = rand() % 4;
			}
			mstar = 4;
			row[mrow] -= mstar;
			break;
		case 1957:
			if (row[3] >= 4)
			{
				mrow = 3;
			}
			else
			{
				mrow = 2;
			}
			if (row[mrow] % 2 == 0)
			{
				mstar = 3;
			}
			else
			{
				mstar = 5;
			}
			row[mrow] -= mstar;
			break;
		case 1982:
			if (row[3] >= 4)
			{
				mrow = 3;
				if (row[mrow] <= 5)
				{
					mstar = 3;
				}
				else
				{
					mstar = 6;
				}
			}
			else
			{
				mrow = 2;
				mstar = 2;
			}
			row[mrow] -= mstar;
			break;
		case 1983:
			if (row[3] >= 4)
			{
				mrow = 3;
			}
			else
			{
				mrow = 2;
			}
			if (row[mrow] == 4)
			{
				mstar = 2;
			}
			else if (row[mrow] == 7)
			{
				mstar = 7;
			}
			else if (row[mrow] == 6)
			{
				mstar = 5;
			}
			{
				mstar = 3;
			}
			row[mrow] -= mstar;
			break;
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < row[i]; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "Rules: In each turn, you can pick as many stars as you want from one single row. The player who picks the last star loses. Would you like to go first? (Y or N)" << endl;
	cin >> turn;
	while (turn != 'Y' && turn != 'N')
	{
		cout << "Enter Y or N only!" << endl;
		cin >> turn;
	}
	gameover = false;
	while (!gameover)
	{
		if (turn == 'Y')
		{
			Pturn();
			CheckStatus();
			turn = 'N';
		}
		else
		{
			Myturn();
			CheckStatus();
			turn = 'Y';
		}
	}
}