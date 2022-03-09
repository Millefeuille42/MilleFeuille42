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

	MutantStack();

	MutantStack(const MutantStack& src);

	~MutantStack();

	MutantStack& operator=(const MutantStack& rhs);

	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"

#endif //INC_42_MUTANTSTACK_HPP
