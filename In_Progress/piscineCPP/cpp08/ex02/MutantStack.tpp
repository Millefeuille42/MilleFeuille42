//
// Created by mathi on 09-Mar-22.
//

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#define MSTACK MutantStack<type>
#define MSTACK_TEMPLATE template <class type>
#define MSTACK_TYPE typename MSTACK::

MSTACK_TEMPLATE
MSTACK::MutantStack(): std::stack<type>() {}

MSTACK_TEMPLATE
MSTACK::MutantStack(const MSTACK& src) {*this = src;}

MSTACK_TEMPLATE
MSTACK::~MutantStack() {}

MSTACK_TEMPLATE
MSTACK& MSTACK::operator=(const MSTACK& rhs) {
	this->c = rhs.c;
	return (*this);
}

MSTACK_TEMPLATE
MSTACK_TYPE iterator MSTACK::begin() {
	return this->c.begin();
}

MSTACK_TEMPLATE
MSTACK_TYPE iterator MSTACK::end() {
	return this->c.end();
}

#endif //MUTANTSTACK_TPP
