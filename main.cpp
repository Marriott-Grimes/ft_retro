/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <akalmyko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:50:51 by akalmyko          #+#    #+#             */
/*   Updated: 2017/07/09 11:52:31 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retro.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Star.hpp"
#include "Entity.hpp"
#include "Asteroid.hpp"

void	ft_check_key()
{

}

int main(void)
{
	int			xMax = 0;
	int			yMax = 0;
	t_vec2i		delt;
	int			key;
	WINDOW		*win;
	Entity		Player;

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
		key = getch();
		usleep(10000);
		delt = (t_vec2i){0, 0};
		if (key == 27)
			break;
		if (key == KEY_DOWN)
			delt.y = 1;
		if (key == KEY_UP)
			delt.y = -1;
		if (key == KEY_RIGHT)
			delt.x = 1;
		if (key == KEY_LEFT)
			delt.x = -1;
		Player.move(delt);
	}
	endwin();
}
