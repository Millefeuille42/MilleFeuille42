//
//	Created by millefeuille on 10/6/2021
//

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const AMateria &src) {
	*this = src;
}

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &rhs) {
	if (this == &rhs)
		std::cout << "They are the same!" << std::endl;
	this->_type = rhs._type;
	return *this;
}

const std::string &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}

