//
// Created by Millefeuille on 30/06/2021.
//

#include "Character.hpp"

Character::Character() : _materiasCount(0) {
	_materias = materiaInit();
}

Character::Character(const std::string &name)
	: _materias(materiaInit()), _materiasCount(0), _name(name) {}

Character::Character(const Character &src) : _materias(NULL), _materiasCount(0) {
	*this = src;
}

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
	if (!m || _materiasCount >= 4 || hasMateria(m))
		return ;
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {
			_materias[i] = m;
			_materiasCount++;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !_materias[idx])
		return ;
	_materias[idx] = NULL;
}

const std::string &Character::getName() const {
	return _name;
}

bool Character::hasMateria(AMateria *m) {
	for (int i = 0; i < 4; i++)
		if (_materias[i] == m)
			return true;
	return false;
}
