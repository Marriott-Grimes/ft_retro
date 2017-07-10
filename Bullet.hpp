#ifndef BULLET_HPP
# define BULLET_HPP
# include "retro.hpp"
# include "Star.hpp"
# include "Entity.hpp"

class Bullet: public Entity {

public:

	Bullet(void);
	~Bullet(void);
	Bullet(Bullet const & obj);
	Bullet & operator=(Bullet const & rhs);

	int		getEnergy(void) const;
	void	setEnergy(int n);
	int		getNum(void) const;
	void	setNum(int n);

	void	recharge();
	void	fire(t_vec2i p);
	void	despawn();
	void	updateIfActive();

protected:

	int _energy;
	// static int _numActive;
private:

};

#endif
