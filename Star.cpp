#include "Star.hpp"
#include <cstdlib>
#include <ctime>

Star::Star(int x)
: Entity(x)
{
	
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

int		Star::getSpeed()
{

}

void	Star::setSpeed(int s)
{

}

void	Star::update()
{

}

void	Star::resetHeight(int xMax)
{
	int x;

	srand(time(NULL));
	x = ;
}
