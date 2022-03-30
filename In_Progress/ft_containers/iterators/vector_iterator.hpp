//
// Created by mlabouri on 3/28/22.
//

#ifndef INC_42_VECTOR_ITERATOR_HPP
#define INC_42_VECTOR_ITERATOR_HPP

#include "normal_iterators.hpp"

namespace ft {
	template<class _t>
	class vector_iterator : public normal_random_access_iterator<_t> {
	public:

		typedef typename vector_iterator<_t>::iterator::value_type value_type;
		typedef typename vector_iterator<_t>::iterator::pointer pointer;
		typedef typename vector_iterator<_t>::iterator::reference reference;
		typedef typename vector_iterator<_t>::iterator::difference_type difference_type;
		typedef typename vector_iterator<_t>::iterator::iterator_category iterator_category;

		/** Constructors */
		vector_iterator() : _base(pointer()) {}

		vector_iterator(const vector_iterator &src) {
			*this = src;
		}

		vector_iterator(pointer ptr) : _base(ptr) {
			if (ptr == 0)
				_base = pointer();
		}

		/** Destructor */
		~vector_iterator() {}

		/** Members Function*/
		/** Member Operator Overloads */
		vector_iterator &operator=(const vector_iterator &rhs) {
			_base = rhs._base;
			return *this;
		}

		/** prefix ++a */
		vector_iterator &operator++() {
			_base++;
			return *this;
		}

		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		const vector_iterator operator++(const int) {
			vector_iterator temp = *this;
			_base++;
			return temp;
		}

		bool operator==(const vector_iterator &rhs) const {
			return _base == rhs._base;
		}

		bool operator!=(const vector_iterator &rhs) const {
			return _base != rhs._base;
		}

		reference operator*() {
			return *_base;
		} // dereference

		const reference operator*() const {
			return *_base;
		} // dereference

		pointer operator->() {
			return _base;
		} // structure dereference

		const pointer operator->() const {
			return _base;
		} // structure dereference

		vector_iterator &operator--() {
			_base--;
			return *this;
		} //prefix --a

		const vector_iterator operator--(const int) {
			vector_iterator temp = *this;
			_base--;
			return temp;
		} // postfix a-- || int to differentiate between prefix and postfix increment operators.

		vector_iterator operator+(vector_iterator rhs) const {
			difference_type diff = _base - rhs._base;
			return vector_iterator(_base + diff);
		}

		difference_type operator-(vector_iterator rhs) const {
			difference_type diff = _base - rhs._base;

			return diff;
		}

		vector_iterator operator+(const int i) const {
			return vector_iterator(_base + i);
		}

		vector_iterator operator-(const int i) const {
			return vector_iterator(_base - i);
		}

		bool operator<(const vector_iterator &rhs) const {
			return _base < rhs._base;
		}

		bool operator>(const vector_iterator &rhs) const {
			return _base > rhs._base;
		}

		bool operator<=(const vector_iterator &rhs) const {
			return _base <= rhs._base;
		}

		bool operator>=(const vector_iterator &rhs) const {
			return _base >= rhs._base;
		}

		vector_iterator &operator+=(vector_iterator rhs) {
			_base = (this + rhs)._base;
			return *this;
		}

		vector_iterator &operator-=(vector_iterator rhs) {
			_base = (this - rhs)._base;
			return *this;
		}

		vector_iterator &operator+=(const int i) {
			_base += i;
			return *this;
		}

		vector_iterator &operator-=(const int i) {
			_base -= i;
			return *this;
		}

		value_type &operator[](const unsigned int i) const {
			return _base[i];
		}

		operator vector_iterator<const _t> const() {
			return (vector_iterator<const _t>(_base));
		};

	protected:
		pointer _base;

		difference_type abs(difference_type x) const {
			if (x > 0)
				return x;
			return x * -1;
		}
	};

	template <class T>
	bool operator== (const vector_iterator<T> & lhs, const vector_iterator<T> & rhs) {
		return &(*lhs) == &(*rhs);
	}

	template <class T>
	bool operator== (const vector_iterator<const T> & lhs, const vector_iterator<T> & rhs) {
		return &(*lhs) == &(*rhs);
	}

	template <class T>
	bool operator== (const vector_iterator<T> & lhs, const vector_iterator<const T> & rhs) {
		return &(*lhs) == &(*rhs);
	}

	template <class T>
	bool operator!= (const vector_iterator<T> & lhs, const vector_iterator<T> & rhs) {
		return &(*lhs) != &(*rhs);
	}

	template <class T>
	bool operator!= (const vector_iterator<const T> & lhs, const vector_iterator<T> & rhs) {
		return &(*lhs) != &(*rhs);
	}

	template <class T>
	bool operator!= (const vector_iterator<T> & lhs, const vector_iterator<const T> & rhs) {
		return &(*lhs) != &(*rhs);
	}

	template <class T>
	bool operator<(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)  {
		return &(*lhs) < &(*rhs);
	}

	template <class T>
	bool operator<(const vector_iterator<const T> &lhs, const vector_iterator<T> &rhs)  {
		return &(*lhs)< &(*rhs);
	}

	template <class T>
	bool operator<(const vector_iterator<T> &lhs, const vector_iterator<const T> &rhs)  {
		return &(*lhs)< &(*rhs);
	}

	template <class T>
	bool operator>(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return &(*lhs)> &(*rhs);
	}

	template <class T>
	bool operator>(const vector_iterator<const T> &lhs, const vector_iterator<T> &rhs) {
		return &(*lhs)> &(*rhs);
	}

	template <class T>
	bool operator>(const vector_iterator<T> &lhs, const vector_iterator<const T> &rhs) {
		return &(*lhs)> &(*rhs);
	}

	template <class T>
	bool operator<=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return &(*lhs)<= &(*rhs);
	}

	template <class T>
	bool operator<=(const vector_iterator<const T> &lhs, const vector_iterator<T> &rhs) {
		return &(*lhs)<= &(*rhs);
	}

	template <class T>
	bool operator<=(const vector_iterator<T> &lhs, const vector_iterator<const T> &rhs) {
		return &(*lhs)<= &(*rhs);
	}

	template <class T>
	bool operator>=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return &(*lhs)>= &(*rhs);
	}

	template <class T>
	bool operator>=(const vector_iterator<const T> &lhs, const vector_iterator<T> &rhs) {
		return &(*lhs)>= &(*rhs);
	}

	template <class T>
	bool operator>=(const vector_iterator<T> &lhs, const vector_iterator<const T> &rhs) {
		return &(*lhs)>= &(*rhs);
	}

	template <class T>
	typename vector_iterator<T>::difference_type operator-(const vector_iterator<T> lhs, const vector_iterator<const T> rhs) {
		typename vector_iterator<T>::difference_type diff = lhs.operator->() - rhs.operator->();

		return diff;
	}

	template <class T>
	typename vector_iterator<T>::difference_type operator-(const vector_iterator<const T> lhs, const vector_iterator<T> rhs) {
		typename vector_iterator<T>::difference_type diff = lhs.operator->() - rhs.operator->();

		return diff;
	}

	template <class T>
	vector_iterator<T> operator+(const vector_iterator<T> it,  const int i) {
		return vector_iterator<T>(&(*it) + i);
	}

	template <class T>
	vector_iterator<T> operator+(const int i, const vector_iterator<T> it) {
		return vector_iterator<T>(&(*it) + i);
	}
}

#endif //INC_42_VECTOR_ITERATOR_HPP
