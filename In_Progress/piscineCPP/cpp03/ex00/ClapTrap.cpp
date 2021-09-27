#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
		_hitPoints(10), _energyPoints(10), _damages(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name), _hitPoints(10), _energyPoints(10), _damages(0) {
	std::cout << "Parameter constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src) {
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_damages = src._damages;
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

int ClapTrap::getDamages() {
	return _damages;
}

void ClapTrap::attack(const std::string &target) {
	std::cout << "CL4P-TP " + _name + " attacks " + target + ", causing "
	<< _damages << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if ((int)amount > _hitPoints) {
		_hitPoints = 0;
		return;
	}
	_hitPoints -= (int)amount;
	std::cout << "CL4P-TP " + _name + " takes "
	<< amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	_hitPoints += (int)amount;
	std::cout << "CL4P-TP " + _name + " heals "
			  << amount << " points of damage!" << std::endl;
}

std::string ClapTrap::getName() {
	return _name;
}

int ClapTrap::getEnergy() {
	return _energyPoints;
}

int ClapTrap::getHitPoints() {
	return _hitPoints;
}
