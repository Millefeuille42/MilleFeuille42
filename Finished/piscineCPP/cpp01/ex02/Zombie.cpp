//
// Created by millefeuille on 23/03/2021.
//

#include "Zombie.hpp"

std::string colors[3] = {"Red", "Green", "Blue"};

void Zombie::announce() const {
	std::cout << "<" + _color + " " + _name + "(" + _type + ")> Braiiiiiiinnnssss ..." << std::endl;
}

Zombie::Zombie() : _color(colors[rand() % 3]), _name("Bob"), _type("Default") {
	std::cout << "Bob Created" << std::endl;
}

Zombie::Zombie(const std::string name, const std::string type) : _color(colors[rand() % 3]), _name(name), _type(type) {
	std::cout << this->_name + " Created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << " has been defeated!" << std::endl;
}
