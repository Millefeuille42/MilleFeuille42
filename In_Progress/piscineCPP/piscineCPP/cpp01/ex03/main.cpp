//
// Created by millefeuille on 23/03/2021.
//

#include <cstdlib>
#include "ZombieHorde.hpp"

int main () {
	srand(time(NULL));

	ZombieHorde horde = ZombieHorde(8);
	horde.announce();
}