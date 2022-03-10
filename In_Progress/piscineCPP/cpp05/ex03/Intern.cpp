//
// Created by Millefeuille on 19/07/2021.
//

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

static Form *makeShrubberyCreationForm(std::string const & target) {
	return new ShrubberyCreationForm(target);
}

static Form *makePresidentialPardonForm(std::string const & target) {
	return new PresidentialPardonForm(target);
}

static Form *makeRobotomyRequestForm(std::string const & target) {
	return new RobotomyRequestForm(target);
}

Form *Intern::makeForm(std::string type, std::string target) const {
	static std::string types[] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
	};
	static Form *(*actions[])(std::string const & target) = {
			makeShrubberyCreationForm,
			makeRobotomyRequestForm,
			makePresidentialPardonForm
	};

	for (int i = 0; i < (int)types->size(); i++)
	{
		if (type == types[i])
		{
			std::cout << "Intern creates " << type << std::endl;
			return actions[i](target);
		}
	}
	std::cout << "Intern is confused, " + type + " forms does not exists..." << std::endl;
	return NULL;
}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern &Intern::operator=(const Intern &rhs) {
	return *this;
}
