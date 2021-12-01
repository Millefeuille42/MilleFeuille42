//
// Created by mlabouri on 12/1/21.
//

#ifndef INC_42_ITER_HPP
#define INC_42_ITER_HPP

template<typename T>
void iter(T *address, unsigned int len, void (*func)(T &)) {
	if (address == NULL || func == NULL)
		return ;
	for (unsigned int i = 0; i < len; i++) {
		func(address[i]);
	}
}



//Write a function template iter that take 3 parameters and returns nothing. The first
//parameter is the address of an array, the second one is the length of the array and the
//third one is a function called for each element of the array

#endif //INC_42_ITER_HPP
