//
//	Created by millefeuille on 10/6/2021
//

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria {
public:
	AMateria(const std::string &type);

	AMateria();
	AMateria(AMateria const & src);
	virtual ~AMateria();
	AMateria & operator=(AMateria const & rhs);

	const std::string &getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
		std::string	_type;
};

#endif //AMATERIA_HPP
