/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <akalmyko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:07:18 by akalmyko          #+#    #+#             */
/*   Updated: 2017/07/08 12:35:35 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
// #include <unistd.h>
// #include <cstdlib>
// #include <ctime>
// #include <signal.h>

int main(void) {
	initscr();                 /* Start curses mode     */
    printw("Hello World !!!"); /* Print Hello World    */
    refresh();                 /* Print it on to the real screen */
    getch();                   /* Wait for user input */
    endwin();                  /* End curses mode    */
    return (0);
}
