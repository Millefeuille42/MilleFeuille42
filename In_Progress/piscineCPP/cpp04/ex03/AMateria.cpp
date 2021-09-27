//
//	Created by millefeuille on 10/6/2021
//

#include "AMateria.hpp"

AMateria::AMateria() : _xp(0) {}

AMateria::AMateria(const AMateria &src) {
	*this = src;
}

AMateria::AMateria(const std::string &type) : _xp(0), _type(type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &rhs) {
	if (this == &rhs)
		std::cout << "They are the same!" << std::endl;
	this->_xp = rhs._xp;
	this->_type = rhs._type;
	return *this;
}

unsigned int AMateria::getXp() const {
	return _xp;
}

const std::string &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	_xp += 10;
	(void)target;
}

