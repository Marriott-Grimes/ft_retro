#ifndef STAR_HPP
# define STAR_HPP

class Star: public Entity
{

public:

	Star(int);
	~Star();
	Star(Star const& obj);
	Star&	operator = (Star const& rhs);

	int		getSpeed() const;
	void	setSpeed(int s);

	void	update();
	void	resetHeight(int yMax);

private:

	int	_speed;
};


#endif
