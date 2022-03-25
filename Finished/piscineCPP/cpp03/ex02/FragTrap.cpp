#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) :
		ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap Parameter constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & src) {
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_damages = src._damages;
	std::cout << "FragTrap Assignment operator called" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string &target) {
	std::cout << "FR4G-TP " + _name + " attacks " + target + ", causing "
			  << _damages << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	if ((int)amount > _hitPoints) {
		_hitPoints = 0;
		return;
	}
	_hitPoints -= (int)amount;
	std::cout << "FR4G-TP " + _name + " takes "
			  << amount << " points of damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	_hitPoints += (int)amount;
	std::cout << "FR4G-TP " + _name + " heals "
			  << amount << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FR4G-TP " + _name + " wants to high-five you!" << std::endl;
}
