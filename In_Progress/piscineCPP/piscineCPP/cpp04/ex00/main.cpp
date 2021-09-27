//
// Created by millefeuille on 31/03/2021.
//

#include <iostream>
#include "Sorcerer.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Knight bobby("Bobby");

	std::cout << robert << jim << joe << bobby;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(bobby);
	return 0;
}