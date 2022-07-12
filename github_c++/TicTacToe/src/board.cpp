/*
 * board.cpp
 *
 *  Created on: July 11, 2022
 *      Author: Dallas Eaton
 */

#include "board.h"

#include <iostream>

using namespace std;
using tic_tac_toe::Board;

Board::Board(): squares({'x','1','2','3','4','5','6','7','8','9'}) {}

Board::~Board() {}

/*
 * Draw the board using the squares
 */
void Board::draw_board()
{
	cout << "     |     |     " << endl;
	cout << "  " << squares[1] << "  |  " << squares[2] << "  |  " << squares[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << squares[4] << "  |  " << squares[5] << "  |  " << squares[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << squares[7] << "  |  " << squares[8] << "  |  " << squares[9] << endl;
	cout << "     |     |     " << endl << endl;
}

/*************************************************
 * Check if there is a win on the game board
 * Return 1 if game is won
 * Return 0 if game is tied
 * Return -1 if game is in progress
 *************************************************/
int Board::check_win()
{
	if (squares[1] == squares[2] && squares[2] == squares[3])
	{
		return 1;
	}
	else if (squares[1] == squares[5] && squares[5] == squares[9])
	{
		return 1;
	}
	else if (squares[1] == squares[4] && squares[4] == squares[7])
	{
		return 1;
	}
	else if (squares[4] == squares[5] && squares[5] == squares[6])
	{
		return 1;
	}
	else if (squares[7] == squares[8] && squares[8] == squares[9])
	{
		return 1;
	}
	else if (squares[3] == squares[5] && squares[5] == squares[7])
	{
		return 1;
	}
	else if ( squares[2] == squares[5] && squares[5] == squares[8])
	{
		return 1;
	}
	else if ( squares[3] == squares[6] && squares[6] == squares[9])
	{
		return 1;
	}
	else if (squares[1] != '1' && squares[2] != '2' && squares[3] != '3' &&
			 squares[4] != '4' && squares[5] != '5' && squares[6] != '6' &&
			 squares[7] != '7' && squares[8] != '8' && squares[9] != '9')
	{
		return 0;
	}
	else
	{
		return -1;
	}

}

char Board::get_square(int square)
{
	return squares[square];
}

void Board::set_square(int square, char mark)
{
	squares[square] = mark;
}
