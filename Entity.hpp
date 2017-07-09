#ifndef ENTITY_HPP
# define ENTITY_HPP

#include "ft_retro.hpp"
#include <iostream>
#include <ncurses.h>

class Entity
{

public:
	Entity(void);
	Entity(int x, int y);
	~Entity();
	Entity(Entity const& obj);
	Entity&	operator = (Entity const& rhs);

	t_vec2i	getPos() const;
	void	setPos(t_vec2i pos);
	const char*	getSymbol() const;
	void	setSymbol(const char* pos);

	void	draw();
	void	move(t_vec2i delta);

protected:

	t_vec2i		_pos;
	const char*	_symbol;
	// int			_color;
};


#endif
