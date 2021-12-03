//
// Created by Millefeuille on 02/12/2021.
//

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T>
void	easyfind(T& t, int i) {
	typename T::const_iterator it;

	it = std::find(t.begin(), t.end(), i);
	if (it == t.end()) {
		std::cout << "Value not found in container" << std::endl;
		return;
	}
	std::cout << "Value found in container" << std::endl;
}

#endif //EASYFIND_HPP
