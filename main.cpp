/* ************************************************************************** */
/*					                                                          */
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
#include "Bullet.hpp"

WINDOW* windowSetup()
{
	WINDOW		*win;
	win = initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	curs_set(FALSE);
	keypad(win, TRUE);
	nodelay(win, true);
	win = newwin(YMAX, XMAX, 0, 0);
	return (win);
}

t_vec2i	readKey(int key)
{
	t_vec2i		delt;

	delt = (t_vec2i){0, 0};
	if (key == 27)
		exit(0);
	if (key == KEY_DOWN)
		delt.y = 1;
	if (key == KEY_UP)
		delt.y = -1;
	if (key == KEY_RIGHT)
		delt.x = 1;
	if (key == KEY_LEFT)
		delt.x = -1;
	return (delt);
}

int main(void)
{
	
	int		key;
	WINDOW	*win;
	Entity	Player;
	Star	bg[NUMSTARS];
	Star	asteroid[NUMENEMIES];
	Bullet	bullet;
	int		tick = 0;


	std::srand(time(NULL));
	win = windowSetup();
	Player.setSymbol("A");
	Player.setPos((t_vec2i){40, 20});
	Player.setScreenSize((t_vec2i){XMAX, YMAX});
	for (int i = 0; i < NUMSTARS; i++)
	{
		bg[i].setSymbol(".");
		bg[i].Entity::setPos((t_vec2i){rand() % XMAX, rand() % YMAX + 1});
	}
	for (int i = 0; i < NUMENEMIES; i++)
	{
		asteroid[i].setSymbol("*");
		asteroid[i].Entity::setPos((t_vec2i){rand() % XMAX, rand() % YMAX + 1});
	}
	while (42) {
		clear();
		if (!(tick % 10))
			bullet.updateIfActive();
		bullet.recharge();
		for (int i = 0; i < NUMSTARS; i++)
			bg[i].update();
		for (int i = 0; i < NUMENEMIES; i++)
		{
			asteroid[i].Entity::draw();
			if (asteroid[i].Entity::collision(bullet.Entity::getPos()))
				asteroid[i].resetHeight();
			if (asteroid[i].Entity::collision(Player.getPos()))
				exit(0);
		}
		if (!(tick % 20))
		{
			for (int i = 0; i < NUMENEMIES; i++)
				asteroid[i].update();
		}
		Player.draw();
		refresh();
		key = getch();
		usleep(10000);
		if (key == ' ')
			bullet.fire(Player.getPos());	
		Player.move(readKey(key));
		tick++;
	}
	endwin();
}
