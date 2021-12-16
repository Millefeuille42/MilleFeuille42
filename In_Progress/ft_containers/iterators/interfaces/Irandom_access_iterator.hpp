//
// Created by mlabouri on 12/16/21.
//

#ifndef INC_42_IRANDOM_ACCESS_ITERATOR_HPP
#define INC_42_IRANDOM_ACCESS_ITERATOR_HPP

#include "../iterator.hpp"
#include "../iterator_tags.hpp"

namespace ft {
	template <typename T>
	class Irandom_access_iterator : public ft::iterator<random_access_iterator_tag, T> {
	public:
		/** Constructors */
		Irandom_access_iterator();
		Irandom_access_iterator(const Irandom_access_iterator& src);
		/** Members Function*/
		/** Member Operator Overloads */
		Irandom_access_iterator& operator=(const Irandom_access_iterator& rhs);
		/** prefix ++a */
		Irandom_access_iterator& operator++();
		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		Irandom_access_iterator operator++(int);
		bool operator==(const Irandom_access_iterator& rhs) const;
		bool operator!=(const Irandom_access_iterator& rhs) const;
		Irandom_access_iterator& operator*(); // dereference
		Irandom_access_iterator* operator->(); // structure dereference
		Irandom_access_iterator& operator--(); //prefix --a
		Irandom_access_iterator operator--(int); // postfix a-- || int to differentiate between prefix and postfix increment operators.
		Irandom_access_iterator operator+(Irandom_access_iterator rhs);
		Irandom_access_iterator operator-(Irandom_access_iterator rhs);
		Irandom_access_iterator operator+(int i);
		Irandom_access_iterator operator-(int i);
		bool operator<(const Irandom_access_iterator& rhs);
		bool operator>(const Irandom_access_iterator& rhs);
		bool operator<=(const Irandom_access_iterator& rhs);
		bool operator>=(const Irandom_access_iterator& rhs);
		Irandom_access_iterator& operator+=(Irandom_access_iterator rhs);
		Irandom_access_iterator& operator-=(Irandom_access_iterator rhs);
		Irandom_access_iterator& operator+=(int i);
		Irandom_access_iterator& operator-=(int i);
		Irandom_access_iterator& operator[](unsigned int i);
	};
}

#endif //INC_42_IRANDOM_ACCESS_ITERATOR_HPP
