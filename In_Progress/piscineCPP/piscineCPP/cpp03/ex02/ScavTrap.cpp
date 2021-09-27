#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) :
		ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap Parameter constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src) {
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_damages = src._damages;
	std::cout << "ScavTrap Assignment operator called" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	std::cout << "SC4V-TP " + _name + " attacks " + target + ", causing "
			  << _damages << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if ((int)amount > _hitPoints) {
		_hitPoints = 0;
		return;
	}
	_hitPoints -= (int)amount;
	std::cout << "SC4V-TP " + _name + " takes "
			  << amount << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	_hitPoints += (int)amount;
	std::cout << "SC4V-TP " + _name + " heals "
			  << amount << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "SC4V-TP " + _name + " entered Gate Keeper mode " << std::endl;
}
