#include <ncurses.h>
#include <iostream>
#include "Entity.hpp"
#include "ft_retro.hpp"

Entity::Entity(int x, int y = 0)
{
	this->setPos((t_vec2i){x, y});
}

Entity::Entity()
{
	this->setPos((t_vec2i){0, 0});
}

Entity::~Entity()
{

}

Entity::Entity(Entity const& obj)
{
	this->_pos = obj.getPos();
	this->_symbol = obj.getSymbol();
}

Entity&	Entity::operator = (Entity const& rhs)
{
	this->_pos = rhs.getPos();
	this->_symbol = rhs.getSymbol();
	return (*this);
}


t_vec2i		Entity::getPos() const
{
	return (this->_pos);
}

void	Entity::setPos(t_vec2i p)
{
	this->_pos = p;
}

const char*	Entity::getSymbol() const
{
	return (this->_symbol);
}

void	Entity::setSymbol(const char* str)
{
	this->_symbol = str;
}

void	Entity::draw()
{
	t_vec2i p;

	p = this->getPos();
	mvprintw(p.y, p.x, (const char *)this->getSymbol());
}

void	Entity::move(t_vec2i delta)
{
	t_vec2i newPos;
	newPos = this->getPos();
	newPos.x += delta.x;
	newPos.y += delta.y;
	this->setPos(newPos);
}
