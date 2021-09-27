//
// Created by millefeuille on 30/03/2021.
//

#include <iostream>
#include "Knight.hpp"

Knight::Knight(const std::string &name) : Victim(name) {
	std::cout << "For my Lord !" << std::endl;
}

Knight::Knight(const Knight &src) : Victim(src) {
	std::cout << "For my Lord !" << std::endl;
}

Knight::~Knight() {
	std::cout << "Argh..." << std::endl;
}

void Knight::getPolymorphed() const {
	std::cout << _name << " was just polymorphed into a bunny!" << std::endl;
}