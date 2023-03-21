#include <ncurses.h>
#include <vector>
#include <string>
#include <utility>

#include "../lib/window.h"
#include "../lib/constants.h"
#include "../lib/tetromino.h"
#include "../lib/playfield.h"

void GameWindow::display(Playfield pf, Tetromino ttmno)
{
	std::vector<std::vector<std::string>> game_grid = pf.game_grid;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (ttmno.tetromino_grid[i][j] == "0")
				game_grid[ttmno.position.first + i][ttmno.position.second + j] = ttmno.tetromino_grid[i][j];
		}
	}

	printw("> TETRIS.cpp\n");
	printw("w - rotate; a - left; d - right; s - down; <space> - drop\n\n");
	for (auto x : game_grid)
	{
		for (auto y : x)
		{
			const char * block = y.c_str();
			printw("%s", block);
		}
		printw("\n");
	}
	printw("\n");
	printw("Score: %d\n", pf.score);
}

void GameWindow::refresh(Playfield pf, Tetromino ttmno)
{
	clear();
	this->display(pf, ttmno);
}

void GameWindow::end()
{
	endwin();
}
