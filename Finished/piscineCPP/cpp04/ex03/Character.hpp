//
// Created by Millefeuille on 30/06/2021.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
# include "AMateria.hpp"

class Character : public ICharacter {
public:
	Character(const std::string &name);
	Character(const Character &src);

	~Character();

	Character & operator=(Character const & rhs);

	void use(int idx, ICharacter &target);
	void equip(AMateria *m);
	void unequip(int idx);

	const std::string &getName() const;

private:
	AMateria	**_materias;
	int	_materiasCount;
	std::string	_name;

	Character();

	bool hasMateria(AMateria *m);
};


#endif //CHARACTER_HPP
