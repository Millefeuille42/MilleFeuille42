//
// Created by millefeuille on 3/23/21.
//

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
	public:
		Weapon();
		Weapon(std::string type);
		void setType(std::string type);
		std::string const &getType() const ;
	private:
		std::string	_type;
};


#endif //WEAPON_HPP
