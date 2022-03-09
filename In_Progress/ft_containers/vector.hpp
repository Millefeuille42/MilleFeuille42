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
		public:
			/** Constructors */
			normal_iterator() : _base(pointer(value_type())) {}

			normal_iterator(const normal_iterator& src) {
				*this = src;
			}

			explicit normal_iterator(pointer ptr) : _base(ptr) {
				if (ptr == NULL)
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
			normal_iterator operator++(const int) {
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

			_t& operator*() {
				return *_base;
			} // dereference

			_t* operator->() {
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
				return _base < rhs;
			}

			bool operator>(const normal_iterator& rhs) {
				return _base > rhs;
			}

			bool operator<=(const normal_iterator& rhs) {
				return _base <= rhs;
			}

			bool operator>=(const normal_iterator& rhs) {
				return _base >= rhs;
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
			}

			normal_iterator& operator[](const unsigned int i) {
				_base[i];
			}

		private:
			pointer		_base;
			difference_type abs(difference_type x) {
				if (x > 0)
					return x;
				return x * -1;
			}
		};

		template<class _t>
		class reverse_normal_iterator : public reverse_iterator<normal_iterator<_t> > {

		};

	public:
		typedef normal_iterator<value_type>					iterator;
		typedef normal_iterator<const value_type>			const_iterator;
		typedef reverse_normal_iterator<iterator>			reverse_iterator;
		typedef reverse_normal_iterator<const_iterator>		const_reverse_iterator;

		// TODO Define member functions
		// TODO Construct!!
		// TODO Lexicographical_compare && Equal
/**  Constructors */
	public:
		explicit vector(const allocator_type& alloc = allocator_type())
		: _allocator(alloc), _data(NULL), _size(0), _capacity(0) {} // no elements

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _allocator(alloc), _data(_allocator.allocate(n + 5)), _size(n), _capacity(_size + 5) {
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
		vector& operator=(const vector& x) {
			_allocator.deallocate(_data, _capacity);
			_data = _allocator.allocate(x._capacity);
			_size = x._size;
			_capacity = x._capacity;
			sameSizeCopy(x._data, _data, x._size);
		}

	/** Iterators Members Function */
		iterator begin() {
			return iterator(_data);
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
				_data[i] = val;
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
			_allocator.deallocate(_data, _capacity);
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
				throw std::out_of_range("out of range");
			}
			return _data[n];
		}

		const_reference at (size_type n) const {
			if (n >= _size) {
				throw std::out_of_range("out of range");
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
			this->clear();
			resize(n, val);
		} // fill

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			difference_type dist = distance(first, last);
			this->clear();
			resize(dist);
			for (size_type i = 0; first != last; first++) {
				_data[i] = *first;
			}
		} // range

		iterator insert (iterator position, const value_type& val); // single element
		void insert (iterator position, size_type n, const value_type& val); // fill
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last); // range

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last); // range

		void push_back (const value_type& val) {
			this->resize(_size + 1, val);
		}

		void pop_back() {
			_size--;
			this->destroy_last();
		}

		void swap (vector& x) {
			pointer tmp = _data;

			_data = x._data;
			x._data = tmp;
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
				dest[i] = src[i];
			}
		}

		void destroy_last() {
			_allocator.destroy(_data + _size);
		}

		void destroy_data() {
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_data + i);
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
		typedef typename ft::vector<T>::iterator iterator;

		if (lhs.size() != rhs.size())
			return false;

		iterator r = rhs.begin();

		for (iterator l = lhs.begin(); l != lhs.end(); l++) {
			if (++r != l)
				return false;
		}
		return true;
	}

	template <class T>
	bool operator<  (const vector<T>& lhs, const vector<T>& rhs) {
		typedef typename ft::vector<T>::iterator iterator;
		iterator l = lhs.begin();
		iterator r = rhs.begin();

		while (l != lhs.end()) {
			if (*l > *r || r == rhs.end())
				return false;
			if (*l < *r)
				return true;
			l++;
			r++;
		}
		return true;
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
