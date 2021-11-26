//
// Created by mlabouri on 9/27/21.
//

#include "Cat.hpp"

Brain *Cat::getBrain() const {
	return _brain;
}

Cat::Cat(): Animal("Cat") {
	std::cout << "Default constructor of Cat called!" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Copy constructor of Cat called!" << std::endl;
	_brain = new Brain();
	_brain->deepCopy(*src.getBrain());
}

Cat::~Cat() {
	std::cout << "Destructor of Cat called!" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "*Cat noises*" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
	_type = src._type;
	_brain->deepCopy(*src.getBrain());
	return *this;
}
