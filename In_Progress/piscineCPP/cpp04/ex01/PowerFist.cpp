//
//	Created by millefeuille on 18/5/2021
//

#include "PowerFist.hpp"

PowerFist::PowerFist()
	: AWeapon("Power Fist", 8, 50) {}

PowerFist::~PowerFist() {}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
