//
// Created by mlabouri on 9/27/21.
//

#ifndef INC_42_CAT_HPP
# define INC_42_CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &src);
	~Cat();

	Cat &operator=(const Cat &src);

	void makeSound() const;
	Brain *getBrain() const;

private:
	Brain* _brain;
};


#endif //INC_42_CAT_HPP
