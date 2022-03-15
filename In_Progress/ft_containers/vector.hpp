//
// Created by mlabouri on 12/6/21.
//

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "utils/stddef.hpp"
#include "utils/algorithm.hpp"
#include "utils/exceptions.hpp"

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
		public:
			/** Constructors */
			normal_iterator() : _base(pointer()) {}

			normal_iterator(const normal_iterator& src) {
				*this = src;
			}

			explicit normal_iterator(pointer ptr) : _base(ptr) {
				if (ptr == 0)
					_base = pointer();
			}

			/** Destructor */
			~normal_iterator() {}

			/** Members Function*/
			/** Member Operator Overloads */
			normal_iterator& operator=(const normal_iterator& rhs) {
				_base = rhs._base;
				return *this;
			}

			/** prefix ++a */
			normal_iterator& operator++() {
				_base++;
				return *this;
			}

			/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
			const normal_iterator operator++(const int) {
				normal_iterator temp = *this;
				_base++;
				return temp;
			}

			bool operator==(const normal_iterator& rhs) const {
				return _base == rhs._base;
			}

			bool operator!=(const normal_iterator& rhs) const {
				return _base != rhs._base;
			}

			reference operator*() {
				return *_base;
			} // dereference

			pointer operator->() {
				return &(this->operator*());
			} // structure dereference

			normal_iterator& operator--() {
				_base--;
				return *this;
			} //prefix --a

			normal_iterator operator--(const int) {
				normal_iterator temp = *this;
				_base--;
				return temp;
			} // postfix a-- || int to differentiate between prefix and postfix increment operators.

			normal_iterator operator+(normal_iterator rhs) {
				difference_type diff = this->abs(_base - rhs._base);
				return normal_iterator(_base + diff);
			}

			normal_iterator operator-(normal_iterator rhs) {
				difference_type diff = this->abs(_base - rhs._base);
				return normal_iterator(_base - diff);
			}

			normal_iterator operator+(const int i) {
				return normal_iterator(_base + i);
			}

			normal_iterator operator-(const int i) {
				return normal_iterator(_base - i);
			}

			bool operator<(const normal_iterator& rhs) {
				return _base < rhs._base;
			}

			bool operator>(const normal_iterator& rhs) {
				return _base > rhs._base;
			}

			bool operator<=(const normal_iterator& rhs) {
				return _base <= rhs._base;
			}

			bool operator>=(const normal_iterator& rhs) {
				return _base >= rhs._base;
			}

			normal_iterator& operator+=(normal_iterator rhs) {
				_base = (this + rhs)._base;
				return *this;
			}

			normal_iterator& operator-=(normal_iterator rhs) {
				_base = (this - rhs)._base;
				return *this;
			}

			normal_iterator& operator+=(const int i) {
				_base += i;
				return *this;
			}

			normal_iterator& operator-=(const int i) {
				_base -= i;
				return *this;
			}

			normal_iterator& operator[](const unsigned int i) {
				return _base[i];
			}

		private:
			pointer		_base;
			difference_type abs(difference_type x) {
				if (x > 0)
					return x;
				return x * -1;
			}
		};

	public:
		typedef normal_iterator<value_type>					iterator;
		typedef normal_iterator<const value_type>			const_iterator;
		typedef reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		// TODO Define member functions
/**  Constructors */
	public:
		explicit vector(const allocator_type& alloc = allocator_type())
		: _allocator(alloc), _data(0), _size(0), _capacity(0) {} // no elements

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _allocator(alloc), _data(_allocator.allocate(n + 5)), _size(n), _capacity(_size + 5) {
			for (size_type i = 0; i < n; i++) {
				_allocator.construct(_data + i, val);
			}
		} // n elements at value val

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		: _allocator(alloc) {
			typedef typename std::__is_integer<InputIterator>::__type _Integral
			difference_type dist = ft::distance(first, last);
			_size = dist;
			_capacity = _size + 5;
			_data = _allocator.allocate(_capacity);
			for (size_type i = 0; first != last; first++) {
				_allocator.construct(_data + i, *first);
				i++;
			}
		} // Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.

		vector(const vector& x) : _data(0), _size(), _capacity() {
			*this = x;
		} // copy

/**  Destructor */
		~vector() {
			if (_data != 0) {
				_allocator.deallocate(_data, _capacity);
				_data = 0;
			}
		};

