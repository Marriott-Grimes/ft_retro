#ifndef STAR_HPP
# define STAR_HPP

class Star: public Entity
{

public:

	Star(int, int);
	~Star();
	Star(Star const& obj);
	Star&	operator = (Star const& rhs);

	void	update();
	void	resetHeight();

private:

	int	_speed;
};


#endif
