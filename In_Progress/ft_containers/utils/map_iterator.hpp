//
// Created by mlabouri on 4/19/22.
//

#ifndef INC_42_MAP_ITERATOR_HPP
#define INC_42_MAP_ITERATOR_HPP

#include "../iterators/normal_iterators.hpp"
#include "Tree.hpp"

namespace ft {
	// TODO Make iterator constructed on node instead of value_type
	template<class _t, class _tcp = _t>
	class map_iterator : public normal_bidirectional_iterator<_t> {
	private:
		typedef typename Node<_tcp>::node_pointer node_pointer;
		typedef normal_bidirectional_iterator<_t> base_iterator;
	public:
		typedef typename base_iterator::value_type value_type;
		typedef typename base_iterator::pointer pointer;
		typedef typename base_iterator::reference reference;
		typedef typename base_iterator::difference_type difference_type;
		typedef typename base_iterator::iterator_category iterator_category;

		/** Constructors */
		map_iterator(node_pointer ptr = node_pointer()) : _base(ptr) {
			isBeforeBegin = false;
			isPastTheEnd = false;
		}

		map_iterator(const map_iterator &src) { *this = src; }

		/** Destructor */
		~map_iterator() {}

		/** Members Function*/
		/** Member Operator Overloads */
		map_iterator &operator=(const map_iterator &rhs) {
			if (this == &rhs)
				return *this;
			_base = rhs._base;
			isPastTheEnd = rhs.isPastTheEnd;
			isBeforeBegin = rhs.isBeforeBegin;
			return *this;
		}

		/** prefix ++a */
		map_iterator &operator++() {
			// If you are before begin, set to begin and return
			if (isBeforeBegin) {
				isBeforeBegin = false;
				return *this;
			}

			// If you are past the end, return
			if (isPastTheEnd)
				return *this;

			node_pointer baseTmp = _base;
			_base = _base->next();

			// If no next, go past the end, return NULL pointer
			if (_base == baseTmp) {
				isPastTheEnd = true;
				return *this;
			}
			return *this;
		}

		//prefix --a
		map_iterator &operator--() {
			// If you are past the end, set to end and return
			if (isPastTheEnd) {
				isPastTheEnd = false;
				return *this;
			}

			// If you are before begin, return NULL pointer
			if (isBeforeBegin)
				return *this;

			node_pointer baseTmp = _base;
			_base = _base->prev();

			// If no prev, go before begin, return NULL pointer
			if (_base == baseTmp) {
				isBeforeBegin = true;
				return *this;
			}
			return *this;
		}


		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		const map_iterator operator++(const int) {
			// If you are before begin, set to begin and return NULL pointer
			if (isBeforeBegin) {
				isBeforeBegin = false;
				return node_pointer();
			}

			// If you are past the end, return NULL pointer
			if (isPastTheEnd)
				return node_pointer();

			map_iterator temp = *this;
			node_pointer baseTmp = _base;
			_base = _base->next();

			// If no next, set past the end, return end
			if (_base == baseTmp)
				isPastTheEnd = true;
			return temp;
		}

		// postfix a-- || int to differentiate between prefix and postfix increment operators.
		const map_iterator operator--(const int) {
			// If you are past the end, set to end and return NULL pointer
			if (isPastTheEnd) {
				isPastTheEnd = false;
				return node_pointer();
			}

			// If you are before begin, return NULL pointer
			if (isBeforeBegin)
				return node_pointer();

			map_iterator temp = *this;
			node_pointer baseTmp = _base;
			_base = _base->prev();

			// If no prev, set before begin, return begin
			if (_base == baseTmp)
				isBeforeBegin = true;
			return temp;
		}

		bool operator==(const map_iterator &rhs) const {
			if (isBeforeBegin != rhs.isBeforeBegin)
				return false;
			if (isPastTheEnd != rhs.isPastTheEnd)
				return false;
			if (isPastTheEnd || isBeforeBegin)
				return true;

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

		operator map_iterator<const _t, _t> const() {
			map_iterator<const _t, _t> ret = map_iterator<const _t, _t>(_base);
			ret.isBeforeBegin = isBeforeBegin;
			ret.isPastTheEnd = isPastTheEnd;
			return ret;
		};

		bool isBeforeBegin;
		bool isPastTheEnd;
	private:
		node_pointer _base;
	};

	template <class T>
	bool operator== (const map_iterator<T> & lhs, const map_iterator<T> & rhs) {
		if (lhs.isBeforeBegin != rhs.isBeforeBegin)
			return false;
		if (lhs.isPastTheEnd != rhs.isPastTheEnd)
			return false;
		if (lhs.isPastTheEnd || lhs.isBeforeBegin) // if they are at the same status, and one of them is true
			return true;
		return lhs.operator->() == &rhs.operator->();
	}

	template <class T>
	bool operator== (const map_iterator<const T> & lhs, const map_iterator<T> & rhs) {
		if (lhs.isBeforeBegin != rhs.isBeforeBegin)
			return false;
		if (lhs.isPastTheEnd != rhs.isPastTheEnd)
			return false;
		if (lhs.isPastTheEnd || lhs.isBeforeBegin) // if they are at the same status, and one of them is true
			return true;
		return lhs.operator->() == &rhs.operator->();
	}

	template <class T>
	bool operator== (const map_iterator<T> & lhs, const map_iterator<const T> & rhs) {
		if (lhs.isBeforeBegin != rhs.isBeforeBegin)
			return false;
		if (lhs.isPastTheEnd != rhs.isPastTheEnd)
			return false;
		if (lhs.isPastTheEnd || lhs.isBeforeBegin) // if they are at the same status, and one of them is true
			return true;
		return lhs.operator->() == &rhs.operator->();
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
