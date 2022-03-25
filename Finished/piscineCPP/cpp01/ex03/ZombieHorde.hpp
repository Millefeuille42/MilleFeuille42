//
// Created by millefeuille on 23/03/2021.
//

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {
	public:
		ZombieHorde(int n);
		~ZombieHorde();
		void	announce() const ;
	private:
		ZombieHorde();

		int	_zombieNumber;
		Zombie	*_zombies;
};


#endif //ZOMBIEHORDE_HPP
