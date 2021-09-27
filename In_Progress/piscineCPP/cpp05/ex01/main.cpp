//
// Created by Millefeuille on 02/07/2021.
//

#include "Form.hpp"

void	bureauTestDecrement() {
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

void	bureauTestIncrement() {
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

void	bureauTestCreation() {
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

void	formTestCreation() {
	Form *c20;
	Form *b23;
	Form *a19;
	Form *d01;
	Form *validForm;

	std::cout << "Testing creation:" << std::endl;
	try {
		c20 = new Form(0, 134, "c20");
		delete c20;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		b23 = new Form(15, 0, "b23");
		delete b23;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		a19 = new Form(151, 13, "a19");
		delete a19;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		d01 = new Form(149, 151, "d01");
		delete d01;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		validForm = new Form(149, 12, "validForm");
		delete validForm;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
}

void	formTestSign() {
	Bureaucrat	*lvl0Noob;
	Bureaucrat	*lvl100Boss;
	Form	*theNoobForm;
	Form	*theBossForm;

	std::cout << "Testing sign:" << std::endl;
	try {
		theNoobForm = new Form(1, 134, "The Noob Form");
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		theBossForm = new Form(15, 30, "The Boss Form");
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		lvl0Noob = new Bureaucrat(100, "Noob");
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		lvl100Boss = new Bureaucrat(15, "Boss");
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		lvl0Noob->signForm(*theNoobForm);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		lvl100Boss->signForm(*theNoobForm);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		lvl0Noob->signForm(*theBossForm);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		lvl100Boss->signForm(*theBossForm);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	delete lvl0Noob;
	delete lvl100Boss;
	delete theNoobForm;
	delete theBossForm;
}

int	main() {
	bureauTestCreation();
	std::cout << "\n";
	bureauTestIncrement();
	std::cout << "\n";
	bureauTestDecrement();
	std::cout << "\n";
	formTestCreation();
	std::cout << "\n";
	formTestSign();
}