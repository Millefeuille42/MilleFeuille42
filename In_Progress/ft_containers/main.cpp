#include "map.hpp"

#define mapTest ft::map<std::string, int>

int main() {
	mapTest myMap;
	mapTest mySecondMap(myMap);


	mySecondMap.max_size();
	mySecondMap.swap(myMap);

	myMap.size();
	myMap.max_size();
	myMap.begin();
	myMap.end();
	myMap.rbegin();
	myMap.rend();
	myMap.get_allocator();
	myMap.clear();
	myMap.empty();
	myMap["test"];
}
