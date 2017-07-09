/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <akalmyko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:51:28 by akalmyko          #+#    #+#             */
/*   Updated: 2017/07/09 11:52:25 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP
# include "retro.hpp"
# include <ncurses.h>

class Entity {

public:
	Entity(void);
	~Entity(void);
	Entity(int x, int y);
	Entity(Entity const & obj);
	Entity 		&operator=(Entity const & rhs);

	t_vec2i		getPos(void) const;
	void		setPos(t_vec2i pos);
	const char	*getSymbol() const;
	void		setSymbol(const char* pos);

	void		draw(void);
	void		move(t_vec2i delta);

protected:

	t_vec2i		_pos;
	const char*	_symbol;
	// int			_color;

private:

};


#endif
