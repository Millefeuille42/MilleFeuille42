//
// Created by mlabouri on 9/27/21.
//

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "Default constructor of WrongCat called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "Copy constructor of WrongCat called!" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor of WrongCat called!" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "*WrongCat noises*" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
	_type = src._type;
	return *this;
}
