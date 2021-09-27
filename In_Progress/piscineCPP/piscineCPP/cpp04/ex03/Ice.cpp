//
// Created by Millefeuille on 30/06/2021.
//

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &src) : AMateria(src) {}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &rhs) {
	if (this == &rhs)
		std::cout << "ICE They are the same!" << std::endl;
	return *this;
}

AMateria *Ice::clone() const {
	Ice	*ret = new Ice();

	*ret = *this;
	return ret;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " + target.getName() + " *" << std::endl;
	AMateria::use(target);
}
