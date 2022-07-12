//============================================================================
// Name        : tic_tac_toe.cpp
// Author      : Dallas Eaton
// Version     :
// Copyright   : copyright notice
// Description : Contains the main function for the TicTacToe game
//============================================================================

#include "board.h"
#include <iostream>

using namespace std;
using tic_tac_toe::Board;

char again;
int player = 1;
bool illegal = false;
Board board =  Board();

int play_again();

int main()
{
	int marker = -1;
	int selection;

	char mark[3] = {'.', 'X', 'O'};


	while (marker == -1)
	{
		cout << endl << endl << "Tic-Tac-Toe" << endl << endl;
		cout << "Player 1 = X's  |  Player 2 = O's" << endl << endl << endl;

		board.draw_board();

		cout << "Player " << player << ", enter a number on the board: ";
		cin >> selection;

		if (selection == 1 && board.get_square(1) == '1')
		{
			board.set_square(1, mark[player]);
		}
		else if (selection == 2 && board.get_square(2) == '2')
		{
			board.set_square(2, mark[player]);
		}
		else if (selection == 3 && board.get_square(3) == '3')
		{
			board.set_square(3, mark[player]);
		}
		else if (selection == 4 && board.get_square(4) == '4')
		{
			board.set_square(4, mark[player]);
		}
		else if (selection == 5 && board.get_square(5) == '5')
		{
			board.set_square(5, mark[player]);
		}
		else if (selection == 6 && board.get_square(6) == '6')
		{
			board.set_square(6, mark[player]);
		}
		else if (selection == 7 && board.get_square(7) == '7')
		{
			board.set_square(7, mark[player]);
		}
		else if (selection == 8 && board.get_square(8) == '8')
		{
			board.set_square(8, mark[player]);
		}
		else if (selection == 9 && board.get_square(9) == '9')
		{
			board.set_square(9, mark[player]);
		}
		else
		{
			cout << "Illegal move, press ENTER to try again.";

			illegal = true;
			cin.ignore();
			cin.get();
		}

		marker = board.check_win();

		if (marker == 1)
		{
			board.draw_board();
			cout << "Player " << player << " WINS!!" << endl << endl;
			marker = play_again();
		}
		else if (marker == 0)
		{
			board.draw_board();
			cout << "It's a DRAW!!";
			marker = play_again();
		}

		if (!illegal) {
			if (player == 1){ player++; } else { player--; }
		}
		illegal = false;
	}
}

/*
 * At the end of the game, if another game is desired,
 * game will be reset and a new board will be made.
 */
int play_again()
{
	cout << "Play again? (Y/N)";
	cin >> again;
	if (again == 'Y' || again == 'y')
	{
		board = Board();
		illegal = true;
		player = 1;
		cout << endl << "Goodbye!!";
		return -1;
	}
}
