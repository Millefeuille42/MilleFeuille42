//
//	Created by millefeuille on 18/5/2021
//

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>
 #include <iostream>

class AWeapon {
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		virtual ~AWeapon();
		AWeapon & operator=(AWeapon const & rhs);

		std::string getName() const;
		int getAPCost() const;
		int getDamage() const;

		virtual void attack() const = 0;

	protected:
		std::string	_name;
		int	_apCost;
		int	_damage;

	private:
		AWeapon();
		AWeapon(AWeapon const & src);
};

#endif //AWEAPON_HPP
