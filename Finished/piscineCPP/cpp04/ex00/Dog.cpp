//
// Created by mlabouri on 9/27/21.
//

#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Default constructor of Dog called!" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Copy constructor of Dog called!" << std::endl;
}

Dog::~Dog() {
	std::cout << "Destructor of Dog called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "*Dog noises*" << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
	_type = src._type;
	return *this;
}
