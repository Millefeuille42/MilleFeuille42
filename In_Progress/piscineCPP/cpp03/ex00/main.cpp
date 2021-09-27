//
// Created by millefeuille on 25/03/2021.
//

#include "ClapTrap.hpp"

int main() {
	ClapTrap bobby("Bobby");
	ClapTrap henry("Henry");

	bobby.attack(henry.getName());
	henry.takeDamage(bobby.getDamages());
	henry.beRepaired(10);
}