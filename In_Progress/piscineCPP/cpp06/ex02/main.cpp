//
// Created by mlabouri on 11/26/21.
//

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
	std::cout << "Generated ";
	switch (rand() % 3) {
		case 0:
			std::cout << "A, Identified: ";
			return new A;
		case 1:
			std::cout << "B, Identified: ";
			return new B;
		default:
			std::cout << "C, Identified: ";
			return new C;
	}
}

void identify(Base* p) {
	std::string name[3] = {"A", "B", "C"};
	Base *results[3] = {
			dynamic_cast<A*>(p),
			dynamic_cast<B*>(p),
			dynamic_cast<C*>(p),
	};

	for (int i = 0; i < 3; i++) {
		if (results[i]) {
			std::cout << name[i] << std::endl;
			return;
		}
	}
	std::cout << "Invalid" << std::endl;
}

void identify(Base& p) {
	try {
		Base& eval = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		Base& eval = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		Base& eval = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception &e) {}
}

int main() {
	srand(time(NULL));

	std::cout << "--- By Pointer ---" << std::endl;
	for (int i = 0; i < 10; i++) {
		Base* eval = generate();
		identify(eval);
		delete eval;
	}

	std::cout << "--- By Reference ---" << std::endl;
	for (int i = 0; i < 10; i++) {
		Base* eval = generate();
		identify(*eval);
		delete eval;
	}
}