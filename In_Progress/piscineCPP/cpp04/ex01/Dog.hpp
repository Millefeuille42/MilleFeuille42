//
// Created by mlabouri on 9/27/21.
//

#ifndef INC_42_DOG_HPP
# define INC_42_DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &src);
	~Dog();

	Dog &operator=(const Dog &src);

	void makeSound() const;
	Brain *getBrain() const;

private:
	Brain* _brain;
};


#endif //INC_42_DOG_HPP
