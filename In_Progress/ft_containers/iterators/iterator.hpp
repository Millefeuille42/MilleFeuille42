//
// Created by mlabouri on 12/16/21.
//

#ifndef INC_42_ITERATOR_HPP
#define INC_42_ITERATOR_HPP

#include "../stddef.hpp"

namespace ft {

	/** Iterators https://www.cplusplus.com/reference/iterator/iterator */
	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};
}

#endif //INC_42_ITERATOR_HPP
