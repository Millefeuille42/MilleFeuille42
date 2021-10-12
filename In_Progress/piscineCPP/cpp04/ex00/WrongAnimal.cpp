//
// Created by mlabouri on 9/27/21.
//

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "Default constructor of WrongAnimal called!" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
	std::cout << "Parameter constructor of WrongAnimal called!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor of WrongAnimal called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << "Copy constructor of WrongAnimal called!" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
	std::cout << "Assignment operator of WrongAnimal called!" << std::endl;
	_type = src._type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "*WrongAnimal noises*" << std::endl;
}

const std::string &WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::setType(const std::string &type) {
	_type = type;
}