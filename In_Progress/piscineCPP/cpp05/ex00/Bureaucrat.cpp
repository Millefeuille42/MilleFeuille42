//
// Created by Millefeuille on 02/07/2021.
//

#include "Bureaucrat.hpp"
#include "../ex01/Bureaucrat.hpp"


const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(int grade, const std::string &name) throw(IGradeException)
		: _grade(grade), _name(name) {
	std::cout << "Creating " << *this;
	if (_grade < 1)
		throw(GradeTooHighException());
	if (_grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) throw(IGradeException)
		: _grade(src._grade), _name(src._name) {
	if (_grade < 1)
		throw(GradeTooHighException());
	if (_grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::decrement() {
	std::cout << "Decrementing " << *this;
	if (_grade >= 150)
		throw(GradeTooLowException());
	_grade++;
}

void Bureaucrat::increment() {
	std::cout << "Incrementing " << *this;
	if (_grade <= 1)
		throw(GradeTooHighException());
	_grade--;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	_grade = rhs._grade;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName()  << ", bureaucrat of grade "
	   << bureaucrat.getGrade() << std::endl;
	return os;
}
