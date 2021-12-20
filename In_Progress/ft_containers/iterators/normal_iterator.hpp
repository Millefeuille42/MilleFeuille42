//
// Created by mlabouri on 12/17/21.
//

#ifndef INC_42_NORMAL_ITERATOR_HPP
#define INC_42_NORMAL_ITERATOR_HPP

#include "iterator.hpp"

/// Has no interest as is, it's just for reference when building iterators
namespace ft {
	template<typename _iT>
	class normal_iterator : public iterator<random_access_iterator_tag, _iT> {
	public:
	/** Constructors */
		normal_iterator();
		normal_iterator(const normal_iterator& src);
	/** Members Function*/
		/** Member Operator Overloads */
		normal_iterator& operator=(const normal_iterator& rhs);
			/** prefix ++a */
		normal_iterator& operator++();
			/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		normal_iterator operator++(const int);
		bool operator==(const normal_iterator& rhs) const;
		bool operator!=(const normal_iterator& rhs) const;
		_iT& operator*(); // dereference
		_iT* operator->(); // structure dereference
		normal_iterator& operator--(); //prefix --a
		normal_iterator operator--(const int); // postfix a-- || int to differentiate between prefix and postfix increment operators.
		normal_iterator operator+(normal_iterator rhs);
		normal_iterator operator-(normal_iterator rhs);
		normal_iterator operator+(const int i);
		normal_iterator operator-(const int i);
		bool operator<(const normal_iterator& rhs);
		bool operator>(const normal_iterator& rhs);
		bool operator<=(const normal_iterator& rhs);
		bool operator>=(const normal_iterator& rhs);
		normal_iterator& operator+=(normal_iterator rhs);
		normal_iterator& operator-=(normal_iterator rhs);
		normal_iterator& operator+=(const int i);
		normal_iterator& operator-=(const int i);
		normal_iterator& operator[](const unsigned int i);
	};

	template<typename _iT>
	class normal_iterator<const _iT> : public iterator<random_access_iterator_tag, _iT> {
	public:
		/** Constructors */
		normal_iterator();
		normal_iterator(normal_iterator& src);
		/** Members Function*/
		/** Member Operator Overloads */
		normal_iterator& operator=(normal_iterator& rhs);
		/** prefix ++a */
		normal_iterator& operator++();
		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		normal_iterator operator++( int);
		bool operator==(normal_iterator& rhs);
		bool operator!=(normal_iterator& rhs);
		const _iT& operator*(); // dereference
		const _iT* operator->(); // structure dereference
		normal_iterator& operator--(); //prefix --a
		normal_iterator operator--(int); // postfix a-- || int to differentiate between prefix and postfix increment operators.
		normal_iterator operator+(normal_iterator rhs);
		normal_iterator operator-(normal_iterator rhs);
		normal_iterator operator+(int i);
		normal_iterator operator-(int i);
		bool operator<(normal_iterator& rhs);
		bool operator>(normal_iterator& rhs);
		bool operator<=(normal_iterator& rhs);
		bool operator>=(normal_iterator& rhs);
		normal_iterator& operator+=(normal_iterator rhs);
		normal_iterator& operator-=(normal_iterator rhs);
		normal_iterator& operator+=(int i);
		normal_iterator& operator-=(int i);
		normal_iterator& operator[](unsigned int i);
	};
}

#endif //INC_42_NORMAL_ITERATOR_HPP
