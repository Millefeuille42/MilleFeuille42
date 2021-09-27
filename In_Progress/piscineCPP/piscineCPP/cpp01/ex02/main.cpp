//
// Created by millefeuille on 23/03/2021.
//

#include <cstdlib>
#include "ZombieEvent.hpp"

int main () {
	srand(time(NULL));

	ZombieEvent event1;
	ZombieEvent event2;
	Zombie		*zombie1;
	Zombie		*zombie2;
	Zombie		*zombie3;
	Zombie		*zombie4;
	Zombie		zombie5("Teo", "Runner");
	Zombie		zombie6("Carrot", "Runner");

	event1.setZombieType("Crawler");
	event2.setZombieType("Heapster");

	zombie1 = event1.newZombie("Paul");
	zombie2 = event2.newZombie("Eugene");
	zombie3 = event1.randomChump();
	zombie4 = event2.randomChump();

	delete(zombie1);
	delete(zombie2);
	delete(zombie3);
	delete(zombie4);
	zombie5.announce();
}