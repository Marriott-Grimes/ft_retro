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

t_vec2i	readKey(int key, WINDOW* win)
{
	t_vec2i		delt;

	delt = (t_vec2i){0, 0};
	if (key == 27)
	{
		delwin(win);
		endwin();
		exit(0);
	}
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

void	initStars(Star	bg[NUMSTARS])
{
	for (int i = 0; i < NUMSTARS; i++)
	{
		bg[i].setSymbol(".");
		bg[i].Entity::setPos((t_vec2i){rand() % XMAX, rand() % YMAX + 1});
	}
}

void	initAsteroids(Star	asteroid[NUMENEMIES])
{
	for (int i = 0; i < NUMENEMIES; i++)
	{
		asteroid[i].setSymbol("O");
		asteroid[i].Entity::setPos((t_vec2i){rand() % XMAX, rand() % YMAX + 1});
	}
}

int main(void)
{
	
	int		key;
	WINDOW	*win;
	Entity	Player;
	Star	bg[NUMSTARS];
	Star	asteroid[NUMENEMIES];
	Bullet	bullet[NUMBULLETS];
	int		tick = 0;


	std::srand(time(NULL));
	win = windowSetup();
	Player.setSymbol("A");
	Player.setPos((t_vec2i){40, 20});
	Player.setScreenSize((t_vec2i){XMAX, YMAX});
	initStars(bg);
	initAsteroids(asteroid);
	while (42) {
		clear();
		for (int i = 0; i < NUMBULLETS; i++)
		{
			if (bullet[i].Entity::getPos().x != 1000)
				bullet[i].Entity::draw();
			if (!(tick % 10))
			{
				bullet[i].updateIfActive();
				bullet[i].recharge();
			}
		}
		for (int i = 0; i < NUMSTARS; i++)
			bg[i].update();
		for (int i = 0; i < NUMENEMIES; i++)
		{
			asteroid[i].Entity::draw();
			for (int j = 0; j < NUMBULLETS; j++)
			{
				if (asteroid[i].Entity::collision(bullet[j].Entity::getPos()))
					asteroid[i].resetHeight();
			}
			if (asteroid[i].Entity::collision(Player.getPos()))
			{
				delwin(win);
				endwin();
				exit(0);
			}
			if (!(tick % 20))
				asteroid[i].update();
		}
		Player.draw();
		refresh();
		key = getch();
		usleep(10000);
		if (key == ' ')
		{
			for (int i = 0; i < NUMBULLETS; i++)
			{
				if (bullet[i].fire(Player.getPos()))
					break ;
			}
		}
		Player.move(readKey(key, win));
		tick++;
	}
	delwin(win);
	endwin();
	return (0);
}
