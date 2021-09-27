//
// Created by millefeuille on 3/23/21.
//

#include <iostream>
#include "Human.hpp"

int	main() {
	Human bob;
	Human bobby("Bobby");

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;

	std::cout << bobby.identify() << std::endl;
	std::cout << bobby.getBrain().identify() << std::endl;
}