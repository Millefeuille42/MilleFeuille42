//
// Created by mlabouri on 12/16/21.
//

#ifndef INC_42_ITERATOR_TRAITS_HPP
# define INC_42_ITERATOR_TRAITS_HPP

#include "../utils/stddef.hpp"
#include "../utils/type_traits.hpp"

#include "iterator_tags.hpp"


/// Defines the iterator_traits class
namespace ft {

	template<typename _iterator>
	struct iterator_traits {
		typedef typename _iterator::iterator_category iterator_category;
		typedef typename _iterator::value_type        value_type;
		typedef typename _iterator::difference_type   difference_type;
		typedef typename _iterator::pointer           pointer;
		typedef typename _iterator::reference         reference;
	};

	template<typename _t>
	struct iterator_traits<_t*> {
		typedef std::random_access_iterator_tag iterator_category;
		typedef _t                         value_type;
		typedef ptrdiff_t                   difference_type;
		typedef _t*                        pointer;
		typedef _t&                        reference;
	};

	template<typename _t>
	struct iterator_traits<const _t*> {
		typedef std::random_access_iterator_tag iterator_category;
		typedef _t                         value_type;
		typedef ptrdiff_t                   difference_type;
		typedef const _t*                  pointer;
		typedef const _t&                  reference;
	};

	template<> struct iterator_traits<int> {
		typedef std::random_access_iterator_tag iterator_category;
		typedef int                         value_type;
		typedef ptrdiff_t                   difference_type;
		typedef int*                        pointer;
		typedef int&                        reference;
	};
}

#endif //INC_42_ITERATOR_TRAITS_HPP
