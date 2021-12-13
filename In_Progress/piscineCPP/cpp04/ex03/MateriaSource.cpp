//
// Created by Millefeuille on 01/07/2021.
//

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
		: _materias(materiaInit()), _materiasCount(0) {}

MateriaSource::MateriaSource(const MateriaSource &src)
		: _materias(materiaCopy(src._materias)), _materiasCount(src._materiasCount) {}

MateriaSource::~MateriaSource() {
	materiaClean(_materias);
	delete[] _materias;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	if (this == &rhs)
		std::cout << "SOURCE They are the same!" << std::endl;
	_materiasCount = rhs._materiasCount;
	materiaClean(_materias);
	delete[] _materias;
	_materias = materiaCopy(rhs._materias);
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (!materia || _materiasCount >= 4)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {
			_materias[i] = materia;
			_materiasCount++;
			break ;
		}
	}
	return ;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < _materiasCount; i++) {
		if (_materias[i] && _materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	return NULL;
}
