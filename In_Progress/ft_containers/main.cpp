#include "utils/Tree.hpp"
#include "libs/utility.hpp"
#include "utils/map_iterator.hpp"
#include "map.hpp"

int main() {
	typedef ft::pair<char, int> pairType;
	typedef ft::Tree<pairType> treeType;
	typedef ft::map_iterator<pairType> itType;
	typedef ft::map<char, int> mapType;

	mapType myMap = mapType();
	treeType tst = treeType(pairType(1, 2));
	itType it = itType(tst.origin);

	tst.leftmost();
	tst.rightmost();
	tst.resetCurrent();
	tst.next();
	tst.prev();

	pairType testVal = pairType(1, 2);

	tst.append(testVal);
	tst.find(testVal);
	myMap.find('a');
}
