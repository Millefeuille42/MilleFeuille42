//
// Created by mlabouri on 9/27/21.
//

#include "Dog.hpp"

Brain *Dog::getBrain() const {
	return _brain;
}

Dog::Dog(): Animal("Dog") {
	std::cout << "Default constructor of Dog called!" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Copy constructor of Dog called!" << std::endl;
	_brain = new Brain();
	_brain->deepCopy(*src.getBrain());
}

Dog::~Dog() {
	std::cout << "Destructor of Dog called!" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "*Dog noises*" << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
	_type = src._type;
	_brain->deepCopy(*src.getBrain());
	return *this;
}
