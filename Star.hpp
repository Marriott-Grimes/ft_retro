/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <akalmyko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:49:42 by akalmyko          #+#    #+#             */
/*   Updated: 2017/07/09 11:52:39 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_HPP
# define STAR_HPP
# include "retro.hpp"
# include "Entity.hpp"
# include <cstdlib>

class Star : public Entity {

public:

	Star(void);
	~Star(void);
	Star(int x, int s);
	Star(Star const & obj);
	Star	&operator=(Star const & rhs);

	int		getSpeed(void) const;
	void	setSpeed(int s);
	void	update(int xMax, int yMax);
	void	resetHeight(int yMax);

protected:

private:

	int		_speed;

};

#endif
