//
// Created by Millefeuille on 02/12/2021.
//

#include <list>
#include "easyfind.hpp"

int main() {
	std::list<int> l;

	for (int i = 0; i <= 100; i++)
		l.push_back(i);

	std::cout << easyfind<std::list<int> >(l, 42) << std::endl;
	std::cout << easyfind<std::list<int> >(l, 99) << std::endl;
	std::cout << easyfind<std::list<int> >(l, 100) << std::endl;
	std::cout << easyfind<std::list<int> >(l, -1) << std::endl;

	return (0);
}
