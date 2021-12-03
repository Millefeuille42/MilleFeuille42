//
// Created by mlabouri on 12/3/21.
//

#include <iostream>
#include <list>
#include "MutantStack.hpp"

void stackMain() {
	std::stack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Front: ";
	std::cout << mstack.top() << std::endl;
	std::cout << "Size: ";
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
}

void mutantMain() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Front: ";
	std::cout << mstack.top() << std::endl;
	std::cout << "Size: ";
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Content: " << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void listMain() {
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "Front: ";
	std::cout << mstack.front() << std::endl;
	std::cout << "Size: ";
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Content: " << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main() {
	std::cout << "--- LIST ---" << std::endl;
	listMain();
	std::cout << "--- MSTACK ---" << std::endl;
	mutantMain();
	std::cout << "--- STACK ---" << std::endl;
	stackMain();
	return 0;
}
