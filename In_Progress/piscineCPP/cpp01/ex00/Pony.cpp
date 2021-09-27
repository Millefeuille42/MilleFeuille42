//
// Created by millefeuille on 23/03/2021.
//

#include "Pony.hpp"

Pony::Pony() : _age(0), _legs(4), _name("donkey") {
	sayIntro();
}

Pony::Pony(int age, const std::string name) : _age(age), _legs(4), _name(name) {
	sayIntro();
}

Pony::~Pony() {
	std::cout << "And " + _name + " suddenly died" << std::endl;
}

void Pony::sayIntro() const {
	std::cout << "Hello, i'm a ";
	std::cout << _legs;
	std::cout << " legged Pony named " + this->_name + ". I'm ";
	std::cout << this->_age;
}

void ponyOnTheStack(int age, const std::string name) {
	Pony pony(age, name);

	std::cout << " years old. And i'm on the stack" << std::endl;
}

void ponyOnTheHeap(int age, const std::string name) {
	Pony *pony = new Pony(age, name);

	std::cout << " years old. And i'm on the heap" << std::endl;
	delete(pony);
}
