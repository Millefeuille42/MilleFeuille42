//
// Created by Millefeuille on 29/06/2021.
//

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap() {
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
		ClapTrap(name + "_clap_name", 100, 50, 30), _name(name) {
	std::cout << "DiamondTrap Parameter constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src) {
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & src) {
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_damages = src._damages;
	std::cout << "DiamondTrap Assignment operator called" << std::endl;
	return *this;
}

void	DiamondTrap::whoAmI() const {
	std::cout << "Hello! I'm " + ClapTrap::_name +
	"! But you can call me " + _name + " too!" << std::endl;
}
