//
// Created by Millefeuille on 02/07/2021.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(int grade, const std::string &name) throw(IGradeException)
		: _grade(grade), _name(name) {
	std::cout << "Creating " << *this << std::endl;
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
	std::cout << "Decrementing " << *this << std::endl;
	if (_grade >= 150)
		throw(GradeTooLowException());
	_grade++;
}

void Bureaucrat::increment() {
	std::cout << "Incrementing " << *this << std::endl;
	if (_grade <= 1)
		throw(GradeTooHighException());
	_grade--;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
	}
	catch (std::exception &e) {
		std::cout << _name << " cannot sign " << form.getName()
		<< " because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signs " << form.getName() << std::endl;
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

void Bureaucrat::executeForm(const Form &form) {
	std::cout << *this << " executes form " << form << std::endl;
	try {
		form.execute(*this);
	} catch (std::exception &e) {
		std::cout << "Error executing the form: " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName()  << ", bureaucrat of grade "
	   << bureaucrat.getGrade();
	return os;
}
