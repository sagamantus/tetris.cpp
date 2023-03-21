#include <ncurses.h>
#include <vector>
#include <string>
#include <utility>

#include "../lib/window.h"
#include "../lib/constants.h"
#include "../lib/playfield.h"


void GameWindow::display() {

	initscr();
	noecho();
	Tetromino ttmno;

	std::vector<std::vector<std::string>> ttmno_grid = ttmno.tetromino_grid;
	std::pair<int, int> coord_pair = ttmno.position;

	int rows = ttmno_grid.size();
	int cols = ttmno_grid[0].size();

	WINDOW *win = newwin(rows, cols, coord_pair.second, coord_pair.first);

	for( int i = 0; i < rows; i++ ) {
		for( int j = 0; j < cols; j++) {
			if( ttmno_grid[i][j] == '#' ) {
				mvwaddch(win, i, j, ttmno_grid[i][j]);
			}
		}
	}

	wrefresh(win);

	// waiting until user presses 'q'
	while(wgetch(win) != 'q') {}
	//closes the window
	endwin();

}
