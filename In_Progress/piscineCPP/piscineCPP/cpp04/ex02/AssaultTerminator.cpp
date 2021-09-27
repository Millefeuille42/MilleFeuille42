//
//	Created by millefeuille on 19/5/2021
//

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator() {
	announce();
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &src) {
	*this = src;
}

AssaultTerminator::~AssaultTerminator() {
	std::cout <<  "I’ll be back..." << std::endl;
}

AssaultTerminator &AssaultTerminator::operator=(const AssaultTerminator &rhs) {
	if (this == &rhs)
		std::cout << "smth" << std::endl;
	this->_name = rhs.getName();
	return *this;
}

void AssaultTerminator::announce() const {
	std::cout << "* teleports from space *" << std::endl;
}

//	TODO	fix operator=

ISpaceMarine *AssaultTerminator::clone() const {
	AssaultTerminator *ret = new(AssaultTerminator);

	*ret = *this;
	return ret;
}

void AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

const std::string &AssaultTerminator::getName() const {
	return _name;
}
