//
// Created by mlabouri on 12/17/21.
//

#ifndef INC_42_NORMAL_ITERATOR_HPP
#define INC_42_NORMAL_ITERATOR_HPP

#include "iterator.hpp"
#include "iterator_traits.hpp"

/// Has no interest as is, it's just for reference when building iterators
namespace ft {
	template<typename _iT>
class normal_iterator : public iterator<typename iterator_traits<_iT>::iterator_category, typename iterator_traits<_iT>::value_type> {
	public:
	/** Constructors */
		normal_iterator() {};
		normal_iterator(const normal_iterator& src) {};
	/** Destructor */
		~normal_iterator() {};
	/** Members Function*/
		/** Member Operator Overloads */
		normal_iterator& operator=(const normal_iterator& rhs) {};
			/** prefix ++a */
		virtual normal_iterator& operator++() {};
			/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		virtual normal_iterator operator++(const int) {};
		virtual bool operator==(const normal_iterator& rhs) const {};
		virtual bool operator!=(const normal_iterator& rhs) const {};
		virtual _iT& operator*() {}; // dereference
		virtual _iT* operator->() {}; // structure dereference
		virtual normal_iterator& operator--() {}; //prefix --a
		virtual normal_iterator operator--(const int) {}; // postfix a-- || int to differentiate between prefix and postfix increment operators.
		virtual normal_iterator operator+(normal_iterator rhs) {};
		virtual normal_iterator operator-(normal_iterator rhs) {};
		virtual normal_iterator operator+(const int i) {};
		virtual normal_iterator operator-(const int i) {};
		virtual bool operator<(const normal_iterator& rhs) {};
		virtual bool operator>(const normal_iterator& rhs) {};
		virtual bool operator<=(const normal_iterator& rhs) {};
		virtual bool operator>=(const normal_iterator& rhs) {};
		virtual normal_iterator& operator+=(normal_iterator rhs) {};
		virtual normal_iterator& operator-=(normal_iterator rhs) {};
		virtual normal_iterator& operator+=(const int i) {};
		virtual normal_iterator& operator-=(const int i) {};
		virtual normal_iterator& operator[](const unsigned int i) {};
	};

	template<typename _iT>
	class normal_iterator<const _iT> : public iterator<random_access_iterator_tag, _iT> {
	public:
		/** Constructors */
		normal_iterator() {};
		normal_iterator(normal_iterator& src) {};
		/** Destructor */
		~normal_iterator() {};
		/** Members Function*/
		/** Member Operator Overloads */
		normal_iterator& operator=(normal_iterator const& rhs) {};
		/** prefix ++a */
		virtual normal_iterator& operator++() {};
		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		virtual normal_iterator operator++(int) {};
		virtual bool operator==(normal_iterator& rhs) {};
		virtual bool operator!=(normal_iterator& rhs) {};
		virtual const _iT& operator*() {}; // dereference
		virtual const _iT* operator->() {}; // structure dereference
		virtual normal_iterator& operator--() {}; //prefix --a
		virtual normal_iterator operator--(int) {}; // postfix a-- || int to differentiate between prefix and postfix increment operators.
		virtual normal_iterator operator+(normal_iterator rhs) {};
		virtual normal_iterator operator-(normal_iterator rhs) {};
		virtual normal_iterator operator+(int i) {};
		virtual normal_iterator operator-(int i) {};
		virtual bool operator<(normal_iterator& rhs) {};
		virtual bool operator>(normal_iterator& rhs) {};
		virtual bool operator<=(normal_iterator& rhs) {};
		virtual bool operator>=(normal_iterator& rhs) {};
		virtual normal_iterator& operator+=(normal_iterator rhs) {};
		virtual normal_iterator& operator-=(normal_iterator rhs) {};
		virtual normal_iterator& operator+=(int i) {};
		virtual normal_iterator& operator-=(int i) {};
		virtual normal_iterator& operator[](unsigned int i) {};
		//TODO Add Member Functions
	};
}

#endif //INC_42_NORMAL_ITERATOR_HPP
