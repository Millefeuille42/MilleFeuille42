// ### INCLUDES ### //
#include <iostream>
#include <cstdlib>

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

typedef int testedType;
typedef char keyType;

#ifndef SEED
# define SEED time(NULL)
#endif

#define R_NUM rand() % 1250 + 1
#define R_CHAR rand()%('z'-'a' + 1) + 'a'

// ### TYPEDEF ### //

typedef NAMESPACE::pair<const keyType, testedType> CPairType;
typedef NAMESPACE::map<keyType, testedType> mapType;
__attribute__((unused)) typedef NAMESPACE::vector<testedType> vectorType;
typedef NAMESPACE::stack<testedType> stackType;

// ### PRINT FUNCTIONS ### //

template <class val> void printValue(const val value) {
	std::cout << value << std::endl;
}

template <> void printValue<CPairType>(CPairType value) {
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
	for (testedType val = cpy.top(); !cpy.empty(); cpy.pop()) {
		val = cpy.top();
		std::cout << val << std::endl;
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

void doTestsOnVector(vectorType & myVector) {
	myVector.push_back(R_NUM);
	myVector.push_back(R_NUM);
	myVector.push_back(R_NUM);
	myVector.push_back(R_NUM);
	myVector.push_back(R_NUM);
	printValue( *myVector.insert(myVector.begin() + 2, R_NUM) );
	myVector.insert(myVector.begin() + 2, 42, R_NUM);
	myVector.insert(myVector.begin() + 2, myVector.begin(),myVector.end());
	printValue( *myVector.erase(myVector.begin() + 2) );
	printValue( *myVector.erase(myVector.begin() + 5, myVector.end() - 2) );
	printValue( myVector.at(5) );
	printValue( myVector[5] );
	myVector.pop_back();
	myVector.pop_back();
	myVector.push_back(R_NUM);
	myVector.push_back(R_NUM);
	printValue(myVector.front());
	printValue(myVector.back());
	myVector.assign(42, R_NUM);
	vectorType a = vectorType(454, R_NUM);
	myVector.assign(a.begin(), a.end());
}

void vectorTest() {
	vectorType myVoidVector;
	vectorType myDefaultVector = vectorType();
	vectorType myAllocatedVector(12);
	vectorType myFillVector(12, R_NUM);

	doTestsOnVector(myVoidVector);
	doTestsOnVector(myDefaultVector);
	doTestsOnVector(myAllocatedVector);
	doTestsOnVector(myFillVector);

	vectorType myCopyVector = vectorType(myVoidVector);
	myCopyVector.push_back(R_NUM);
	vectorType myEmptyVector = vectorType();
	vectorType myRangeVector = vectorType(myVoidVector.begin(), myVoidVector.end());

	std::cout << "### Rel. Op. ###" << std::endl;
	std::cout << "# Testing when == #" << std::endl;
	printRel(myVoidVector, myRangeVector);

	std::cout << "# Testing when != #" << std::endl;
	printRel(myVoidVector, myCopyVector);

	std::cout << "# Testing when one is empty #" << std::endl;
	printRel(myEmptyVector, myFillVector);

	swap(myCopyVector, myAllocatedVector);
	myVoidVector.resize(5, R_NUM);

	printContainer(myVoidVector);
	printContainer(myDefaultVector);
	printContainer(myAllocatedVector);
	printContainer(myFillVector);
	printContainer(myCopyVector);
	printContainer(myEmptyVector);
}

void doTestsOnMap(mapType & myMap) {
	printValue( *myMap.insert(NAMESPACE::make_pair('c', R_NUM)).first );
	printValue( *myMap.insert(myMap.begin(), NAMESPACE::make_pair(R_CHAR, 4)) );
	printValue( *myMap.insert(NAMESPACE::make_pair('c', R_NUM)).first);
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	myMap.insert(myMap.begin(), myMap.end());
	myMap.insert(myMap.begin(), --myMap.end());
	printValue(myMap.count('c'));
	printValue(myMap.count('r'));
	printValue(myMap.count('G'));
	printValue(*myMap.find('c'));
	printValue(*myMap.find('r'));
	printValue(*myMap.find('G'));
	myMap.erase('c');
	myMap.erase(--myMap.end());
	myMap.erase(myMap.begin(), myMap.end());
	printValue( *myMap.insert(NAMESPACE::make_pair('c', R_NUM)).first);
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	myMap.clear();
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	printValue( *myMap.insert(NAMESPACE::make_pair(R_CHAR, R_NUM)).first );
	myMap.insert(myMap.begin(), myMap.end());
	printValue( (myMap['W'] = R_NUM) );
	printValue( myMap[R_CHAR] );
	printValue( *myMap.upper_bound(R_CHAR) );
	printValue( *myMap.upper_bound(R_CHAR) );
	printValue( *myMap.lower_bound(R_CHAR) );
	printValue( *myMap.lower_bound(R_CHAR) );
	printValue( *myMap.equal_range(R_CHAR).first );
	printValue( *myMap.equal_range(R_CHAR).first );
	printValue( *myMap.equal_range(R_CHAR).second );
	printValue( *myMap.equal_range(R_CHAR).second );
}

void mapTest() {
	mapType myVoidMap;
	mapType myDefaultMap = mapType();

	doTestsOnMap(myVoidMap);
	doTestsOnMap(myDefaultMap);

	mapType myCopyMap = mapType(myVoidMap);
	mapType myEmptyMap = mapType();
	mapType myRangeMap = mapType(myVoidMap.begin(), myVoidMap.end());
	doTestsOnMap(myCopyMap);
	doTestsOnMap(myRangeMap);
	myCopyMap.erase(myCopyMap.begin()++);

	std::cout << "### Rel. Op. ###" << std::endl;
	std::cout << "# Testing when == #" << std::endl;
	printRel(myVoidMap, myDefaultMap);

	std::cout << "# Testing when != #" << std::endl;
	printRel(myVoidMap, myCopyMap);

	std::cout << "# Testing when one is empty #" << std::endl;
	printRel(myEmptyMap, myDefaultMap);

	printContainer(myVoidMap);
	printContainer(myDefaultMap);
	printContainer(myCopyMap);
	printContainer(myRangeMap);
	printContainer(myEmptyMap);
}

void doTestsOnStack(stackType & myStack) {
	myStack.push(R_NUM);
	myStack.push(R_NUM);
	myStack.push(R_NUM);
	myStack.push(R_NUM);
	myStack.push(R_NUM);
	myStack.pop();
	myStack.pop();
	myStack.push(R_NUM);
}

void stackTest() {
	stackType myVoidStack;
	stackType myDefaultStack = stackType();

	doTestsOnStack(myVoidStack);
	doTestsOnStack(myDefaultStack);

	stackType myCopyStack = stackType(myVoidStack);
	myCopyStack.push(R_NUM);
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
	srand(SEED);

	std::cout << "/// VECTOR ///" << std::endl;
	vectorTest();
	std::cout << "/// MAP ///" << std::endl;
	mapTest();
	std::cout << "/// STACK ///" << std::endl;
	stackTest();
	return 0;
}
