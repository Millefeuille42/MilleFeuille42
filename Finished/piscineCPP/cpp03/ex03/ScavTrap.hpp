#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
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

	virtual void	attack(const std::string &target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);
	void	guardGate();
};
#endif
