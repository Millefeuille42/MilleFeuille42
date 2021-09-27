//
// Created by Millefeuille on 30/06/2021.
//

#ifndef ICE_HPP
# define ICE_HPP


#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(Ice const & src);
	~Ice();
	Ice & operator=(Ice const & rhs);

	AMateria * clone() const;
	void use(ICharacter &target);
};


#endif //ICE_HPP
