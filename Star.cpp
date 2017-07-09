#include "Star.hpp"
#include "Entity.hpp"
#include <cstdlib>

Star::Star(int x, int s)
: Entity(x, 0)
{
	this->setSpeed(s);
}

Star::~Star()
{

}

Star::Star(Star const& obj)
{
	this->Entity::setPos(obj.Entity::getPos());
	this->Entity::setSymbol(obj.Entity::getSymbol());
	this->_speed = obj.getSpeed();
}

Star&	Star::operator = (Star const& rhs)
{
	this->Entity::setPos(rhs.Entity::getPos());
	this->Entity::setSymbol(rhs.Entity::getSymbol());
	this->_speed = rhs.getSpeed();
	return (*this);
}

int		Star::getSpeed() const
{
	return (this->_speed);
}

void	Star::setSpeed(int s)
{
	this->_speed = s;
}

void	Star::update(int xMax, int yMax)
{
	this->Entity::move((t_vec2i){0, this->getSpeed()});
	if (this->Entity::getPos().y > yMax)
		this->resetHeight(xMax);
}

void	Star::resetHeight(int xMax)
{
	int x;

	x = rand() % xMax;
	this->Entity::setPos((t_vec2i){x, 0});
}
