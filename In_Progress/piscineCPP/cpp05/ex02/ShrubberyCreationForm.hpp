//
// Created by Millefeuille on 15/07/2021.
//

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat &executor) const throw(IFormException);

private:
	ShrubberyCreationForm();
};


#endif //SHRUBBERYCREATIONFORM_HPP
