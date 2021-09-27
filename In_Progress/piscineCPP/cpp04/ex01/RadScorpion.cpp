//
// Created by millefeuille on 18/05/2021.
//

#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
		: Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *" << std::endl;
}