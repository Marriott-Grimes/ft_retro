/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <akalmyko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:46:18 by akalmyko          #+#    #+#             */
/*   Updated: 2017/07/09 11:52:36 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star.hpp"

/* constructors/desctructors/copier */

Star::Star(int xMax, int yMax) {
	this->Entity::setScreenSize((t_vec2i){xMax, yMax});
	return ;
}

Star::~Star(void) {
	return ;
}

Star::Star()
{
	return ;
}

Star::Star(Star const & obj)
{
	*this = obj;
	return ;
}

Star&	Star::operator=(Star const & rhs)
{
	this->Entity::setPos(rhs.Entity::getPos());
	this->Entity::setSymbol(rhs.Entity::getSymbol());
	this->Entity::setScreenSize(rhs.Entity::getScreenSize());
	this->_speed = rhs.getSpeed();
	return (*this);
}

/* member methods */

int		Star::getSpeed(void) const
{
	return (this->_speed);
}

void	Star::setSpeed(int s)
{
	this->_speed = s;
	return ;
}

void	Star::update()
{
	this->Entity::move((t_vec2i){0, this->getSpeed()});
	if (this->Entity::getPos().y >= this->Entity::getScreenSize().y)
		this->resetHeight();
	this->Entity::draw();
	return ;
}

void	Star::resetHeight()
{
	int x;

	x = rand() % this->Entity::getScreenSize().x + 1;
	this->Entity::setPos((t_vec2i){x, 1});
	return ;
}
