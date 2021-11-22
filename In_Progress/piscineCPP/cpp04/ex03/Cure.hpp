//
// Created by Millefeuille on 30/06/2021.
//

#ifndef CURE_HPP
# define CURE_HPP


#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const AMateria &src);
	~Cure();

	AMateria *clone() const;
	void use(ICharacter &target);
};


#endif //CURE_HPP
