//
// Created by millefeuille on 30/03/2021.
//

#include <iostream>
#include "Peon.hpp"

Peon::Peon(const std::string &name) : Victim(name) {
	std::cout << "Zog Zog" << std::endl;
}

Peon::Peon(const Peon &src) : Victim(src) {
	std::cout << "Zog Zog" << std::endl;
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const {
	std::cout << _name << " was just polymorphed into a pink pony!" << std::endl;
}
