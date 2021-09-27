#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
protected:
	std::string         _name;
	int                 _hitPoints;
	int                 _energyPoints;
	int                 _damages;

public:
	// default constructor
	ClapTrap            ();
	// parameter constructor
	ClapTrap            (const std::string& name);
	ClapTrap			(const std::string& name, int hit, int nrg, int damages);
	// destructor
	~ClapTrap            ();
	// copy constructor
	ClapTrap            (ClapTrap const & src);
	// assignment operator
	ClapTrap             & operator=(ClapTrap const & src);

	int	getDamages();
	int	getEnergy();
	int	getHitPoints();
	std::string	getName();

	void	attack(std::string const & target);

	void	takeDamage(unsigned int amount);

	void	beRepaired(unsigned int amount);
};
#endif