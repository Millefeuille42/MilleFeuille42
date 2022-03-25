//
// Created by millefeuille on 23/03/2021.
//

#include "Zombie.hpp"

std::string colors[3] = {"Red", "Green", "Blue"};
std::string names[5] = {"Bobby", "Potato", "Johnny", "Bob", "Norminet"};

void Zombie::announce() const {
	std::cout << "<" + _color + " " + _name + "(" + _type + ")> Braiiiiiiinnnssss ..." << std::endl;
}

Zombie::Zombie() : _color(colors[rand() % 3]), _name(names[rand() % 5]), _type("Default") {
	std::cout << this->_name + " Created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << " has been defeated!" << std::endl;
}
