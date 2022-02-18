//
// Created by mlabouri on 12/6/21.
//

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "utils/stddef.hpp"

#include "iterators/normal_iterators.hpp"
#include "iterators/reverse_iterator.hpp"

namespace ft {
	//https://www.cplusplus.com/reference/vector/vector
	template<class T, class Alloc = std::allocator<T> >
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
		class normal_iterator : public normal_random_access_iterator<_t> {

		}; //TODO Define content

		template<class _t>
		class reverse_normal_iterator : public reverse_iterator<normal_iterator<_t> > {

		}; //TODO Define content

	public:
		typedef normal_iterator<value_type>					iterator;
		typedef normal_iterator<const value_type>				const_iterator;
		typedef reverse_normal_iterator<iterator>			reverse_iterator;
		typedef reverse_normal_iterator<const_iterator>		const_reverse_iterator;

		// TODO Define member functions
/**  Constructors */
	public:
		explicit vector(const allocator_type& alloc = allocator_type())
		: _allocator(alloc), _data(NULL), _size(0), _capacity(0), _const_data(_data) {} // no elements

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _allocator(alloc), _data(_allocator.allocate(n + 5)), _size(n), _capacity(_size + 5), _const_data(_data) {
			for (size_type i = 0; i < n; i++) {
				_data[i] = val;
			}
		} // n elements at value val

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		: _allocator(alloc) {
			difference_type dist = distance(first, last);
			_size = dist;
			_capacity = _size + 5;
			_data = _allocator.allocate(_capacity);
			_const_data = _data;
			for (size_type i = 0; first != last; first++) {
				_data[i] = *first;
			}
		} // Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.

		vector(const vector& x) : _size(), _capacity() {
			*this = x;
		} // copy

/**  Destructor */
		~vector() {
			_allocator.deallocate(_data, _capacity);
		};

/**  Members Function */
	/** Member Operator Overloads */
	//TODO Needs all other functions
		vector& operator=(const vector& x) {
			_allocator.deallocate(_data, _capacity);
			_data = _allocator.allocate(x._capacity);
			_size = x._size;
			_capacity = x._capacity;
			_const_data = _data;
			sameSizeCopy(x._data, _data, x._size);
		} // https://www.cplusplus.com/reference/vector/vector/operator=/

	/** Iterators Members Function */
	//TODO Needs iterators
		iterator begin();
		const_iterator begin() const;

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;

	/** Capacity Members Function */
		size_type size() const {
			return _size;
		} // Returns the number of elements in the vector.

		size_type max_size() const {
			return _allocator.max_size;
		} // Returns the maximum number of elements that the vector can hold.

		void resize (size_type n, value_type val = value_type()) {
			if (n < _size) {
				_allocator.deallocate(_data + n, _capacity - n);
				_capacity = n;
			} else {
				if (n > _capacity) {
					pointer newData = _allocator.allocate(n);
					sameSizeCopy(_data, newData, _size); // TODO make sure data needs to be at same address or not
					_allocator.deallocate(_data, _capacity);
					_capacity = n;
					_data = newData;
				}
				for (size_type i = _size; i < n; i++) {
					_data[i] = val;
				}
			}
			_size = n;
		} // https://www.cplusplus.com/reference/vector/vector/resize/

		size_type capacity() const {
			return _capacity;
		}

		bool empty() const {
			return _size <= 0;
		}

		void reserve (size_type n) {
			if (n < _capacity)
				return ;
			pointer newData = _allocator.allocate(n);
			sameSizeCopy(_data, newData, _size); // TODO make sure data needs to be at same address or not
			_allocator.deallocate(_data, _capacity);
			_capacity = n;
			_data = newData;
		};

	/** Access Members Function */
		reference operator[] (size_type n) {
			return _data[n];
		}

		const_reference operator[] (size_type n) const {
			return _const_data[n];
		}

		reference at (size_type n) {
			if (n >= _size) {
				throw std::out_of_range("out of range");
			}
			return _data[n];
		}

		const_reference at (size_type n) const {
			if (n >= _size) {
				throw std::out_of_range("out of range");
			}
			return _const_data[n];
		}

		reference front() {
			return *_data;
		}

		const_reference front() const {
			return *_const_data;
		}

		reference back() {
			return _data[_size - 1];
		}

		const_reference back() const {
			return _const_data[_size - 1];
		}

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

		void clear() {
			_allocator.deallocate(_data, _capacity);
			_size = 0;
			_capacity = 0;
			_data = NULL;
			_const_data = NULL;
		}

		allocator_type get_allocator() const {
			return _allocator;
		}

	private:
		allocator_type	_allocator;
		pointer			_data;
		const_pointer	_const_data;
		size_type		_size;
		size_type 		_capacity;

		void sameSizeCopy(const_pointer src, pointer dest, size_type s) {
			for (size_type i = 0; i < s; i++) {
				dest[i] = src[i];
			}
		}
	};

	template <class T>
	void swap (vector<T>& x, vector<T>& y);

	template <class T>
	bool operator== (const vector<T>& lhs, const vector<T>& rhs);

	template <class T>
	bool operator!= (const vector<T>& lhs, const vector<T>& rhs);

	template <class T>
	bool operator<  (const vector<T>& lhs, const vector<T>& rhs);

	template <class T>
	bool operator<= (const vector<T>& lhs, const vector<T>& rhs);

	template <class T>
	bool operator>  (const vector<T>& lhs, const vector<T>& rhs);

	template <class T>
	bool operator>= (const vector<T>& lhs, const vector<T>& rhs);
}

#endif //VECTOR_HPP
