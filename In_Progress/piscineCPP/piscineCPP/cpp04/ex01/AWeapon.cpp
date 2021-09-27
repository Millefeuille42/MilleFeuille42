//
//	Created by millefeuille on 18/5/2021
//

#include "AWeapon.hpp"


AWeapon::AWeapon() {}

AWeapon::AWeapon(const AWeapon &src) {
	*this = src;
}

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
	: _name(name), _apCost(apcost), _damage(damage) {}

AWeapon::~AWeapon() {}

AWeapon &AWeapon::operator=(const AWeapon &rhs) {
	if (this == &rhs)
		return *this;
	_name = rhs.getName();
	_apCost = rhs._apCost;
	_damage = rhs._damage;
	return *this;
}

std::string AWeapon::getName() const {
	return _name;
}

int AWeapon::getAPCost() const {
	return _apCost;
}

int AWeapon::getDamage() const {
	return _damage;
}
