#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include "./lib/constants.h"

void ping(void)
{

	printw("Ping!\n");
}

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
	struct timespec last_ping_time, current_time;
	clock_gettime(CLOCK_MONOTONIC, &last_ping_time);

	initscr();

	cbreak();
	noecho();
	nodelay(stdscr, TRUE);

	scrollok(stdscr, TRUE);

	while (1)
	{
		if (kbhit())
		{
			// Key pressed
			printw("Key pressed! It was: %d\n", getch());
			refresh();
			clock_gettime(CLOCK_MONOTONIC, &current_time);
			last_ping_time = current_time;
		}
		else
		{
			// No key pressed
			refresh();
		}

		// check if one second has passed since last ping
		clock_gettime(CLOCK_MONOTONIC, &current_time);
		if (current_time.tv_sec - last_ping_time.tv_sec >= DROP_RATE)
		{
			ping();
			last_ping_time = current_time;
		}

		usleep(1000); // sleep for 1 millisecond
	}

	endwin(); // close ncurses window
	return 0; // exit program
}
