//
//	Created by millefeuille on 18/5/2021
//

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character {
	public:
		Character(std::string const & name);
		~Character();
		Character & operator=(Character const & rhs);

		void	recoverAP();
		void	equip(AWeapon*);
		void	attack(Enemy*);
		std::string	getName() const;
		int	getAP() const;
		AWeapon*	getWeapon() const;

	private:
		Character();
		Character(Character const & src);
		std::string	_name;
		int	_ap;
		AWeapon*	_weapon;
};

std::ostream  &operator<<(std::ostream &, Character const &);

#endif //CHARACTER_HPP
