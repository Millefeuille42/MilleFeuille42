//
// Created by mlabouri on 12/3/21.
//

#ifndef INC_42_MUTANTSTACK_HPP
#define INC_42_MUTANTSTACK_HPP


#include <stack>

template <class type>
class MutantStack : public std::stack<type> {
public:
	typedef typename std::deque<type>::iterator iterator;

	MutantStack(): std::stack<type>() {}

	MutantStack(const MutantStack& src) {*this = src;}

	~MutantStack() {}

	MutantStack& operator=(const MutantStack& rhs) {
		this->c = rhs.c;
		return (*this);
	}

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}
};


#endif //INC_42_MUTANTSTACK_HPP
