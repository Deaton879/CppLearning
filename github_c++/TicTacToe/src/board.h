/*
 * board.h
 *
 *  Created on: July 11, 2022
 *      Author: Dallas Eaton
 */

#ifndef SRC_BOARD_H_
#define SRC_BOARD_H_

namespace tic_tac_toe {
	class Board {
		private:
			char squares[10];

		public:
			Board();
			~Board();

			void draw_board();
			int check_win();
			char get_square(int square);
			void set_square(int square, char mark);
	};
}
#endif /* SRC_BOARD_H_ */

