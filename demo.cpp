#include <ncurses.h>
#include <unistd.h>

int main()
{
	int x = 0, y = 0;
	int xMax = 0, yMax = 0;
	int deltX = 0, deltY = 0;
	int ch;

	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);

 	// Global var `stdscr` is created by the call to `initscr()`
 	getmaxyx(stdscr, yMax, xMax);

	while (1) {
		clear();
		mvprintw(y, x, "o");
		refresh();
		ch = getch();
		usleep(30000);
		deltX = 0;
		deltY = 0;
		if (ch == KEY_DOWN)
			deltY = 1;
		if (ch == KEY_UP)
			deltY = -1;
		if (ch == KEY_RIGHT)
			deltX = 1;
		if (ch == KEY_LEFT)
			deltX = -1;
		x += deltX;
		y += deltY;
	}
	endwin();
}