//
// Created by mlabouri on 12/1/21.
//

#include <string>
#include <iostream>
#include "iter.hpp"

void addOneAndDisplay(int & i) {
	std::cout << ++i << std::endl;
}

void displayString(std::string & s) {
	std::cout << s << std::endl;
}

int main() {
	int tabInt[5] = {0, 1, 2, 3, 4};
	std::string tabString[3] = {"hello", "coucou", "sava"};

	::iter(tabInt, 5, addOneAndDisplay);
	::iter(tabString, 3, displayString);
	::iter(tabInt, 5, addOneAndDisplay);
}
