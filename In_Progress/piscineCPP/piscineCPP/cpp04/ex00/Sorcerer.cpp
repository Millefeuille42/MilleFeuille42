//
// Created by millefeuille on 30/03/2021.
//

#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {}

Sorcerer::Sorcerer(const std::string & name, const std::string & title) : _name(name), _title(title) {
	std::cout << _name + ", " + _title +  ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &src) : _name(src._name), _title(src._title) {
	std::cout << _name + ", " + _title +  ", is born!" << std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &rhs) {
	_name = rhs._name;
	_title = rhs._title;
	return *this;
}

Sorcerer::~Sorcerer() {
	std::cout << _name + ", " + _title +  ", is dead."
	+ " Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getName() const {
	return _name;
}

std::string Sorcerer::getTitle() const {
	return _title;
}

void Sorcerer::polymorph(const Victim & target) const {
	target.getPolymorphed();
}

void Sorcerer::polymorph(const Peon &target) const {
	target.getPolymorphed();
}

void Sorcerer::polymorph(const Knight &target) const {
	target.getPolymorphed();
}

std::ostream &operator<<(std::ostream & stream, Sorcerer const & rhs) {
	return stream << "I am " + rhs.getName() + ", " + rhs.getTitle()
	+ ", and I like ponies!" << std::endl;
}
