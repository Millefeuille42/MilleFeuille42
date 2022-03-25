//
// Created by Millefeuille on 15/07/2021.
//

#include "ShrubberyCreationForm.hpp"

const std::string tree = "      /\\      \n"
						 "     /\\*\\     \n"
						 "    /\\O\\*\\    \n"
						 "   /*/\\/\\/\\   \n"
						 "  /\\O\\/\\*\\/\\  \n"
						 " /\\*\\/\\*\\/\\/\\ \n"
						 "/\\O\\/\\/*/\\/O/\\\n"
						 "      ||      \n"
						 "      ||      \n"
						 "      ||      ";

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form(137, 145, "ShrubberyCreationForm", target) {}

ShrubberyCreationForm::ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const throw(IFormException) {
	Form::execute(executor);
	std::string filename = std::string(std::string(getTarget() + "_shrubbery"));
	std::ofstream newFile(filename.c_str());
	newFile << tree << std::endl;
	newFile.close();
	std::cout << "Shrubbery Creation complete!" << std::endl;
}
