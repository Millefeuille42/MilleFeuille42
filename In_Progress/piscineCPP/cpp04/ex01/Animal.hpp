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

	virtual ~Animal();
	virtual void makeSound() const;

	Animal &operator=(Animal const &src);

	virtual Brain *getBrain() const = 0;
	const std::string &getType() const;

	void setType(const std::string &type);

protected:
	std::string _type;
};


#endif //INC_42_ANIMAL_HPP
