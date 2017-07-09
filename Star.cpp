#include "Star.hpp"
#include <cstdlib>

Star::Star(int x, int s)
: Entity(x)
{
	this->setSpeed(s);
}

Star::~Star()
{

}

Star::Star(Star const& obj)
{
	this->_pos = obj.getPos();
	this->_symbol = obj.getSymbol();
	this->_speed = obj.getSpeed();
}

Star&	Star::operator = (Star const& rhs)
{
	this->_pos = rhs.getPos();
	this->_symbol = rhs.getSymbol();
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
	this->move(t_vec2i{0, this->getSpeed()});
	if (this->getPos().y > yMax)
		this->resetHeight(xMax);
}

void	Star::resetHeight(int xMax)
{
	int x;

	x = rand() % xMax;
	this->setPos
}
