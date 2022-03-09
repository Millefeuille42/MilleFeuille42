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

#endif //INC_42_ITER_HPP
