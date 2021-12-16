//
// Created by mlabouri on 12/6/21.
//

#ifndef INC_42_VECTOR_HPP
# define INC_42_VECTOR_HPP

#include <memory>
#include "iterators/iterator.hpp"
#include "iterators/iterator_tags.hpp"

namespace ft {
	//https://www.cplusplus.com/reference/vector/vector
	template<typename T, class Alloc = std::allocator<T> >
	class vector {
	public:
/**  Member Types */
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

/** Inner Classes */
	/** Iterators https://www.cplusplus.com/reference/iterator/ */
	class iterator : public ft::iterator<random_access_iterator_tag, T> {
	public:
		/** Constructors */
		iterator();
		iterator(const iterator& src);
		/** Members Function*/
		/** Member Operator Overloads */
		iterator& operator=(const iterator& rhs);
		/** prefix ++a */
		iterator& operator++();
		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		iterator operator++(int);
		bool operator==(const iterator& rhs) const;
		bool operator!=(const iterator& rhs) const;
		iterator& operator*(); // dereference
		iterator* operator->(); // structure dereference
		iterator& operator--(); //prefix --a
		iterator operator--(int); // postfix a-- || int to differentiate between prefix and postfix increment operators.
		iterator operator+(iterator rhs);
		iterator operator-(iterator rhs);
		iterator operator+(int i);
		iterator operator-(int i);
		bool operator<(const iterator& rhs);
		bool operator>(const iterator& rhs);
		bool operator<=(const iterator& rhs);
		bool operator>=(const iterator& rhs);
		iterator& operator+=(iterator rhs);
		iterator& operator-=(iterator rhs);
		iterator& operator+=(int i);
		iterator& operator-=(int i);
		iterator& operator[](unsigned int i);
	};
/**  Constructors */
		vector(); // Constructs an empty container, with no elements.
		vector(size_type n, const value_type& val = value_type()); // Constructs a container with n elements. Each element is a copy of val.
		template <class InputIterator> vector(InputIterator first, InputIterator last); // Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
		vector(const vector& x); // Constructs a container with a copy of each of the elements in x, in the same order.

/**  Destructor */
		~vector(); // This destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator.

/**  Members Function*/
	/** Member Operator Overloads */
		vector& operator=(const vector& x); // https://www.cplusplus.com/reference/vector/vector/operator=/

	/** Iterators Members Function*/
		void begin();
		void end();

	/** Capacity Members Function */
		size_type size() const; // Returns the number of elements in the vector.
		size_type max_size() const; // Returns the maximum number of elements that the vector can hold.
		void resize (size_type n, value_type val = value_type()); // https://www.cplusplus.com/reference/vector/vector/resize/

	};
}

#endif //INC_42_VECTOR_HPP
