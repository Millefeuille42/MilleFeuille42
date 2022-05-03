#include <iostream>
#include "utils/Tree.hpp"
#include "libs/utility.hpp"
#include "utils/map_iterator.hpp"
#include "map.hpp"
#include <map>

#define NS ft

typedef NS::map<char, int> mapType;

void printIt(mapType::iterator it) {
	std::cout << '(' << it.operator->() << ") " << it->first << " -> " << it->second << std::endl;
}

void printEmpty(bool b) {
	if (b)
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Filled" << std::endl;
}

void printSize(mapType::size_type i) {
	std::cout << "Size: " << i << std::endl;
}

void printCount(mapType::size_type i) {
	std::cout << "Found " << i << std::endl;
}

void printVal(mapType::size_type i) {
	std::cout << "Val:  " << i << std::endl;
}

int main() {

	mapType myMap = mapType();

	std::cout << "--- Testing Insert ---" << std::endl;
	printSize( myMap.size() ); // Expecting -> 0
	printIt( myMap.insert(NS::make_pair('c', 42)).first ); // Expecting -> 42
	printIt( myMap.insert(NS::make_pair('a', 48)).first ); // Expecting -> 48
	printIt( myMap.insert(myMap.find('e'), NS::make_pair('b', 41)) ); // Expecting -> 41
	printIt( myMap.insert(NS::make_pair('d', 40)).first ); // Expecting -> 40
	std::cout << "--- Testing Find ---" << std::endl;
	printIt( myMap.find('a') ); // Expecting -> 48
	printIt( myMap.find('e') ); // Expecting -> 40

	std::cout << "--- Testing Count ---" << std::endl;
	printCount( myMap.count('c') ); // Expecting -> 1
	printCount( myMap.count('f') ); // Expecting -> 0

	std::cout << "--- Testing [] ---" << std::endl;
	myMap['a'] = 12;
	myMap['e'] = 48;
	myMap['e'] = 49;
	printVal( myMap['a'] ); // Expecting -> 12
	printIt( myMap.find('e') ); // Expecting -> 49

	std::cout << "--- Testing Empty And Size ---" << std::endl;
	printEmpty( myMap.empty() ); // Expecting -> Filled
	printSize( myMap.size() ); // Expecting -> 5
	myMap.get_allocator();
	myMap.max_size();
	myMap.value_comp();
	myMap.key_comp();

	//mapType mySecondMap(myMap);


	//printIt( mySecondMap.find('e') ); // Expecting -> 49
	//printIt( mySecondMap.insert(NS::make_pair('f', 1)).first ); // Expecting -> 1
	//printIt( mySecondMap.insert(NS::make_pair('e', 1000)).first ); // Expecting -> 49
	//printIt( mySecondMap.find('e') ); // Expecting -> 49
	//printIt( myMap.find('f') ); // Expecting -> 49

	std::cout << "--- Testing Clear ---" << std::endl;
	myMap.clear();
	printEmpty( myMap.empty() ); // Expecting -> Empty
	printSize( myMap.size() ); // Expecting -> 0
}
