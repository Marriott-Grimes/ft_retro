/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <akalmyko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:51:42 by akalmyko          #+#    #+#             */
/*   Updated: 2017/07/09 11:52:22 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

/* constructors/desctructors/copier */

Entity::Entity(void)
{
	this->setPos((t_vec2i){5, 5});
	this->Entity::setScreenSize((t_vec2i){XMAX, YMAX});
	return ;
}

Entity::~Entity(void)
{
	return ;
}

Entity::Entity(int x, int y = 0)
{
	this->setPos((t_vec2i){x, y});
	return ;
}

Entity::Entity(Entity const & obj)
{
	*this = obj;
	return ;
}

Entity & Entity::operator=(Entity const & rhs)
{
	this->_pos = rhs.getPos();
	this->_symbol = rhs.getSymbol();
	return (*this);
}

/* member methods */

t_vec2i		Entity::getPos(void) const
{
	return (this->_pos);
}

void	Entity::setPos(t_vec2i p)
{
	this->_pos = p;
	return ;
}

const char*	Entity::getSymbol(void) const
{
	return (this->_symbol);
}

void	Entity::setSymbol(const char *str)
{
	this->_symbol = str;
	return ;
}

t_vec2i		Entity::getScreenSize(void) const
{
	return (this->_screenSize);
}

void		Entity::setScreenSize(t_vec2i xyMax)
{
	this->_screenSize = xyMax;
	return ;
}

void	Entity::draw()
{
	t_vec2i p;

	p = this->getPos();
	mvprintw(p.y, p.x, (const char *)this->getSymbol());
	return ;
}

void	Entity::move(t_vec2i delta)
{
	t_vec2i		newPos;

	newPos = this->getPos();
	newPos.x += delta.x;
	newPos.y += delta.y;
	if (newPos.x >= 0 && newPos.x <= this->getScreenSize().x
		&& newPos.y <= this->getScreenSize().y)
		this->setPos(newPos);
	return ;
}

bool	Entity::collision(t_vec2i p)
{
	if (p.x == this->getPos().x && p.y == this->getPos().y)
		return (true);
	return (false);
}