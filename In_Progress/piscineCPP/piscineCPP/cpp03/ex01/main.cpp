//
// Created by millefeuille on 25/03/2021.
//

#include "ScavTrap.hpp"

int main() {
	ScavTrap bobby("Bobby");
	ClapTrap henry("Henry");

	bobby.attack(henry.getName());
	henry.takeDamage(bobby.getDamages());
	henry.beRepaired(10);
	bobby.beRepaired(20);

	bobby.guardGate();
}