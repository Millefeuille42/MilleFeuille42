//
// Created by mlabouri on 11/22/21.
//

#include "convert.hpp"

void dispNl() {
	std::cout << std::endl;
}

void dispInvalid(){
	std::cout << "invalid";
}

void display(std::string const & arg, char val, long buffer, bool fail) {
	(void) arg;
	std::cout << "char: ";
	if (buffer> CHAR_MAX || buffer < CHAR_MIN || fail)
		dispInvalid();
	else if ((buffer < 32 || buffer > 126) && !fail)
		std::cout << "Non displayable";
	else
		std::cout << '\'' << val << '\'';
	dispNl();
}

void display(std::string const & arg, int val, long buffer, bool fail) {
	(void) arg;
	std::cout << "int: ";
	if (buffer > INT_MAX || buffer < INT_MIN || fail)
		dispInvalid();
	else
		std::cout << val;
	dispNl();
}

void display(std::string const & arg, float val, double buffer, bool fail) {
	std::cout << "float: ";
	if (arg == "nan" || arg == "nanf")
		std::cout << "nan" << "f";
	else if (arg == "+inf" || arg == "+inff")
		std::cout << "+inf" << "f";
	else if (arg == "-inf" || arg == "-inff")
		std::cout << "-inf" << "f";
	else if (buffer > FLT_MAX || fail)
		dispInvalid();
	else
		std::cout << val << "f";
	dispNl();
}

void display(std::string const & arg, double val, bool fail) {
	std::cout << "double: ";
	if (arg == "nan" || arg == "nanf")
		std::cout << "nan";
	else if (arg == "+inf" || arg == "+inff")
		std::cout << "+inf";
	else if (arg == "-inf" || arg == "-inff")
		std::cout << "-inf";
	else if (fail)
		dispInvalid();
	else
		std::cout << val;
	dispNl();
}
