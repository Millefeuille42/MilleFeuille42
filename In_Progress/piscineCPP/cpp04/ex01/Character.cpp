//
//	Created by millefeuille on 18/5/2021
//

#include "Character.hpp"

Character::Character() {}

Character::Character(const Character &src) {
	*this = src;
}

Character::Character(const std::string & name)
	: _name(name), _ap(40), _weapon(NULL) {}


Character::~Character() {}

Character &Character::operator=(const Character &rhs) {
	if (this == &rhs)
		return *this;
	_name = rhs.getName();
	_ap = rhs.getAP();
	_weapon = rhs.getWeapon();
	return *this;
}

std::string Character::getName() const {
	return _name;
}

int Character::getAP() const {
	return _ap;
}

AWeapon *Character::getWeapon() const {
	return _weapon;
}

void Character::recoverAP() {
	if (_ap + 10 > 40) {
		std::cout << _name + " can't recover more AP!" << std::endl;
		return;
	}
	_ap += 10;
	std::cout << _name + " recovered 10 AP!" << std::endl;
}

void Character::equip(AWeapon *weapon) {
	_weapon = weapon;
}

void Character::attack(Enemy *enemy) {
	if (_weapon == NULL) {
		std::cout << _name + " has no weapon!" << std::endl;
		return ;
	}
	if (enemy == NULL) {
		std::cout << _name + " has no target!" << std::endl;
		return ;
	}
	if (_weapon->getAPCost() > _ap) {
		std::cout << _name + " is out of AP!" << std::endl;
		return ;
	}


	_ap -= _weapon->getAPCost();
	std::cout << _name + " attacks " + enemy->getType() + " with a " + _weapon->getName() << std::endl;
	_weapon->attack();
	enemy->takeDamage(_weapon->getDamage());
}

std::ostream &operator<<(std::ostream &stream, Character const &c) {
	if (c.getWeapon() == NULL)
		return stream << c.getName() + " has " << c.getAP() << " AP and is unarmed" << std::endl;
	return stream << c.getName() + " has " << c.getAP() << " AP and wields a " + c.getWeapon()->getName() << std::endl;
}