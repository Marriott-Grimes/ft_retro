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

Star::Star(void) {
	return ;
}

Star::~Star(void) {
	return ;
}

Star::Star(int x, int s) : Entity(x, 0)
{
	this->setSpeed(s);
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

void	Star::update(int xMax, int yMax)
{
	this->Entity::move((t_vec2i){0, this->getSpeed()});
	if (this->Entity::getPos().y > yMax)
		this->resetHeight(xMax);
	return ;
}

void	Star::resetHeight(int xMax)
{
	int x;

	x = rand() % xMax;
	this->Entity::setPos((t_vec2i){x, 0});
	return ;
}
