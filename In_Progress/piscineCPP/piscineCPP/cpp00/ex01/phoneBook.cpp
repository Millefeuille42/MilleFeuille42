//
// Created by millefeuille on 3/22/21.
//

#include <cstdlib>
#include "phoneBook.hpp"

void displaySearch(Contact contacts[8], int contactNum) {
	int wantedContact = -1;
	std::string input;

	std::cout << "| Index | First Name | Last Name  | Nickname   |" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	for (int i = 0; i < contactNum; i++) {
		contacts[i].displayContactSearch();
		std::cout << "------------------------------------------------" << std::endl;
	}
	std::cin >> input;
	for (; wantedContact < 0 || wantedContact >= contactNum;) {
		if (!input.empty() && std::isdigit(input.at(0))) {
			wantedContact = std::atoi(input.c_str());
			input.clear();
			continue ;
		}
		std::cout << "Invalid input" << std::endl;
		std::cin >> input;
	}
	contacts[wantedContact].displayContact();
}

int	main() {
	int	contactNum = 0;
	Contact	contacts[8];

	for (std::string userInput; userInput != "EXIT";) {
		std::cin >> userInput;
		if (userInput == "ADD") {
			if (contactNum >= 8) {
				std::cout << "The Phone Book is full!" << std::endl;
				continue ;
			}
			contacts[contactNum].createContact(contactNum);
			contactNum++;
		}
		if (userInput == "SEARCH") {
			if (!contactNum) {
				std::cout << "The Phone Book is empty!" << std::endl;
				continue ;
			}
			displaySearch(contacts, contactNum);
		}
	}
}