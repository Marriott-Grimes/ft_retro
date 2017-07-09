/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <akalmyko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:43:52 by akalmyko          #+#    #+#             */
/*   Updated: 2017/07/09 11:52:19 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_HPP
# define ASTEROID_HPP
# include "retro.hpp"

class Asteroid: public Star {

public:

	Asteroid(void);
	~Asteroid(void);
	Asteroid(Asteroid const & obj);
	Asteroid & operator=(Asteroid const & rhs);

protected:

private:

};

#endif
