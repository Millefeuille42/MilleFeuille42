//
// Created by millefeuille on 23/03/2021.
//

#include <string>
#include <iostream>

void	displayStrings(std::string *p_str, std::string &r_str) {
	std::cout << *p_str << std::endl;
	std::cout << r_str << std::endl;
}

int	main() {
	std::string str = "HI THIS IS BRAIN";

	displayStrings(&str, str);
}