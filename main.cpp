#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include "./lib/constants.h"
#include "./lib/playfield.h"
#include "./lib/tetromino.h"
#include "./lib/window.h"

int kbhit(void)
{
	int ch = getch();

	if (ch != ERR)
	{
		ungetch(ch);
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	GameWindow game_win;
	Playfield pf;
	Tetromino ttmno = ttmno.generate_tetromino(pf);
	ttmno.move_down(pf);
	ttmno.move_down(pf);

	struct timespec last_ping_time, current_time;
	clock_gettime(CLOCK_MONOTONIC, &last_ping_time);

	initscr();

	cbreak();
	noecho();
	nodelay(stdscr, TRUE);

	// scrollok(stdscr, TRUE);

	while (1)
	{
		if (kbhit())
		{
			// Key pressed
			char c = getch();
			if (c == 'w')
			{
				ttmno.rotate(pf);
			}
			else if (c == 'a')
			{
				ttmno.move_left(pf);
			}
			else if (c == 'd')
			{
				ttmno.move_right(pf);
			}
			else if (c == 's')
			{
				ttmno.move_down(pf);
			}
			else if (c == ' ')
			{
				ttmno.drop(pf);
			}
			else if (c == 'q')
			{
				break;
			}
			refresh();
			clock_gettime(CLOCK_MONOTONIC, &current_time);
			last_ping_time = current_time;
		}

		clear();
		game_win.refresh(pf, ttmno);

		// check if one second has passed since last ping
		clock_gettime(CLOCK_MONOTONIC, &current_time);
		if (current_time.tv_sec - last_ping_time.tv_sec >= DROP_RATE)
		{
			last_ping_time = current_time;
			ttmno.move_down(pf);
		}

		usleep(1000); // sleep for 1 millisecond
	}

	endwin(); // close ncurses window
	
	std::cout << "GAME OVER!" << std::endl;
	std::cout << "Score: " << pf.score << std::endl;
	return 0; // exit program
}
