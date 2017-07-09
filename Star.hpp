#ifndef STAR_HPP
# define STAR_HPP

#include "Entity.hpp"

class Star: public Entity
{

public:

	Star(int x, int s);
	~Star();
	Star(Star const& obj);
	Star&	operator = (Star const& rhs);

	int		getSpeed() const;
	void	setSpeed(int s);

	void	update(int xMax, int yMax);
	void	resetHeight(int yMax);

private:

	int	_speed;
};


#endif
