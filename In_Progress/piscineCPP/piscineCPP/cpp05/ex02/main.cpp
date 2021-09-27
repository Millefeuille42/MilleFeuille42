//
// Created by Millefeuille on 02/07/2021.
//

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		jim = new Bureaucrat(1, "Jim");
		jim->increment();
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	delete dave;
	delete jim;
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
	Form *a19;
	Form *d01;
	Form *validForm;

	try {
		a19 = new ShrubberyCreationForm("Empty field");
		delete a19;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		d01 = new PresidentialPardonForm("Norminet");
		delete d01;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		validForm = new RobotomyRequestForm("Moulinette");
		delete validForm;
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
}

void	formTestSign() { //TODO END TESTS
	Bureaucrat	*lvl0Noob;
	Bureaucrat	*lvl100Boss;
	Form	*shrubTest;
	Form	*robotomyTest;

	std::cout << "Testing sign:" << std::endl;
	try {
		shrubTest = new ShrubberyCreationForm("somewhere");
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		robotomyTest = new RobotomyRequestForm("Robominet");
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
		lvl0Noob->signForm(*shrubTest);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		lvl100Boss->signForm(*shrubTest);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		lvl0Noob->signForm(*robotomyTest);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	try {
		lvl100Boss->signForm(*robotomyTest);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	std::cout << "\n";
	std::cout << "Testing exec:" << std::endl;
	try {
		lvl0Noob->executeForm(*shrubTest);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		lvl0Noob->executeForm(*robotomyTest);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		lvl100Boss->executeForm(*shrubTest);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		lvl100Boss->executeForm(*robotomyTest);
	}
	catch (std::exception &e) {
		std::cout << "\tERROR: " << e.what() << std::endl;
	}
	delete lvl0Noob;
	delete lvl100Boss;
	delete shrubTest;
	delete robotomyTest;
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