//
// Created by Millefeuille on 02/07/2021.
//

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>
# include <iostream>

# include "Bureaucrat.hpp"

class Form {
public:
	class IFormException : public std::exception {
	public:
		virtual const char *what() const throw() = 0;
	};
	class GradeTooHighException : public IFormException {
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public IFormException {
	public:
		const char *what() const throw();
	};
	class AlreadySignedException : public IFormException {
	public:
		const char *what() const throw();
	};
	class NotSignedException : public IFormException {
	public:
		const char *what() const throw();
	};


	Form(const int execGrade, const int signGrade, const std::string &name, const std::string &target) throw(IFormException);
	Form(const Form &src) throw(IFormException);

	virtual ~Form();

	void	beSigned(const Bureaucrat &bureaucrat) throw(IFormException);
	virtual void	execute(const Bureaucrat &executor) const throw(IFormException) ;

	Form &operator=(const Form &rhs);

	bool isSigned() const;
	int getExecGrade() const;
	int getSignGrade() const;

	const std::string &getTarget() const;

	const std::string &getName() const;

private:

	bool _signed;
	const int	_execGrade;
	const int	_signGrade;
	const std::string	_name;
	const std::string	_target;
protected:
	Form();
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //FORM_HPP
