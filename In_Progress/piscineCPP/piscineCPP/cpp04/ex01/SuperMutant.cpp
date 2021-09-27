//
//	Created by millefeuille on 18/5/2021
//

#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
	: Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damages) {
	Enemy::takeDamage(damages - 3);
}