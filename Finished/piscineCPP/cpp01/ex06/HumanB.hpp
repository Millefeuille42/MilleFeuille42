//
// Created by millefeuille on 3/23/21.
//

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
	public:
		HumanB();
		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);
		void attack() const ;
		void setWeapon(Weapon &weapon);
		Weapon *getWeapon() ;
	private:
		std::string	_name;
		Weapon *_weapon;
};


#endif //HUMANB_HPP
