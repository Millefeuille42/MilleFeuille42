//
// Created by Millefeuille on 29/06/2021.
//

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string	_name;

public:
	// default constructor
	DiamondTrap            ();
	// parameter constructor
	DiamondTrap            (const std::string &name);
	// destructor
	~DiamondTrap            ();
	// copy constructor
	DiamondTrap            (DiamondTrap const & src);
	// assignment operator
	DiamondTrap             & operator=(DiamondTrap const & src);

	void attack(const std::string &target) {
		ScavTrap::attack(target);
	}

	void beRepaired(unsigned int amount) {
		ScavTrap::beRepaired(amount);
	}

	void takeDamage(unsigned int amount) {
		ScavTrap::takeDamage(amount);
	}

	void whoAmI() const;
};

#endif
