#include <ncurses.h>
#include "window.h"



void GameWindow::create_game_window(int x, int y, int width, int height) {
	// @params: x, y coordinates and the width, height from those coordinates
	// @return: None
	WINDOW *win;

	attron(A_BOLD);
	box()
}