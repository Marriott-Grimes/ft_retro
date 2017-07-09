#ifndef ASTEROID_HPP
# define ASTEROID_HPP

class Asteroid: public Entity
{

public:

	Asteroid(int, int);
	~Asteroid();
	Asteroid(Asteroid const& obj);
	Asteroid&	operator = (Asteroid const& rhs);

	void	update();

private:

};

#endif
