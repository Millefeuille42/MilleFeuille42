//
// Created by Millefeuille on 02/12/2021.
//

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T>
bool	easyfind(T& t, int i) {
	typename T::const_iterator it;

	it = std::find(t.begin(), t.end(), i);
	return it != t.end();
}

#endif //EASYFIND_HPP
