//
// Created by millefeuille on 23/03/2021.
//

#include "ZombieHorde.hpp"

void ZombieHorde::announce() const {
	for (int i = 0; i < _zombieNumber; i++)
		_zombies[i].announce();
}

ZombieHorde::ZombieHorde() : _zombieNumber(0), _zombies(NULL) {}
ZombieHorde::ZombieHorde(int n) : _zombieNumber(n), _zombies(new Zombie[n]) {}

ZombieHorde::~ZombieHorde() {
	delete[] _zombies;
}


