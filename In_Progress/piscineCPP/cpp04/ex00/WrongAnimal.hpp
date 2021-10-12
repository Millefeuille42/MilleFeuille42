//
// Created by mlabouri on 9/27/21.
//

#ifndef INC_42_WRONGANIMAL_HPP
#define INC_42_WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal &src);

	virtual ~WrongAnimal();
	void makeSound() const;

	WrongAnimal &operator=(WrongAnimal const &src);

	const std::string &getType() const;

	void setType(const std::string &type);

protected:
	std::string _type;
};


#endif //INC_42_WRONGANIMAL_HPP
