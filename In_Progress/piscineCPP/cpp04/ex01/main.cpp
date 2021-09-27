//
// Created by millefeuille on 18/05/2021.
//

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

#include "Character.hpp"

int main() {
	Character* me = new Character("Norminet");
	std::cout << *me;

	Enemy* rc = new RadScorpion();
	Enemy* sm = new SuperMutant();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;

	me->equip(pf);
	me->attack(rc);
	std::cout << *me;

	me->equip(pr);
	std::cout << *me;

	me->attack(rc);
	std::cout << *me;

	me->attack(rc);
	std::cout << *me;

	me->attack(sm);
	std::cout << *me;

	me->equip(pf);
	me->attack(sm);
	me->attack(sm);
	me->attack(sm);

	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->attack(sm);
	me->attack(NULL);

	me->equip(NULL);
	me->attack(sm);

	delete me;

	return 0;
}