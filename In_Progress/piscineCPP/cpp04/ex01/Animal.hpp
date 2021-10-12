//
// Created by mlabouri on 9/27/21.
//

#ifndef INC_42_ANIMAL_HPP
# define INC_42_ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {
public:
	Animal();
	Animal(const std::string &type);
	Animal(const Animal &src);

	virtual ~Animal();
	void makeSound() const;

	Animal &operator=(Animal const &src);

	const std::string &getType() const;

	void setType(const std::string &type);

protected:
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