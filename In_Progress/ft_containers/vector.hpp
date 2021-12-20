//
// Created by mlabouri on 12/6/21.
//

#ifndef INC_42_VECTOR_HPP
# define INC_42_VECTOR_HPP

#include <memory>
#include "stddef.hpp"

#include "iterators/normal_iterator.hpp"
#include "iterators/reverse_iterator.hpp"

namespace ft {
	//https://www.cplusplus.com/reference/vector/vector
	template<typename T, class Alloc = std::allocator<T> >
	class vector {
/**  Member Types */
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::pointer 			pointer;
		typedef typename allocator_type::const_pointer 		const_pointer;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

/**  Iterators */
	private:
		template<class _t>
		class normal_iterator : public ft::normal_iterator<_t> {}; //TODO Define content
		template<class _t>
		class reverse_normal_iterator : public ft::normal_iterator<_t> {}; //TODO Define content
	public:
		typedef normal_iterator<pointer>					iterator;
		typedef normal_iterator<const_pointer>				const_iterator;
		typedef reverse_normal_iterator<pointer>			reverse_iterator;
		typedef reverse_normal_iterator<const_pointer>		const_reverse_iterator;

/**  Constructors */
	public:
		vector(); // no elements
		vector(size_type n, const value_type& val = value_type()); // n elements at value val
		template <class InputIterator>
		vector(InputIterator first, InputIterator last); // Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
		vector(const vector& x); // copy

/**  Destructor */
		~vector();

/**  Members Function */
	/** Member Operator Overloads */
		vector& operator=(const vector& x); // https://www.cplusplus.com/reference/vector/vector/operator=/

	/** Iterators Members Function */
		iterator begin();
		const_iterator begin() const;

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;

	/** Capacity Members Function */
		size_type size() const; // Returns the number of elements in the vector.
		size_type max_size() const; // Returns the maximum number of elements that the vector can hold.
		void resize (size_type n, value_type val = value_type()); // https://www.cplusplus.com/reference/vector/vector/resize/
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);

	/** Access Members Function */
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;

		reference at (size_type n);
		const_reference at (size_type n) const;

		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;

	/** Modifiers Members Function */
		void assign (size_type n, const value_type& val); // fill
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last); // range

		iterator insert (iterator position, const value_type& val); // single element
		void insert (iterator position, size_type n, const value_type& val); // fill
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last); // range

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last); // range

		void push_back (const value_type& val);
		void pop_back();
		void swap (vector& x);
		void clear();
	};
}

#endif //INC_42_VECTOR_HPP
