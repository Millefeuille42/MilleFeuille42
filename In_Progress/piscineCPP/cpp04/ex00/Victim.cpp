//
// Created by millefeuille on 30/03/2021.
//

#include <iostream>
#include "Victim.hpp"

Victim::Victim() {}

Victim::Victim(const std::string &name) : _name(name) {
	std::cout << "A random victim called " + _name + " just appeared!" << std::endl;
}

Victim::Victim(const Victim &src) : _name(src._name) {
	std::cout << "A random victim called " + _name + " just appeared!" << std::endl;
}

Victim &Victim::operator=(const Victim &rhs) {
	_name = rhs._name;
	return *this;
}

Victim::~Victim() {
	std::cout << "Victim " + _name + " died for no apparent reasons!" << std::endl;
}

std::string Victim::getName() const {
	return _name;
}

void Victim::getPolymorphed() const {
	std::cout << _name << " was just polymorphed in a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, Victim const & rhs) {
	return stream << "I'm " + rhs.getName() + " and I like otters!" << std::endl;
}
