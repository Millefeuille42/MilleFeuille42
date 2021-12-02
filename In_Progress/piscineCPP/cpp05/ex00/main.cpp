//
// Created by Millefeuille on 02/07/2021.
//

#include "Bureaucrat.hpp"

void	testDecrement() {
	Bureaucrat *dave;
	Bureaucrat *jim;

	std::cout << "Testing decrements:" << std::endl;
	try {
		dave = new Bureaucrat(151, "Dave");
		dave->decrement();
		delete dave;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		jim = new Bureaucrat(150, "Jim");
		jim->decrement();
		delete jim;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
}

void	testIncrement() {
	Bureaucrat *dave;
	Bureaucrat *jim;

	std::cout << "Testing increments:" << std::endl;
	try {
		dave = new Bureaucrat(15, "Dave");
		dave->increment();
		delete dave;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		jim = new Bureaucrat(1, "Jim");
		jim->increment();
		delete jim;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
}

void	testCreation() {
	Bureaucrat *dave;
	Bureaucrat *jim;
	Bureaucrat *bob;
	Bureaucrat *norminet;

	std::cout << "Testing creation:" << std::endl;
	try {
		dave = new Bureaucrat(0, "Dave");
		delete dave;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		jim = new Bureaucrat(15, "Jim");
		delete jim;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		bob = new Bureaucrat(151, "Bob");
		delete bob;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		norminet = new Bureaucrat(150, "Norminet");
		delete norminet;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
}

int	main() {
	testCreation();
	std::cout << "\n";
	testIncrement();
	std::cout << "\n";
	testDecrement();
}
