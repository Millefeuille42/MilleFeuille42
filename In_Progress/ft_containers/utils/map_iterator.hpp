//
// Created by mlabouri on 4/19/22.
//

#ifndef INC_42_MAP_ITERATOR_HPP
#define INC_42_MAP_ITERATOR_HPP

#include "../iterators/normal_iterators.hpp"
#include "tree.hpp"
#include "../map.hpp"

namespace ft {
	template<class _t, class Container = map<_t, _t>, class Compare = ft::less<typename Container::value_type> >
	class map_iterator : public normal_bidirectional_iterator<_t> {
	public:
		typedef typename map_iterator<_t>::iterator::value_type value_type;
		typedef typename map_iterator<_t>::iterator::pointer pointer;
		typedef typename map_iterator<_t>::iterator::reference reference;
		typedef typename map_iterator<_t>::iterator::difference_type difference_type;
		typedef typename map_iterator<_t>::iterator::iterator_category iterator_category;

	private:
		typedef tree<Container, Compare> _tree;

	public:
		/** Constructors */
		map_iterator(_tree t = _tree()) : _base(t) {}

		map_iterator(const map_iterator &src) {
			*this = src;
		}

		/** Destructor */
		~map_iterator() {}

		/** Members Function*/
		/** Member Operator Overloads */
		map_iterator &operator=(const map_iterator &rhs) {
			if (this == &rhs)
				return ;
			_base = rhs._base;
			return *this;
		}

		/** prefix ++a */
		map_iterator &operator++() {
			_base->next();
			return *this;
		}

		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		const map_iterator operator++(const int) {
			map_iterator temp = *this;
			_base->next();
			return temp;
		}

		bool operator==(const map_iterator &rhs) const {
			if ((_base.pastTheEnd && rhs._base.pastTheEnd) || (_base.beforeBegin && rhs._base.beforeBegin))
				return true;
			if (_base.beforeBegin != rhs._base.beforeBegin || _base.pastTheEnd != rhs._base.pastTheEnd)
				return false;

			return _base.operator->() == &rhs.operator->();
		}

		bool operator!=(const map_iterator &rhs) const {
			return !(*this == rhs);
		}

		reference operator*() {
			return *_base;
		} // dereference

		const reference operator*() const {
			return *_base;
		} // dereference

		pointer operator->() {
			return _base.operator->();
		} // structure dereference

		const pointer operator->() const {
			return _base.operator->();
		} // structure dereference

		map_iterator &operator--() {
			_base->prev();
			return *this;
		} //prefix --a

		const map_iterator operator--(const int) {
			map_iterator temp = *this;
			_base->prev();
			return temp;
		} // postfix a-- || int to differentiate between prefix and postfix increment operators.

	private:
		_tree _base;
	};

	template <class T>
	bool operator== (const map_iterator<T> & lhs, const map_iterator<T> & rhs) {
		if ((lhs._base.pastTheEnd && rhs._base.pastTheEnd) || (lhs._base.beforeBegin && rhs._base.beforeBegin))
			return true;
		if (lhs._base.beforeBegin != rhs._base.beforeBegin || lhs._base.pastTheEnd != rhs._base.pastTheEnd)
			return false;

		return lhs._base.operator->() == &rhs.operator->();
	}

	template <class T>
	bool operator== (const map_iterator<const T> & lhs, const map_iterator<T> & rhs) {
		if ((lhs._base.pastTheEnd && rhs._base.pastTheEnd) || (lhs._base.beforeBegin && rhs._base.beforeBegin))
			return true;
		if (lhs._base.beforeBegin != rhs._base.beforeBegin || lhs._base.pastTheEnd != rhs._base.pastTheEnd)
			return false;

		return lhs._base.operator->() == &rhs.operator->();
	}

	template <class T>
	bool operator== (const map_iterator<T> & lhs, const map_iterator<const T> & rhs) {
		if ((lhs._base.pastTheEnd && rhs._base.pastTheEnd) || (lhs._base.beforeBegin && rhs._base.beforeBegin))
			return true;
		if (lhs._base.beforeBegin != rhs._base.beforeBegin || lhs._base.pastTheEnd != rhs._base.pastTheEnd)
			return false;

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
