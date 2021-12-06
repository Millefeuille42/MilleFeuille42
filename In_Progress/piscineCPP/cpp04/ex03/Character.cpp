//
// Created by Millefeuille on 30/06/2021.
//

#include "Character.hpp"

static void materiaClean(AMateria **materias) {
	if (materias)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materias[i]) {
				delete materias[i];
				materias[i] = NULL;
			}
		}
	}
}

static AMateria **materiaInit() {
	AMateria **ret = new AMateria *[4];
	for (int i = 0; i < 4; i++)
	{
		ret[i] = NULL;
	}
	return ret;
}

static AMateria **materiaCopy(AMateria **materias) {
	AMateria **ret = new AMateria *[4];
	for (int i = 0; i < 4; i++) {
		*ret[i] = *materias[i];
	}
	return ret;
}

Character::Character() {}

Character::Character(const std::string &name)
	: _materias(materiaInit()), _materiasCount(0), _name(name) {}

Character::Character(const Character &src)
	: _materias(materiaCopy(src._materias)), _materiasCount(src._materiasCount), _name(src._name) {}

Character::~Character() {
	materiaClean(_materias);
	delete[] _materias;
}

Character &Character::operator=(const Character &rhs) {
	if (this == &rhs)
		std::cout << "They are the same!" << std::endl;
	_name = rhs._name;
	_materiasCount = rhs._materiasCount;
	materiaClean(_materias);
	delete[] _materias;
	_materias = materiaCopy(rhs._materias);
	return *this;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3 || !_materias[idx])
		return ;
	_materias[idx]->use(target);
}

void Character::equip(AMateria *m) {
	if (!m || _materiasCount >= 4)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {
			_materias[i] = m;
			_materiasCount++;
			break ;
		}
	}
	return ;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !_materias[idx])
		return ;
	_materias[idx] = NULL;
}

const std::string &Character::getName() const {
	return _name;
}
