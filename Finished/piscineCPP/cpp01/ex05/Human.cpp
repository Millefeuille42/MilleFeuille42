//
// Created by millefeuille on 3/23/21.
//

#include "Human.hpp"

std::string Human::identify() const {
	return _brain.identify();
}

Brain const &Human::getBrain() const {
	return _brain;
}

Human::Human() : _brain(Brain()), _name("Bob") {}

Human::Human(std::string name) : _brain(Brain()), _name(name) {}
