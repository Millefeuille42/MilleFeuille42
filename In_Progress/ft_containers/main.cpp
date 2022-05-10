// ### INCLUDES ### //
#include <iostream>

#ifdef NAMESPACE

# include <vector>
# include <stack>
# include <map>

#else

# define NAMESPACE ft

# include "vector.hpp"
# include "stack.hpp"
# include "map.hpp"

#endif

// ### DEFINE ### //

#ifndef TESTED_VAL_TYPE
	typedef int testedType;
#else
	typedef TESTED_VAL_TYPE keyType;
#endif

#ifndef TESTED_KEY_TYPE
	typedef char keyType;
#else
	typedef TESTED_KEY_TYPE keyType;
#endif

// ### TYPEDEF ### //

typedef NAMESPACE::pair<keyType, testedType> pairType;
typedef NAMESPACE::map<keyType, testedType> mapType;
__attribute__((unused)) typedef NAMESPACE::vector<testedType> vectorType;
typedef NAMESPACE::stack<testedType> stackType;

// ### PRINT FUNCTIONS ### //

template <class val> void printValue(const val value) {
	std::cout << value << std::endl;
}

template <> void printValue(const pairType value) {
	std::cout << value.first << " -> " << value.second << std::endl;
}

template <class container>
void printRel(const container & lhs, const container & rhs) {
	std::cout << "== ";
	std::cout << (lhs == rhs) << std::endl;
	std::cout << "!= ";
	std::cout << (lhs != rhs) << std::endl;
	std::cout << "> ";
	std::cout << (lhs > rhs) << " | ";
	std::cout << (rhs > lhs) << std::endl;
	std::cout << "< ";
	std::cout << (lhs < rhs) << " | ";
	std::cout << (rhs < lhs) << std::endl;
	std::cout << ">= ";
	std::cout << (lhs >= rhs) << " | ";
	std::cout << (rhs >= lhs) << std::endl;
	std::cout << "<= ";
	std::cout << (lhs <= rhs) << " | ";
	std::cout << (rhs <= lhs) << std::endl;
}

template <class container> void printContent(const container & ctr) {
	typedef typename container::const_iterator cit;
	for (cit b = ctr.begin(); b != ctr.end(); b++)
		printValue(*b);
}

template <> void printContent<stackType>(const stackType & stack) {
	stackType cpy = stack;
	for (testedType val = cpy.top(); !cpy.empty(); val = cpy.top()) {
		std::cout << val << std::endl;
		cpy.pop();
	}
}

template <class container> void printSize(const container & ctr) {
	std::cout << "Empty: ";
	if (ctr.empty())
		std::cout << "True ";
	else
		std::cout << "False ";
	std::cout << "Size: " << ctr.size() << std::endl;

	if (ctr.empty() && ctr.size() > 0)
		std::cout << "Container says it's empty but has a non 0 size"
				  << std::endl;
	else if (!ctr.empty() && ctr.size() <= 0)
		std::cout << "Container says it's not empty but has 0 size"
				  << std::endl;
}

template <class container> void printContainer(const container & ctr) {
	std::cout << "###############" << std::endl;
	std::cout << "# Size #" << std::endl;
	printSize(ctr);
	if (!ctr.empty()) {
		std::cout << "# Content #" << std::endl;
		printContent(ctr);
	}
}

