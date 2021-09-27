//
// Created by Millefeuille on 16/07/2021.
//

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();

	void execute(const Bureaucrat &executor) const throw(IFormException);

private:
	RobotomyRequestForm();
};


#endif //ROBOTOMYREQUESTFORM_HPP
