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
	Animal();
	Animal(const std::string &type);
	Animal(const Animal &src);

	~Animal();
	void makeSound() const;

	Animal &operator=(Animal const &src);

	Brain *getBrain() const {
		return NULL;
	}

	const std::string &getType() const;

	void setType(const std::string &type);

protected:
	std::string _type;
};


#endif //INC_42_ANIMAL_HPP
