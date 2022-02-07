//
// Created by mlabouri on 12/16/21.
//

#ifndef INC_42_ITERATOR_HPP
#define INC_42_ITERATOR_HPP

#include "../utils/stddef.hpp"
#include "iterator_tags.hpp"

/// Defines the iterator base class, with all the required member types
namespace ft {
	/** Iterators https://www.cplusplus.com/reference/iterator/iterator */
	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator {
	protected:
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template <class Category, class T>
	struct iterator<Category, const T> {
	protected:
		typedef T         value_type;
		typedef ptrdiff_t difference_type;
		typedef const T*		  pointer;
		typedef const T&        reference;
		typedef Category  iterator_category;
	};
}

#endif //INC_42_ITERATOR_HPP
