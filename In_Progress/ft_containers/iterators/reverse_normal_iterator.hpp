//
// Created by mlabouri on 12/17/21.
//

#ifndef INC_42_REVERSE_NORMAL_ITERATOR_HPP
#define INC_42_REVERSE_NORMAL_ITERATOR_HPP

#include "normal_iterator.hpp"

namespace ft {
	template<typename _iT>
	class reverse_normal_iterator : public normal_iterator<_iT> {
	private:
		typedef normal_iterator<_iT> base_iT;
	public:
		/** prefix ++a */
		base_iT& operator++();
		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		base_iT operator++(int);
		base_iT& operator--(); //prefix --a
		base_iT operator--(int); // postfix a-- || int to differentiate between prefix and postfix increment operators.
		base_iT operator+(base_iT rhs);
		base_iT operator-(base_iT rhs);
		base_iT operator+(int i);
		base_iT operator-(int i);
		base_iT& operator+=(base_iT rhs);
		base_iT& operator-=(base_iT rhs);
		base_iT& operator+=(int i);
		base_iT& operator-=(int i);
		base_iT& operator[](unsigned int i);
	};

	template<typename _iT>
	class reverse_normal_iterator<const _iT> : public normal_iterator<_iT> {
	private:
		typedef normal_iterator<_iT> base_iT;
	public:
		/** prefix ++a */
		base_iT& operator++();
		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		base_iT operator++(int);
		base_iT& operator--(); //prefix --a
		base_iT operator--(int); // postfix a-- || int to differentiate between prefix and postfix increment operators.
		base_iT operator+(base_iT rhs);
		base_iT operator-(base_iT rhs);
		base_iT operator+(int i);
		base_iT operator-(int i);
		base_iT& operator+=(base_iT rhs);
		base_iT& operator-=(base_iT rhs);
		base_iT& operator+=(int i);
		base_iT& operator-=(int i);
		base_iT& operator[](unsigned int i);
	};
}

#endif //INC_42_REVERSE_NORMAL_ITERATOR_HPP
