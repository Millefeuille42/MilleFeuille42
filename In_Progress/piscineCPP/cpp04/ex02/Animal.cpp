//
// Created by mlabouri on 9/27/21.
//

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Default constructor of Animal called!" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
	std::cout << "Parameter constructor of Animal called!" << std::endl;
}

Animal::~Animal() {
	std::cout << "Destructor of Animal called!" << std::endl;
}

Animal::Animal(const Animal &src) {
	std::cout << "Copy constructor of Animal called!" << std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &src) {
	std::cout << "Assignment operator of Animal called!" << std::endl;
	_type = src._type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "*Animal noises*" << std::endl;
}

const std::string &Animal::getType() const {
	return _type;
}

void Animal::setType(const std::string &type) {
	_type = type;
}
