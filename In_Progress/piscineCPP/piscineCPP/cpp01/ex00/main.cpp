//
// Created by millefeuille on 23/03/2021.
//

#include "Pony.hpp"

int main() {
	ponyOnTheHeap(4, "Rapid Shadow");
	std::cout << std::endl;
	ponyOnTheHeap(6, "Dark Snow");
	std::cout << std::endl;
	ponyOnTheStack(9, "Onyx Star");
	std::cout << std::endl;
	ponyOnTheStack(3, "Tiny Thunder");
	return 0;
}
