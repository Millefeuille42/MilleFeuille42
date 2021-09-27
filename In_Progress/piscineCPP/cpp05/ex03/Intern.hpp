//
// Created by Millefeuille on 19/07/2021.
//

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
public:
	Intern();

	Form *makeForm(std::string type, std::string target) const;

	virtual ~Intern();
};


#endif //INTERN_HPP
