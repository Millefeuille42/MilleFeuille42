//
// Created by mlabouri on 4/22/22.
//

#ifndef INC_42_DEFAULT_CONTAINER_HPP
#define INC_42_DEFAULT_CONTAINER_HPP

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class default_container {
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::pointer 			pointer;
		typedef typename allocator_type::const_pointer 		const_pointer;
		typedef size_t										size_type;
	};
}

#endif //INC_42_DEFAULT_CONTAINER_HPP
