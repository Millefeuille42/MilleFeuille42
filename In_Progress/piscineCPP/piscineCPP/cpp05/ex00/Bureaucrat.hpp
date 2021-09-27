//
// Created by Millefeuille on 02/07/2021.
//

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat {
public:
	class IGradeException : public std::exception {
	public:
		virtual const char *what() const throw() = 0;
	};
	class GradeTooHighException : public IGradeException {
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public IGradeException {
		const char *what() const throw();
	};

	Bureaucrat(int grade, const std::string &name) throw(IGradeException);
	Bureaucrat(const Bureaucrat &src) throw(IGradeException);

	~Bureaucrat();

	void increment();
	void decrement();

	Bureaucrat &operator=(const Bureaucrat &rhs);

	int getGrade() const;
	const std::string &getName() const;

private:
	int _grade;
	const std::string	_name;
	Bureaucrat();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif //BUREAUCRAT_HPP
