#include <ncurses.h>
#include "../lib/window.h"
#include "../lib/constants.h"



void GameWindow::create_game_window() {
	// @params: x, y coordinates and the width, height from those coordinates
	// @return: None

	initscr();
	refresh();
	noecho();
	WINDOW *win;
	win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, START_Y, START_X);
	box(win, 0, 0);
	wrefresh(win);
	wgetch(win);

	char ch;

	// wait until user presses 'q'
	while((ch = getch()) != 'q') {}

	// close the
	endwin();

	

}

int main() {
	GameWindow gm;
	gm.create_game_window();
	return 0;
}