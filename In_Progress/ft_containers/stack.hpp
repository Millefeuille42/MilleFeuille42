//
// Created by mathi on 09-Mar-22.
//

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {
	//https://www.cplusplus.com/reference/vector/vector
	template<class T, class Container = vector<T> >
	class stack {
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		explicit stack (const container_type& ctnr = container_type()) {
			c = ctnr;
		}

		bool empty() const {
			return c.empty();
		};

		size_type size() const {
			return c.size();
		}

		value_type& top() {
			return c.back();
		}

		const value_type& top() const {
			return c.back();
		}

		void push(const value_type& val) {
			c.push_back(val);
		}

		void pop() {
			c.pop_back();
		}

		bool operator== (const stack<T,Container>& rhs) const {
			return c == rhs.c;
		}

		bool operator!= (const stack<T,Container>& rhs) const {
			return c != rhs.c;
		}

		bool operator>  (const stack<T,Container>& rhs) const {
			return c > rhs.c;
		}

		bool operator< (const stack<T,Container>& rhs) const {
			return c < rhs.c;
		}

		bool operator<= (const stack<T,Container>& rhs) const {
			return c <= rhs.c;
		}

		bool operator>= (const stack<T,Container>& rhs) const {
			return c >= rhs.c;
		}

	protected:
		container_type c;
	};
}

#endif //STACK_HPP
