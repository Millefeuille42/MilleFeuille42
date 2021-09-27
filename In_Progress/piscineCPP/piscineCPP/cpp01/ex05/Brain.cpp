//
// Created by millefeuille on 3/23/21.
//

#include <sstream>
#include "Brain.hpp"

std::string Brain::identify() const {
	std::stringstream ss;

	ss << &*this;
	return ss.str();
}

Brain::Brain() {}
