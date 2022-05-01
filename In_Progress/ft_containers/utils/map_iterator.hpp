//
// Created by mlabouri on 4/19/22.
//

#ifndef INC_42_MAP_ITERATOR_HPP
#define INC_42_MAP_ITERATOR_HPP

#include "../iterators/normal_iterators.hpp"
#include "Tree.hpp"

namespace ft {
	template<class _t>
	class map_iterator : public normal_bidirectional_iterator<_t> {
	private:
		typedef typename Node<_t>::node_pointer node_pointer;
		typedef normal_bidirectional_iterator<_t> base_iterator;
	public:
		typedef typename base_iterator::value_type value_type;
		typedef typename base_iterator::pointer pointer;
		typedef typename base_iterator::reference reference;
		typedef typename base_iterator::difference_type difference_type;
		typedef typename base_iterator::iterator_category iterator_category;

		/** Constructors */
		map_iterator(node_pointer ptr = node_pointer()) : _base(ptr) {}

		map_iterator(const map_iterator &src) { *this = src; }

		/** Destructor */
		~map_iterator() {}

		/** Members Function*/
		/** Member Operator Overloads */
		map_iterator &operator=(const map_iterator &rhs) {
			if (this == &rhs)
				return *this;
			_base = rhs._base;
			return *this;
		}

		/** prefix ++a */
		map_iterator &operator++() {
			_base = _base->next();
			return *this;
		}

		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		const map_iterator operator++(const int) {
			map_iterator temp = *this;
			_base = _base->next();
			return temp;
		}

		bool operator==(const map_iterator &rhs) const {
			return _base == rhs._base;
		}

		bool operator!=(const map_iterator &rhs) const {
			return !(*this == rhs);
		}

		reference operator*() {
			return _base->data;
		} // dereference

		const reference operator*() const {
			return _base->data;
		} // dereference

		pointer operator->() {
			return &_base->data;
		} // structure dereference

		const pointer operator->() const {
			return &_base->data;
		} // structure dereference

		map_iterator &operator--() {
			_base = _base->prev();
			return *this;
		} //prefix --a

		const map_iterator operator--(const int) {
			map_iterator temp = *this;
			_base = _base->prev();
			return temp;
		} // postfix a-- || int to differentiate between prefix and postfix increment operators.

	private:
		node_pointer _base;
	};

	template <class T>
	bool operator== (const map_iterator<T> & lhs, const map_iterator<T> & rhs) {
		return lhs._base.operator->() == &rhs.operator->();
	}

	template <class T>
	bool operator== (const map_iterator<const T> & lhs, const map_iterator<T> & rhs) {
		return lhs._base.operator->() == &rhs.operator->();
	}

	template <class T>
	bool operator== (const map_iterator<T> & lhs, const map_iterator<const T> & rhs) {
		return lhs._base.operator->() == &rhs.operator->();
	}

	template <class T>
	bool operator!= (const map_iterator<T> & lhs, const map_iterator<T> & rhs) {
		return !(lhs == rhs);
	}

	template <class T>
	bool operator!= (const map_iterator<const T> & lhs, const map_iterator<T> & rhs) {
		return !(lhs == rhs);
	}

	template <class T>
	bool operator!= (const map_iterator<T> & lhs, const map_iterator<const T> & rhs) {
		return !(lhs == rhs);
	}
}

#endif //INC_42_MAP_ITERATOR_HPP
