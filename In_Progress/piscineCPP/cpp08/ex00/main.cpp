//
// Created by Millefeuille on 02/12/2021.
//

#include <list>
#include "easyfind.hpp"

int main() {
	std::list<int> l;

	for (int i = 0; i <= 100; i++)
		l.push_back(i);

	easyfind<std::list<int> >(l, 42);
	easyfind<std::list<int> >(l, 99);
	easyfind<std::list<int> >(l, 100);
	easyfind<std::list<int> >(l, -1);

	return (0);
}
