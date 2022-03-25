//
// Created by Millefeuille on 16/07/2021.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();

	void execute(const Bureaucrat &executor) const throw(IFormException);

private:
	PresidentialPardonForm();
};


#endif //PRESIDENTIALPARDONFORM_HPP
