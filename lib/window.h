#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "./tetromino.h"
#include "./playfield.h"

class GameWindow {

	public:

		void display(Playfield pf, Tetromino ttmno);
		void refresh(Playfield pf, Tetromino ttmno);
		void end();
};

#endif