//
//	Created by millefeuille on 19/5/2021
//

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() {
	announce();
}

TacticalMarine::TacticalMarine(const TacticalMarine &src) {
	*this = src;
}

TacticalMarine::~TacticalMarine() {
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine &TacticalMarine::operator=(const TacticalMarine &rhs) {
	if (this == &rhs)
		std::cout << "smth" << std::endl;
	this->_name = rhs.getName();
	return *this;
}

void TacticalMarine::announce() const {
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

ISpaceMarine *TacticalMarine::clone() const {
	TacticalMarine *ret = new(TacticalMarine);

	*ret = *this;
	return ret;
}

void TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with a chainsword *" << std::endl;
}

const std::string &TacticalMarine::getName() const {
	return _name;
}
