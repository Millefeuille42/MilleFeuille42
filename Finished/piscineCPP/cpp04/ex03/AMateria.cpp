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

void materiaClean(AMateria **materias) {
	if (materias) {
		for (int i = 0; i < 4; i++) {
			if (materias[i]) {
				delete materias[i];
				materias[i] = NULL;
			}
		}
	}
}

AMateria **materiaInit() {
	AMateria **ret = new AMateria *[4];
	for (int i = 0; i < 4; i++)
		ret[i] = NULL;
	return ret;
}

AMateria **materiaCopy(AMateria **materias) {
	AMateria **ret = new AMateria *[4];
	if (!materias)
		return NULL;
	for (int i = 0; i < 4; i++) {
		if (!materias[i]) {
			ret[i] = NULL;
			continue ;
		}
		ret[i] = materias[i]->clone();
	}
	return ret;
}
