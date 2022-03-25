//
// Created by millefeuille on 3/22/21.
//

#include "contact.hpp"

void Contact::createContact(int contactNumber) {
	std::string input;

	for (int i = 0; i < 11; i++) {
		std::cout << fields[i] << ": ";
		std::cin >> input;
		dataFields[i] = input;
	}
	index = contactNumber;
}

void Contact::displayContact() const {
	for (int i = 0; i < 11; i++) {
		std::cout << fields[i] << ": " << this->dataFields[i] << std::endl;
	}
}

void Contact::displayContactSearch() const {
	std::cout << "| " << index << "    ";
	for (int fieldIndex = 0; fieldIndex < 3; fieldIndex++) {
		std::cout << " | ";
		for (int i = 0; i < 10; i++) {
			if (i < (int)dataFields[fieldIndex].size() && i <= 8) {
				std::cout << dataFields[fieldIndex].at(i);
				continue ;
			}
			if (i > 8 && i < (int)dataFields[fieldIndex].size()) {
				std::cout << ".";
				break ;
			}
			std::cout << " ";
		}
	}
	std::cout << " |" << std::endl;
}
