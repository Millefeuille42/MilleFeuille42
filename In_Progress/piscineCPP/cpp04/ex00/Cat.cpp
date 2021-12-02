//
// Created by mlabouri on 9/27/21.
//

#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	std::cout << "Default constructor of Cat called!" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Copy constructor of Cat called!" << std::endl;
}

Cat::~Cat() {
	std::cout << "Destructor of Cat called!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "*Cat noises*" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
	_type = src._type;
	return *this;
}
