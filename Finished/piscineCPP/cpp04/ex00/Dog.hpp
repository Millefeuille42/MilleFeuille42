//
// Created by mlabouri on 9/27/21.
//

#ifndef INC_42_DOG_HPP
# define INC_42_DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &src);
	~Dog();

	Dog &operator=(const Dog &src);

	void makeSound() const;
};


#endif //INC_42_DOG_HPP
