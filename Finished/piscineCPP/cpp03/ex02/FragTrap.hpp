#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>
# include <string>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
public:

	// default constructor
	FragTrap            ();
	// parameter constructor
	FragTrap            (const std::string &name);
	// destructor
	~FragTrap            ();
	// copy constructor
	FragTrap            (FragTrap const & src);
	// assignment operator
	FragTrap             & operator=(FragTrap const & src);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	highFivesGuys();
};
#endif