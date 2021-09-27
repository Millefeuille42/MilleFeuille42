//
// Created by millefeuille on 3/23/21.
//

#include "Weapon.hpp"

std::string const &Weapon::getType() const {
	return _type;
}

void Weapon::setType(std::string type) {
	_type = type;
}

Weapon::Weapon() : _type("Sword") {}

Weapon::Weapon(std::string type) : _type(type) {

}


