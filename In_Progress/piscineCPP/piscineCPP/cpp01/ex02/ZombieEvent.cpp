//
// Created by millefeuille on 23/03/2021.
//

#include "ZombieEvent.hpp"

std::string names[3] = {"Bobby", "Potato", "Johnny"};

void ZombieEvent::setZombieType(std::string type) {
	this->_type = type;
}

Zombie *ZombieEvent::newZombie(std::string name) {
	return new Zombie(name, _type);
}

Zombie *ZombieEvent::randomChump() {
	Zombie	*zombie = newZombie(names[rand() % 3]);

	zombie->announce();
	return zombie;
}
