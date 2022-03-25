//
// Created by Millefeuille on 01/07/2021.
//

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;

	Character *bobby = new Character("bobby");
	bobby->equip(src->createMateria("ice"));

	Character *henry = new Character(*bobby);
	henry->equip(src->createMateria("cure"));

	henry->use(0, *bobby);
	henry->use(1, *bobby);
	bobby->use(1, *me);
	bobby->use(0, *me);

	delete src;
	delete bobby;

	henry->use(0, *me);

	delete me;
	delete henry;

	return 0;
}
