#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "Entity.hpp"
#include "ft_retro.hpp"


int main()
{
	int xMax = 0, yMax = 0;
	t_vec2i delt;
	int ch;
	WINDOW* win;
	Entity Player;

	srand(time(NULL));
	win = initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	getmaxyx(win, yMax, xMax);
	Player.setSymbol("A");
	while (42) {
		clear();
		attron(A_BOLD);
		box(win, 0, 0);
		attroff(A_BOLD);
		Player.draw();
		refresh();
		ch = getch();
		usleep(10000);
		delt = (t_vec2i){0, 0};
		if (ch == KEY_DOWN)
			delt.y = 1;
		if (ch == KEY_UP)
			delt.y = -1;
		if (ch == KEY_RIGHT)
			delt.x = 1;
		if (ch == KEY_LEFT)
			delt.x = -1;
		Player.move(delt);
	}
	endwin();
}