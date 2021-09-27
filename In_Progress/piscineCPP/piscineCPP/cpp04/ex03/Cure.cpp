//
// Created by Millefeuille on 30/06/2021.
//

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const AMateria &src) : AMateria(src) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &rhs) {
	if (this == &rhs)
		std::cout << "CURE They are the same!" << std::endl;
	return *this;
}

AMateria *Cure::clone() const {
	Cure	*ret = new Cure();

	*ret = *this;
	return ret;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " + target.getName() + "’s wounds *" << std::endl;
	AMateria::use(target);
}
