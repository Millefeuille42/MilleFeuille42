//
// Created by Millefeuille on 01/07/2021.
//

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	IMateriaSource* src = new MateriaSource();
	ICharacter* patate = new Character("patate");
	AMateria* tmp;

	src->learnMateria(ice);
	src->learnMateria(cure);

	delete ice;
	delete cure;

	tmp = src->createMateria("ice");
	patate->equip(tmp);
	tmp = src->createMateria("cure");
	patate->equip(tmp);
	ICharacter* bob = new Character("bob");
	patate->use(0, *bob);
	patate->use(1, *bob);
	delete bob;
	delete patate;
	delete src;
	return 0;
}