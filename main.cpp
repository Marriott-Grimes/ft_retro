/* ************************************************************************** */
/*					                                                    */
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
	int			xMax = 80;
	int			yMax = 24;
	t_vec2i		delt;
	int			key;
	WINDOW		*win;
	Entity		Player;
	Star	bg[10];


	std::srand(time(NULL));
	win = initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	curs_set(FALSE);
	keypad(win, TRUE);
	// getmaxyx(win, yMax, xMax);
	win  =  newwin(yMax, xMax, 0, 0);

	Player.setSymbol("A");
	Player.setScreenSize((t_vec2i){xMax, yMax});
	for (int i = 0; i < 10; i++)
	{
		bg[i].setSpeed(1);
		bg[i].setSymbol(".");
		bg[i].Entity::setScreenSize((t_vec2i){xMax, yMax});
		bg[i].Entity::setPos((t_vec2i){rand() % xMax + 1, rand() % yMax + 1});
	}
	while (42) {
		clear();
		// attron(A_BOLD);
		// box(win, 0, 0);
		// attroff(A_BOLD);
		for (int i = 0; i < 10; i++)
			bg[i].update();
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
