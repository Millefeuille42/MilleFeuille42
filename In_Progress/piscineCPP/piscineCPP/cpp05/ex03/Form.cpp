//
// Created by Millefeuille on 02/07/2021.
//

#include "Form.hpp"

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char *Form::AlreadySignedException::what() const throw() {
	return "Form already signed!";
}

const char *Form::NotSignedException::what() const throw() {
	return "Form not signed!";
}

Form::Form() : _execGrade(0), _signGrade(0) {}

Form::Form(const int execGrade, const int signGrade, const std::string &name,
		const std::string &target) throw(IFormException)
		: _signed(false), _execGrade(execGrade), _signGrade(signGrade), _name(name), _target(target) {
	std::cout << "Created " << *this << std::endl;
	if (_execGrade > 150 || _signGrade > 150) {
		throw(GradeTooLowException());
	}
	if (_execGrade < 1 || _signGrade < 1) {
		throw(GradeTooHighException());
	}
}

Form::Form(const Form &src) throw(IFormException)
	: _signed(src._signed), _execGrade(src._execGrade), _signGrade(src._signGrade), _name(src._name) {
	std::cout << "Created " << *this << std::endl;
	if (_execGrade > 150 || _signGrade > 150) {
		throw(GradeTooLowException());
	}
	if (_execGrade < 1 || _signGrade < 1) {
		throw(GradeTooHighException());
	}
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat &bureaucrat) throw(IFormException) {
	if (bureaucrat.getGrade() > _signGrade)
		throw (GradeTooLowException());
	if (_signed)
		throw (AlreadySignedException());
	_signed = true;
}

bool Form::isSigned() const {
	return _signed;
}

int Form::getExecGrade() const {
	return _execGrade;
}

int Form::getSignGrade() const {
	return _signGrade;
}

const std::string &Form::getName() const {
	return _name;
}

const std::string &Form::getTarget() const {
	return _target;
}

Form &Form::operator=(const Form &rhs) {
	_signed = rhs._signed;
	return *this;
}

void Form::execute(const Bureaucrat &executor) const throw(IFormException) {
	if (executor.getGrade() > _execGrade)
		throw (GradeTooLowException());
	if (!_signed)
		throw (NotSignedException());
	std::cout << *this << " is being executed" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	std::string	formStatus = "false";

	if (form.isSigned())
		formStatus = "True";
	os << "Form " << form.getName() << "_"
	<< form.getTarget() << ", signed: " << formStatus
	<< ". Sign grade: " << form.getSignGrade()
	<< ", execution grade: " << form.getExecGrade();
	return os;
}
