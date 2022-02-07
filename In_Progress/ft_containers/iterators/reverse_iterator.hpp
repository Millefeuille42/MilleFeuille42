//
// Created by mlabouri on 12/17/21.
//

#ifndef INC_42_REVERSE_ITERATOR_HPP
#define INC_42_REVERSE_ITERATOR_HPP

#include "normal_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {
	template<typename _iterator>
	class reverse_iterator
			: public iterator<typename iterator_traits<_iterator>::iterator_category,
					typename iterator_traits<_iterator>::value_type,
					typename iterator_traits<_iterator>::difference_type,
					typename iterator_traits<_iterator>::pointer,
					typename iterator_traits<_iterator>::reference> {
	protected:
		_iterator current;
		typedef iterator_traits<_iterator> _traits_type;

	public:
		typedef _iterator iterator_type;
		typedef typename _traits_type::iterator_category iterator_category;
		typedef typename _traits_type::value_type value_type;
		typedef typename _traits_type::difference_type difference_type;
		typedef typename _traits_type::pointer pointer;
		typedef typename _traits_type::reference reference;

		/** Constructors */
		reverse_iterator()
				: current(_iterator_type()) {}

		explicit reverse_iterator(iterator_type it)
				: current(_iterator_type(it)) {}

		template<class _iter>
		reverse_iterator(const reverse_iterator<_iter> &rev_it)
				: current(rev_it.base()) {}

		/** Destructors */
		~reverse_iterator() {}

		/** Member Functions */
		iterator_type base() const {
			return current;
		}

		reference operator*() const {
			iterator_type tmp = current;
			return *--tmp;
		};

		reverse_iterator operator+(difference_type n) const {
			return reverse_iterator(current - n);
		};

		reverse_iterator &operator++() {
			--current;
			return *this;
		};

		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
			--current;
			return tmp;
		};

		reverse_iterator &operator+=(difference_type n) {
			current -= n;
			return *this;
		};

		reverse_iterator operator-(difference_type n) const {
			return reverse_iterator(current + n);
		};

		reverse_iterator &operator--() {
			++current;
			return *this;
		};

		reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			++current;
			return *this;
		};

		reverse_iterator &operator-=(difference_type n) {
			current += n;
			return *this;
		};

		pointer operator->() const {
			_iterator tmp = current;
			--tmp;
			return tmp;
		};

		reference operator[](difference_type n) const {
			return *(*this + n);
		};
	};

	template<class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return lhs.base() == rhs.base();
	}

	template<class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return lhs.base() != rhs.base();
	}

	template<class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs) {
		return lhs.base() > rhs.base();
	}

	template<class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return lhs.base() >= rhs.base();
	}

	template<class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs) {
		return lhs.base() < rhs.base();
	}

	template<class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return lhs.base() <= rhs.base();
	}

	template<class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator> &lhs,
			const reverse_iterator<Iterator> &rhs) {
		return lhs.base() - rhs.base();
	}

	template<class Iterator>
	reverse_iterator<Iterator> operator+(
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator> &rev_it) {
		return rev_it + n;
	}
}
#endif //INC_42_REVERSE_ITERATOR_HPP
