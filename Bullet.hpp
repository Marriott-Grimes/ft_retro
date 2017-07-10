/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:17:56 by mgrimes           #+#    #+#             */
/*   Updated: 2017/07/09 21:17:58 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP
# include "retro.hpp"
# include "Star.hpp"
# include "Entity.hpp"

class Bullet: public Entity {

public:

	Bullet(void);
	virtual	~Bullet(void);
	Bullet(Bullet const & obj);
	Bullet & operator=(Bullet const & rhs);

	int		getEnergy(void) const;
	void	setEnergy(int n);
	int		getNum(void) const;
	void	setNum(int n);

	void	recharge();
	bool	fire(t_vec2i p);
	void	despawn();
	void	updateIfActive();

protected:

	int _energy;
private:

};

#endif
