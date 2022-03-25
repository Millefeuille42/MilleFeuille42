//
// Created by mlabouri on 9/27/21.
//

#ifndef INC_42_WRONGCAT_HPP
#define INC_42_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &src);
	~WrongCat();

	WrongCat &operator=(const WrongCat &src);

	void makeSound() const;
};


#endif //INC_42_WRONGCAT_HPP
