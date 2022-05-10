//
// Created by mlabouri on 12/6/21.
//

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <memory>

#include "includes/libs/stddef.hpp"
#include "includes/libs/algorithm.hpp"
#include "includes/libs/exceptions.hpp"
#include "includes/libs/type_traits.hpp"

#include "includes/iterators/normal_iterators.hpp"
#include "includes/iterators/reverse_iterator.hpp"
#include "includes/utils/vector_iterator.hpp"

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector {
		public :
			//Member Type;
			typedef T			value_type;
			typedef Allocator	allocator_type;
			typedef typename	allocator_type::reference reference;
			typedef typename	allocator_type::const_reference const_reference;
			typedef typename	allocator_type::pointer pointer;
			typedef typename	allocator_type::const_pointer const_pointer;
			typedef typename	ft::vector_iterator<value_type> iterator;
			typedef typename	ft::vector_iterator<const value_type> const_iterator;
			typedef typename	ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename	ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename 	ft::iterator_traits<iterator>::difference_type difference_type;
			typedef typename	allocator_type::size_type 	size_type;

			//Default Constructor
			vector(const allocator_type &alloc = allocator_type()) : _allocator(alloc),
																				_first(0),
																				_last(0),
																				_max (0) {

			}
			//fill constructor
			vector(size_type n, const value_type &val = value_type(),
							const allocator_type &alloc = allocator_type()) : _allocator(alloc),
																				_first(0),
																				_last(0),
																				_max(0) {
				_first = _allocator.allocate(n);
				_max = n;
				_last = _first;
				for (size_type i = 0; i < n; i++) {
					_allocator.construct(_last, val);
					_last++;
				}
			}
			//range constructor
			template <class InputIterator>
			vector(typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, InputIterator last,
				   const allocator_type &alloc = allocator_type()) : _allocator(alloc),
				   														_first(0),
																		_last(0),
																		_max(0) {
				size_type n = ft::distance(first, last);
				_first = _allocator.allocate(n);
				_max = n;
				_last = _first;
				for (size_type i = 0; i < n; i++) {
					_allocator.construct(_last, *first++);
					_last++;
				}
			}
			//copy constructor
			vector(const vector &src) : _allocator(src._allocator),
										_first(0),
										_last(0),
										_max(0) {
				*this = src;
			}
			//destructor
			~vector() {
				clear();
				_allocator.deallocate(_first, _max);
			}

			//Operator =
			vector &operator=(const vector &src) {
				if (src == *this)
					return (*this);
				if (_first != NULL) {
					clear();
					_allocator.deallocate(_first, _max);
				}
				pointer srcFirst = src._first;
				size_type n = ft::distance(src.begin(), src.end());
				_first = _allocator.allocate(n);
				_max = n;
				_last = _first;
				for (size_type i = 0; i < n; i++) {
					_allocator.construct(_last, *srcFirst++);
					_last++;
				}
				return *this;
			}

			//Iterators
			iterator begin() {
				return iterator(_first);
			}
			const_iterator begin() const {
				return const_iterator(_first);
			}

			iterator end() {
				return iterator(_last);
			}
			const_iterator end() const {
				return const_iterator(_last);
			}

			reverse_iterator rbegin() {
				return reverse_iterator(end());
			}
			const_reverse_iterator rbegin() const {
				return reverse_iterator(end());
			}

			reverse_iterator rend() {
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const {
				return reverse_iterator(begin());
			}


			//Capacity
			size_type size() const {
				return _last - _first;
			}

			size_type max_size() const {
				return allocator_type().max_size();
			}

			void resize(size_type n, value_type val = value_type()) {
				if (n > max_size())
					throw (std::length_error("vector::resize"));
				else if (n > size())
					insert(end(), n - size(), val);
				else if (n < size()) {
					while (n < size()) {
						_last--;
						_allocator.destroy(_last);
					}
				}
			}

			size_type capacity() const {
				return _max;
			}

			bool empty() const {
				return size() <= 0;
			}

			void reserve(size_type n) {
				if (n > max_size())
					throw (std::length_error("vector::reserve"));
				else if (n > _max) {
					pointer tmp_first = _first;
					pointer tmp_last = _last;
					size_type tmp_max = _max;

					_first = _allocator.allocate(n);
					_max = n;
					_last = _first;
					for (size_type i = 0; (tmp_first + i) != tmp_last; i++) {
						_allocator.construct(_last, *(tmp_first + i));
						_allocator.destroy(tmp_first + i);
						_last++;
					}
					_allocator.deallocate(tmp_first, tmp_max);
				}
			}


			//Element access
			reference operator[](size_type n) {
				return *(_first + n);
			}
			const_reference operator[](size_type n) const {
				return *(_first + n);
			}

			reference at(size_type n) {
				if (n >= size())
					throw std::out_of_range("");
				else
					return (*this)[n];
			}
			const_reference at(size_type n) const {
				if (n >= size())
					throw std::out_of_range("");
				else
					return (*this)[n];
			}

			reference front() {
				return(*_first);
			}
			const_reference  front() const {
				return *_first;
			}

			reference back() {
				return *(_last - 1);
			}
			const_reference back() const {
				return *(_last - 1);
			}


			//Modifiers
			template <class InputIterator>
			void assign(typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, InputIterator last) {
				clear();
				size_type n = ft::distance(first, last);
				if (n <= 0)
					return ;
				if (size() + n <= _max) {
					for (size_type i = 0; i < n; i++) {
						_allocator.construct(_last, *first++);
						_last++;
					}
				}
				else
				{
					if (_first != NULL)
						_allocator.deallocate(_first, _max);
					_first = _allocator.allocate(n);
					_max = n;
					_last = _first;
					for (size_type i = 0; i < n; i++) {
						_allocator.construct(_last, *first++);
						_last++;
					}
				}
			}
			void assign(size_type n, const value_type &val) {
				clear();
				if (n <= 0)
					return ;
				if (size() + n <= _max) {
					for (size_type i = 0; i < n; i++) {
						_allocator.construct(_last, val);
						_last++;
					}
				}
				else {
					if (_first != NULL)
						_allocator.deallocate(_first, _max);
					_first = _allocator.allocate(n);
					_max = n;
					_last = _first;
					for (size_type i = 0; i < n; i++) {
						_allocator.construct(_last, val);
						_last++;
					}
				}
			}

			void push_back(const value_type &val) {
				if (size() == _max) {
					if (size() > 0)
						reserve(size() * 2);
					else
						reserve(1);
				}
				_allocator.construct(_last, val);
				_last++;
			}

			void pop_back() {
				_last--;
				_allocator.destroy(_last);
			}

			iterator insert(iterator position, const value_type &val) {
				pointer pos = &(*position);
				if (size() == _max) {
					size_t i = 0;
					for (pointer tmp_first = _first; tmp_first != pos; tmp_first++)
						i++;
					if (_max > 0)
						reserve(size() * 2);
					else
						reserve(1);
					pos = _first + i;
				}
				pointer tmp_cur = _last;
				_last++;
				while (tmp_cur != pos) {
					_allocator.construct(tmp_cur, *(tmp_cur - 1));
					_allocator.destroy(tmp_cur - 1);
					tmp_cur--;
				}
				_allocator.construct(tmp_cur, val);
				return iterator(tmp_cur);
			}
			void insert(iterator position, size_type n, const value_type &val) {
				if (n == 0)
					return ;
				pointer pos = &(*position);
				if ((size() + n) > _max) {
					size_t i = 0;
					for (pointer tmp_first = _first; tmp_first != pos; tmp_first++)
						i++;
					if ((size() * 2) < (size() + n))
						reserve(size() + n);
					else
						reserve(size() * 2);
					pos = _first + i;
				}
				pointer tmp = _last + (n - 1);
				_last += n;
				while (tmp - n >= pos) {
					_allocator.construct(tmp, *(tmp - n));
					_allocator.destroy(tmp - n);
					tmp--;
				}
				while (tmp != pos)
					tmp--;
				for (size_type i = 0; i < n; i++) {
					_allocator.construct(tmp, val);
					tmp++;
				}
			}
			template <class InputIterator>
			void insert(iterator position, typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, InputIterator last) {
				size_type n = ft::distance(first,  last);
				if (n <= 0)
					return ;
				pointer pos = &(*position);
				if ((size() + n) > _max) {
					size_t i = 0;
					for (pointer tmp_first = _first; tmp_first != pos; tmp_first++)
						i++;
					if ((size() * 2) < (size() + n))
						reserve(size() + n);
					else
						reserve(size() * 2);
					pos = _first + i;
				}
				pointer tmp = _last + (n - 1);
				_last += n;
				while (tmp - n >= pos) {
					_allocator.construct(tmp, *(tmp - n));
					_allocator.destroy(tmp - n);
					tmp--;
				}
				while (tmp != pos)
					tmp--;
				for (size_type i = 0; i < n; i++) {
					_allocator.construct(tmp, *first);
					first++;
					tmp++;
				}
			}

			iterator erase(iterator position) {
				pointer pos = &(*position);
				pointer cur = pos;
				_allocator.destroy(cur);
				_last--;
				while (cur != _last) {
					_allocator.construct(cur, *(cur + 1));
					_allocator.destroy(cur + 1);
					cur++;
				}
				return iterator(pos);
			}
			iterator erase(iterator first, iterator last) {
				size_type n = ft::distance(first, last);
				pointer p_first = &(*first);
				pointer cur = p_first;
				for (size_type i = 0; i < n; i++) {
					_allocator.destroy(cur);
					cur++;
				}
				while (cur != _last) {
					_allocator.construct((cur - n), *cur);
					_allocator.destroy(cur);
					cur++;
				}
				_last -= n;
				return iterator(p_first);
			}

			void swap(vector &x) {
				if (x == *this)
					return ;
				allocator_type tmp_allocator = _allocator;
				pointer tmp_first = _first;
				pointer tmp_last = _last;
				size_type tmp_max = _max;

				_allocator = x._allocator;
				_first = x._first;
				_last = x._last;
				_max = x._max;

				x._allocator = tmp_allocator;
				x._first = tmp_first;
				x._last = tmp_last;
				x._max = tmp_max;
			}

			void clear() {
				size_type tmp_size = size();
				size_type i = 0;
				while (i < tmp_size) {
					_last--;
					_allocator.destroy(_last);
					i++;
				}
			}

			//Allocator
			allocator_type get_allocator() const {
				return _allocator;
			}

		protected :
			allocator_type _allocator;
			pointer _first;
			pointer _last;
			size_type _max;
	};

	//relational operators
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return rhs < lhs;
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(lhs < rhs);
	}

	//Swap
	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
		x.swap(y);
	}
}

#endif
