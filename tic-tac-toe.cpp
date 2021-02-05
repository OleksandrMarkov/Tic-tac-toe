#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

//players` names
char name1 [20];
char name2 [20];

// game field
char game_field[3][3];
bool move;

int i, j;

void instruction()
{
	cout<<"Tic-tac-toe\n";
	int letter = 0;
	int letter_A_code = 49; 
	
	/*array filling:
	1 | 2 | 3
	4 | 5 | 6
	7 | 8 | 9
	*/
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			cout<< "|" << letter + 1 << ' ';
			game_field[i][j] = char(letter_A_code + letter);
			letter++;
		}
		cout << '|';
		cout << endl;
	}

	cout<<"Click any to start ...";
	_getch();	
}

bool input()
{
	// game field displaying
	for (i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			cout << "| " << game_field[i][j] << ' ';
		}
		cout << '|';
		cout << endl;
	}
	
	cout << endl;
	if (move)
		cout << name1 << " moves..." << endl;  
	else
		cout << name2 << " moves..." << endl;
		
	int cell;
	cin >> cell;
	
	if (cell < 1 || cell > 9)
	{
		return false;
	}
	/* i, j - indexes of the row and the column
	00 01 02
	10 11 12
	20 21 22
	*/
	if(cell % 3 == 0)
	{
		i = cell / 3 - 1;
		j = 2;	
	}	
	else
	{
		i = cell / 3;
		j = cell % 3 - 1;
	}
	
	if (game_field[i][j] == '0' || game_field[i][j] == 'X')
		return false;
	
	if(move)
	{
		game_field[i][j] = 'X';
		move = false;
	}
	else
	{
		game_field[i][j] = '0';
		move = true; 
	}
		return true;
}


bool win()
{
	bool h = false, v = false, d = false;
	
	for(i = 0; i <3; i++)
	// horizontal
		if( (game_field[i][0] == game_field[i][1]) && (game_field[i][0] == game_field[i][2]) )
		{
			h = true;
			return true;	
		}
		else
	// vertical	
			if( (game_field[0][i] == game_field[1][i]) && (game_field[0][i] == game_field[2][i]) )
			{
				v = true;
				return true;	
			}
		else
		//diagonal
			if( (game_field[0][0] == game_field[1][1] && game_field[0][0] == game_field[2][2]) || (game_field[0][2] == game_field[1][1] && game_field[0][2] == game_field[2][0]) )
			{
				d = true;
				return true;
			}
	
	// can it be a draw?
	int counter = 0;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if (game_field[i][j] == 'X' || game_field[i][j] == '0')
				counter += 1;
		}
	}
	if (counter == 9 && h == false && v == false && d == false)
	{
		cout << "It is a draw!!!\n";
		_getch();
		exit(0); 
	}					
	return false;
}


int main()
{
	instruction();
	system("cls");
	
	cout << "The first player`s name: ";
	cin.getline(name1, 20); 
	cout << "The second player`s name: ";
	cin.getline(name2, 20);
	
	srand(time(NULL));
	// who begins?
	if (rand() & 1)
		move = true;
	else move = false;
	
	while (!win())
	{
		system("cls");
		if (!input())
		{
			cout << "Invalid data!";
			_getch();	
		}	
	}
	
	system("cls");
	
	if (move)
		cout << name2 << " won!" << endl;  
	else
		cout << name1 << " won!" << endl;
	
	system ("pause");
	return 0;
}
