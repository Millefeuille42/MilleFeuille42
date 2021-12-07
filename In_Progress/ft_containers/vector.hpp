//
// Created by mlabouri on 12/6/21.
//

#ifndef INC_42_VECTOR_HPP
# define INC_42_VECTOR_HPP

namespace ft {
	//https://www.cplusplus.com/reference/vector/vector
	template<class T, class Alloc = std::allocator<T> > class vector {
/** @public */
	public:
/** @section Member Types */
		typedef T value_type;
		typedef Alloc allocator_type;

		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		/* TODO Iterators
		 *	iterator	a random access iterator to value_type	convertible to const_iterator
		 *	const_iterator	a random access iterator to const value_type
		 *	reverse_iterator	reverse_iterator<iterator>
		 *	const_reverse_iterator	reverse_iterator<const_iterator>
		 */

		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

/** @section Constructors */
		vector(); // Constructs an empty container, with no elements.
		vector(size_type n, const value_type& val = value_type()); // Constructs a container with n elements. Each element is a copy of val.
		template <class InputIterator> vector(InputIterator first, InputIterator last); // Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
		vector(const vector& x); // Constructs a container with a copy of each of the elements in x, in the same order.

/** @section Destructor */
		~vector(); // This destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator.

/** @section Members Function*/
	/** @subsection Member Operator Overloads */
		vector& operator=(const vector& x); // https://www.cplusplus.com/reference/vector/vector/operator=/

	/** @subsection Iterators Members Function*/

	/** @subsection Capacity Members Function */
		size_type size() const; // Returns the number of elements in the vector.
		size_type max_size() const; // Returns the maximum number of elements that the vector can hold.
		void resize (size_type n, value_type val = value_type()); // https://www.cplusplus.com/reference/vector/vector/resize/

	};
}

#endif //INC_42_VECTOR_HPP
