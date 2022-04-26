#include "map.hpp"

#define mapTest ft::map<std::string, int>

int main() {
	mapTest myMap;
	mapTest mySecondMap(myMap);

	myMap.max_size();
}
