//
// Created by mlabouri on 9/27/21.
//

#ifndef INC_42_ANIMAL_HPP
# define INC_42_ANIMAL_HPP

# include <string>
# include <iostream>
# include "Brain.hpp"

class Animal {
public:
	virtual ~Animal();
	virtual void makeSound() const = 0;

	Animal &operator=(Animal const &src);

	const std::string &getType() const;
	virtual Brain *getBrain() const = 0;
	void setType(const std::string &type);

protected:
	Animal();
	Animal(const std::string &type);
	Animal(const Animal &src);
	std::string _type;
};


#endif //INC_42_ANIMAL_HPP

//	// default constructorx
//	ClapTrap            ();
//	// parameter constructor
//	ClapTrap            (const std::string& name);
//	// destructor
//	~ClapTrap            ();
//	// copy constructor
//	ClapTrap            (ClapTrap const & src);
//	// assignment operator
//	ClapTrap             & operator=(ClapTrap const & src);