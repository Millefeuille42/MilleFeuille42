//
// Created by Millefeuille on 16/07/2021.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: Form(45, 72, "RobotomyRequestForm", target) {}

RobotomyRequestForm::RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const throw(IFormException) {
	Form::execute(executor);
	std::cout << "*drilling noises* ";
	if ((rand() % 2) + 1 ==  2) {
		std::cout << "The robotomy of " << getTarget() << " failed!" << std::endl;
		return;
	}
	std::cout << "The robotomy of " << getTarget() << " is a success" << std::endl;
}
