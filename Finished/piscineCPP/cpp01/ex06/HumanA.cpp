//
// Created by millefeuille on 3/23/21.
//

#include <iostream>
#include "HumanA.hpp"

void HumanA::attack() const {
	std::cout << _name + " attacks with his " + _weapon->getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

Weapon *HumanA::getWeapon() {
	return _weapon;
}

HumanA::HumanA(std::string name) : _name(name) {}

HumanA::HumanA() : _name("Bob") {}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon) {}
