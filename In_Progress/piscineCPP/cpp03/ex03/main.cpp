//
// Created by millefeuille on 25/03/2021.
//

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	ScavTrap bobby("Bobby");
	FragTrap henry("Henry");
	DiamondTrap billy("Billy");

	bobby.attack(henry.getName());
	henry.takeDamage(bobby.getDamages());
	henry.beRepaired(10);
	bobby.beRepaired(20);
	bobby.guardGate();
	henry.highFivesGuys();

	billy.attack(henry.getName());
	billy.guardGate();
	billy.highFivesGuys();
	billy.whoAmI();
}
