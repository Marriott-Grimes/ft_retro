#include "Bullet.hpp"
# include "Entity.hpp"
# include <ncurses.h>

Bullet::Bullet() {
	this->Entity::setSymbol("*");
	this->Entity::setPos((t_vec2i){1000, 1000});
	this->Entity::setScreenSize((t_vec2i){XMAX, YMAX});
	return ;
}

Bullet::~Bullet(void) {
	return ;
}

Bullet::Bullet(Bullet const & obj)
{
	*this = obj;
	return ;
}

Bullet&	Bullet::operator=(Bullet const & rhs)
{
	this->Entity::setPos(rhs.Entity::getPos());
	this->Entity::setSymbol(rhs.Entity::getSymbol());
	this->Entity::setScreenSize(rhs.Entity::getScreenSize());
	return (*this);
}

int		Bullet::getEnergy(void) const
{
	return (this->_energy);
}

void	Bullet::setEnergy(int n)
{
	this->_energy = n;
}

void	Bullet::recharge()
{
	int n;

	n = this->Bullet::getEnergy();
	if (n < 100)
		this->Bullet::setEnergy(n + 1);
}

void	Bullet::fire(t_vec2i playerPos)
{
	if (this->getEnergy() == 100 && this->Entity::getPos().x == 1000)
	{
		playerPos.y--;
		this->Entity::setPos(playerPos);
	}
	// this->_numActive++;
}

void	Bullet::despawn()
{
	this->Entity::setPos((t_vec2i){1000, 1000});
	// this->_numActive--;
}

void	Bullet::updateIfActive()
{
	t_vec2i p;

	p = this->Entity::getPos();
	if (p.x != 1000)
	{
		p.y--;
		this->Entity::setPos(p);
		if (this->Entity::getPos().y >= 0)
			this->Entity::draw();
		else
			this->despawn();
	}
}
