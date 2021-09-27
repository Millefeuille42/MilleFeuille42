//
// Created by millefeuille on 3/23/21.
//

#include <iostream>
#include "HumanB.hpp"

void HumanB::attack() const {
	std::cout << _name + " attacks with his " + _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

Weapon *HumanB::getWeapon() {
	return _weapon;
}

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::HumanB() : _name("Bob") {}

HumanB::HumanB(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon) {}
