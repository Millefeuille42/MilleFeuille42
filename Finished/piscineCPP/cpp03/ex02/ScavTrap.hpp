#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
public:

	// default constructor
	ScavTrap            ();
	// parameter constructor
	ScavTrap            (const std::string &name);
	// destructor
	~ScavTrap            (void);
	// copy constructor
	ScavTrap            (ScavTrap const & src);
	// assignment operator
	ScavTrap             & operator=(ScavTrap const & src);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	guardGate();
};
#endif