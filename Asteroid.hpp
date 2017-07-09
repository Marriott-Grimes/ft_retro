#ifndef ASTEROID_HPP
# define ASTEROID_HPP

class Asteroid: public Star
{

public:

	Asteroid();
	~Asteroid();
	Asteroid(Asteroid const& obj);
	Asteroid&	operator = (Asteroid const& rhs);

private:
};

#endif
