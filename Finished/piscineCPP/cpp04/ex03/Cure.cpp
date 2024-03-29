//
// Created by Millefeuille on 30/06/2021.
//

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &src) : AMateria(src) {}

Cure::~Cure() {}

AMateria *Cure::clone() const {
	Cure	*ret = new Cure();

	*ret = *this;
	return ret;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " + target.getName() + "’s wounds *" << std::endl;
	AMateria::use(target);
}

Cure &Cure::operator=(const Cure &rhs) {
	_type = rhs.getType();
	return *this;
}
