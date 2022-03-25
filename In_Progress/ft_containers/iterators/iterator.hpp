//
// Created by mlabouri on 12/16/21.
//

#ifndef INC_42_ITERATOR_HPP
#define INC_42_ITERATOR_HPP

#include "../utils/stddef.hpp"

/// Defines the iterator base class, with all the required member types
namespace ft {

	struct default_iterator { };

	/** Iterators https://www.cplusplus.com/reference/iterator/iterator */
	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator : default_iterator {
	public:
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template <class Category, class T>
	struct iterator<Category, const T> : default_iterator {
	public:
		typedef const T   value_type;
		typedef ptrdiff_t difference_type;
		typedef T*		  pointer;
		typedef const T&        reference;
		typedef Category  iterator_category;
	};
}

#endif //INC_42_ITERATOR_HPP