/**  Members Function */
	/** Member Operator Overloads */
		vector& operator=(const vector& x) {
			if (_data != 0) {
				_allocator.deallocate(_data, _capacity);
				_data = 0;
			}
			_data = _allocator.allocate(x._capacity);
			_size = x._size;
			_capacity = x._capacity;
			sameSizeCopy(x._data, _data, x._size);
			return *this;
		}

	/** Iterators Members Function */
		iterator begin() {
			iterator it;
			it = iterator(_data);
			return it;
		}

		const_iterator begin() const {
			return const_iterator(_data);
		}

		iterator end() {
			return iterator(_data + _size);
		}
		const_iterator end() const {
			return const_iterator(_data + _size);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(--this->end());
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(--this->end());
		}

		reverse_iterator rend() {
			return reverse_iterator(--this->begin());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(--this->begin());
		}

	/** Capacity Members Function */
		size_type size() const {
			return _size;
		} // Returns the number of elements in the vector.

		size_type max_size() const {
			return _allocator.max_size;
		} // Returns the maximum number of elements that the vector can hold.

		void resize (size_type n, value_type val = value_type()) {
			if (n <= _size) {
				while (n < _size)
					this->pop_back();
				return;
			}

			if (n > _capacity) {
				this->reserve(n + 5);
			}

			for (size_type i = _size; i < n; i++) {
				_allocator.construct(_data + i, val);
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
			sameSizeCopy(_data, newData, _size);
			if (_data != 0) {
				_allocator.deallocate(_data, _capacity);
				_data = 0;
			}
			_capacity = n;
			_data = newData;
		};

	/** Access Members Function */
		reference operator[] (size_type n) {
			return _data[n];
		}

		const_reference operator[] (size_type n) const {
			return _data[n];
		}

		reference at (size_type n) {
			if (n >= _size) {
				throw ft::out_of_range();
			}
			return _data[n];
		}

		const_reference at (size_type n) const {
			if (n >= _size) {
				throw ft::out_of_range();
			}
			return _data[n];
		}

		reference front() {
			return *_data;
		}

		const_reference front() const {
			return *_data;
		}

		reference back() {
			return _data[_size - 1];
		}

		const_reference back() const {
			return _data[_size - 1];
		}

	/** Modifiers Members Function */
		void assign (size_type n, const value_type& val) {
			this->destroy_data();
			this->resize(n, val);
		} // fill

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			difference_type dist = ft::distance(first, last);
			this->clear();
			this->resize(dist);
			for (size_type i = 0; first != last; first++) {
				_allocator.construct(_data + i, *first);
			}
		} // range

		iterator insert (iterator position, const value_type& val) {
			fullRightShift(position);
			_allocator.construct(&(*position), val);
			return position;
		} // single element

		void insert (iterator position, size_type n, const value_type& val) {
			fullRightShift(position, n);
			for (size_type i = 0; i < n; i++) {
				_allocator.construct(&(*position), val);
				position++;
			}
		} // fill

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) {
			difference_type dist = ft::distance(first, last);
			fullRightShift(position, dist);
			for (; first != last; first++) {
				_allocator.construct(&(*position), *first);
				position++;
			}
		} // range

		iterator erase (iterator position) {
			_allocator.destroy(&(*position));
			fullLeftShift(position);
			return position;
		}

		iterator erase (iterator first, iterator last) {
			for (; first != last; first++) {
				_allocator.destroy(&(*first));
			}
			fullLeftShift(last, ft::distance(first, last));
			return first;
		} // range

		void push_back (const value_type& val) {
			this->resize(_size + 1, val);
		}

		void pop_back() {
			_size--;
			this->destroy_last();
		}

		void swap (vector& x) {
			vector tmp(*this);

			*this = x;
			x = tmp;
		};

		void clear() {
			this->destroy_data();
			_size = 0;
		}

		allocator_type get_allocator() const {
			return _allocator;
		}

	private:
		allocator_type	_allocator;
		pointer			_data;
		size_type		_size;
		size_type 		_capacity;

		void sameSizeCopy(const_pointer src, pointer dest, size_type s) {
			for (size_type i = 0; i < s; i++) {
				_allocator.construct(dest + i, src[i]);
			}
		}

		void destroy_last() {
			_allocator.destroy(_data + _size);
		}

		void destroy_data() {
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_data + i);
		}

		void fullRightShift(iterator position, size_type times = 1) {
			if (_size + times > _capacity) {
				this->resize(_size + times);
			}
			iterator curBegin = this->begin();
			iterator curEnd = this->end() - 1;
			for (; curEnd != curBegin; curEnd--) {
				*(curEnd + times) = *curEnd;
				if (curEnd == position)
					break;
			}
			_size += times;
		}

		void fullLeftShift(iterator position, size_type times = 1) {
			position += times;
			iterator curBegin = this->begin();
			iterator curEnd = this->end();
			for (; position != curEnd; position++) {
				*(position - times) = *position;
				if (curEnd == position)
					break;
			}
			_size -= times;
		}
	};

	template <class T>
	void swap (vector<T>& x, vector<T>& y) {
		 T *tmp = y._data;

		y._data = x._data;
		x._data = tmp;
	}

	template <class T>
	bool operator== (const vector<T>& lhs, const vector<T>& rhs) {
		if (lhs.size() != rhs.size())
			return false;

		return  ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T>
	bool operator<  (const vector<T>& lhs, const vector<T>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T>
	bool operator!= (const vector<T>& lhs, const vector<T>& rhs) {
		return !(lhs == rhs);
	}

	template <class T>
	bool operator>  (const vector<T>& lhs, const vector<T>& rhs) {
		return (rhs < lhs);
	}

	template <class T>
	bool operator<= (const vector<T>& lhs, const vector<T>& rhs) {
		return !(lhs > rhs);
	}

	template <class T>
	bool operator>= (const vector<T>& lhs, const vector<T>& rhs) {
			return !(lhs < rhs);
	}
}

#endif //VECTOR_HPP