void vectorTest() {
	vectorType myVoidVector;
	vectorType myDefaultVector = vectorType();
	vectorType myAllocatedVector(12);
	vectorType myFillVector(12, 42);

	std::cout << "### I/O ###" << std::endl;

	myVoidVector.push_back(1);
	myVoidVector.push_back(2);
	myVoidVector.push_back(3);
	myVoidVector.push_back(4);
	myVoidVector.push_back(5);
	printValue( *myVoidVector.insert(myVoidVector.begin() + 2, 42) );
	myVoidVector.insert(myVoidVector.begin() + 2, 42, 12);
	myVoidVector.insert(myVoidVector.begin() + 2, myVoidVector.begin(),myVoidVector.end());
	printValue( *myVoidVector.erase(myVoidVector.begin() + 2) );
	printValue( *myVoidVector.erase(myVoidVector.begin() + 5, myVoidVector.end() - 2) );
	printValue( myVoidVector.at(5) );
	printValue( myVoidVector[5] );
	printValue( myVoidVector.capacity() );
	myVoidVector.pop_back();
	myVoidVector.pop_back();
	myVoidVector.push_back(4);
	myVoidVector.push_back(5);
	myVoidVector.assign(42, 76);
	{
		vectorType a = vectorType(454, 42);
		myVoidVector.assign(a.begin(), a.end());
	}

	myDefaultVector.push_back(1);
	myDefaultVector.push_back(2);
	myDefaultVector.push_back(3);
	myDefaultVector.push_back(4);
	myDefaultVector.push_back(5);
	printValue( *myDefaultVector.insert(myDefaultVector.begin() + 2, 42) );
	myDefaultVector.insert(myDefaultVector.begin() + 2, 42, 12);
	myDefaultVector.insert(myDefaultVector.begin() + 2, myDefaultVector.begin(),myDefaultVector.end());
	printValue( *myDefaultVector.erase(myDefaultVector.begin() + 2) );
	printValue( *myDefaultVector.erase(myDefaultVector.begin() + 5, myDefaultVector.end() - 2) );
	printValue( myDefaultVector.at(5) );
	printValue( myDefaultVector[5] );
	printValue( myDefaultVector.capacity() );
	myDefaultVector.pop_back();
	myDefaultVector.pop_back();
	myDefaultVector.push_back(4);
	myDefaultVector.push_back(5);
	myDefaultVector.assign(42, 76);
	{
		vectorType a = vectorType(454, 42);
		myDefaultVector.assign(a.begin(), a.end());
	}

	myAllocatedVector.push_back(1);
	myAllocatedVector.push_back(2);
	myAllocatedVector.push_back(3);
	myAllocatedVector.push_back(4);
	myAllocatedVector.push_back(5);
	printValue( *myAllocatedVector.insert(myAllocatedVector.begin() + 2, 42) );
	myAllocatedVector.insert(myAllocatedVector.begin() + 2, 42, 12);
	myAllocatedVector.insert(myAllocatedVector.begin() + 2, myAllocatedVector.begin(),myAllocatedVector.end());
	printValue( *myAllocatedVector.erase(myAllocatedVector.begin() + 2) );
	printValue( *myAllocatedVector.erase(myAllocatedVector.begin() + 5, myAllocatedVector.end() - 2) );
	printValue( myAllocatedVector.at(5) );
	printValue( myAllocatedVector[5] );
	printValue( myAllocatedVector.capacity() );
	myAllocatedVector.pop_back();
	myAllocatedVector.pop_back();
	myAllocatedVector.push_back(4);
	myAllocatedVector.push_back(5);
	myAllocatedVector.assign(42, 76);
	{
		vectorType a = vectorType(454, 42);
		myAllocatedVector.assign(a.begin(), a.end());
	}

	myFillVector.push_back(1);
	myFillVector.push_back(2);
	myFillVector.push_back(3);
	myFillVector.push_back(4);
	myFillVector.push_back(5);
	printValue( *myFillVector.insert(myFillVector.begin() + 2, 42) );
	myFillVector.insert(myFillVector.begin() + 2, 42, 12);
	myFillVector.insert(myFillVector.begin() + 2, myFillVector.begin(),myFillVector.end());
	printValue( *myFillVector.erase(myFillVector.begin() + 2) );
	printValue( *myFillVector.erase(myFillVector.begin() + 5, myFillVector.end() - 2) );
	printValue( myFillVector.at(5) );
	printValue( myFillVector[5] );
	printValue( myFillVector.capacity() );
	myFillVector.pop_back();
	myFillVector.pop_back();
	myFillVector.push_back(4);
	myFillVector.push_back(5);
	myFillVector.assign(42, 76);
	{
		vectorType a = vectorType(454, 42);
		myFillVector.assign(a.begin(), a.end());
	}

	vectorType myCopyVector = vectorType(myVoidVector);
	myCopyVector.push_back(5);
	vectorType myEmptyVector = vectorType();

	std::cout << "### Rel. Op. ###" << std::endl;
	std::cout << "# Testing when == #" << std::endl;
	printRel(myVoidVector, myFillVector);

	std::cout << "# Testing when != #" << std::endl;
	printRel(myVoidVector, myCopyVector);

	std::cout << "# Testing when one is empty #" << std::endl;
	printRel(myEmptyVector, myFillVector);

	printContainer(myVoidVector);
	printContainer(myDefaultVector);
	printContainer(myAllocatedVector);
	printContainer(myFillVector);
	printContainer(myCopyVector);
	printContainer(myEmptyVector);
}

void mapTest() {
	mapType myVoidMap;
	mapType myDefaultMap = mapType();

	std::cout << "### I/O ###" << std::endl;

	mapType myCopyMap = mapType(myVoidMap);
	mapType myEmptyMap = mapType();

	std::cout << "### Rel. Op. ###" << std::endl;
	std::cout << "# Testing when == #" << std::endl;

	std::cout << "# Testing when != #" << std::endl;

	std::cout << "# Testing when one is empty #" << std::endl;
}

void stackTest() {
	stackType myVoidStack;
	stackType myDefaultStack = stackType();

	std::cout << "### I/O ###" << std::endl;
	myDefaultStack.push(1);
	myDefaultStack.push(2);
	myDefaultStack.push(3);
	myDefaultStack.push(4);
	myDefaultStack.push(5);

	myVoidStack.push(1);
	myVoidStack.push(2);
	myVoidStack.push(3);
	myVoidStack.push(4);
	myVoidStack.push(5);

	myDefaultStack.pop();
	myDefaultStack.pop();
	myDefaultStack.push(4);

	myVoidStack.pop();
	myVoidStack.pop();
	myVoidStack.push(4);

	stackType myCopyStack = stackType(myVoidStack);
	myCopyStack.push(5);
	stackType myEmptyStack = stackType();

	std::cout << "### Rel. Op. ###" << std::endl;
	std::cout << "# Testing when == #" << std::endl;
	printRel(myVoidStack, myDefaultStack);

	std::cout << "# Testing when != #" << std::endl;
	printRel(myVoidStack, myCopyStack);

	std::cout << "# Testing when one is empty #" << std::endl;
	printRel(myEmptyStack, myDefaultStack);

	printContainer(myDefaultStack);
	printContainer(myVoidStack);
	printContainer(myCopyStack);
	printContainer(myEmptyStack);
}

int main() {
	vectorTest();
	//mapTest();
	//stackTest();
	return 0;
}
