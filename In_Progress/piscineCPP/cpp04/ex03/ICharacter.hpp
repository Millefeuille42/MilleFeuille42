//
// Created by Millefeuille on 30/06/2021.
//

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class AMateria;

class ICharacter {
public:
	virtual ~ICharacter() {}

	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;

	virtual std::string const & getName() const = 0;
};

#endif //ICHARACTER_HPP
