//
// Created by Millefeuille on 16/07/2021.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: Form(5, 25, "PresidentialPardonForm", target) {}

PresidentialPardonForm::PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const throw(IFormException) {
	Form::execute(executor);
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
