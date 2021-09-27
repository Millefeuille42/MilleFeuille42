//
// Created by millefeuille on 19/05/2021.
//

#include "Squad.hpp"

Squad::Squad() : _count(0), _marines(new ISpaceMarine *[0]) {}

Squad::Squad(const Squad &src)
		: _count(src.getCount()), _marines(src.deepCopy()) {}

Squad::~Squad() { cleanSquad(); }

Squad &Squad::operator=(const Squad &rhs) {
	if (this == &rhs)
		return *this;
	cleanSquad();
	_count = rhs.getCount();
	_marines = rhs.deepCopy();
	return *this;
}

ISpaceMarine **Squad::deepCopy() const {
	if (_marines == NULL)
		return NULL;

	ISpaceMarine **ret = new ISpaceMarine *[_count];
	for (int index = 0; index < _count; index++) {
		ret[index] = _marines[index]->clone();
	}
	return ret;
}

void Squad::cleanSquad() {
	for (int index = 0; index < _count; index++) {
		delete _marines[index];
	}
	delete[] _marines;
	_marines = NULL;
	_count = 0;
}

bool Squad::isValid(ISpaceMarine* marine) const {
	if (marine == NULL)
		return false;
	for (int index = 0; index < _count; index++) {
		if (marine == _marines[index])
			return false;
	}
	return true;
}

int Squad::getCount() const {
	return _count;
}

ISpaceMarine *Squad::getUnit(int index) const {
	if (index >= _count)
		return NULL;
	return _marines[index];
}

int Squad::push(ISpaceMarine* marine) {
	if (!isValid(marine))
		return _count;
	ISpaceMarine **ret = new ISpaceMarine *[++_count];
	for (int index = 0; index < _count - 1; index++) {
		ret[index] = _marines[index];
	}
	ret[_count - 1] = marine;
	delete[](_marines);
	_marines = ret;
	return _count;
}
