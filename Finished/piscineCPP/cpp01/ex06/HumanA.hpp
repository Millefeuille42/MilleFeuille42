//
// Created by millefeuille on 3/23/21.
//

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	public:
		HumanA();
		HumanA(std::string name);
		HumanA(std::string name, Weapon &weapon);
		void attack() const ;
		void setWeapon(Weapon &weapon);
		Weapon  *getWeapon() ;
	private:
		std::string	_name;
		Weapon	*_weapon;
};


#endif //HUMANA_HPP
