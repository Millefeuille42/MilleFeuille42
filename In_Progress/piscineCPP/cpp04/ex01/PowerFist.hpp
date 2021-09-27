//
//	Created by millefeuille on 18/5/2021
//

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon {
	public:
		PowerFist();
		~PowerFist();
		void attack() const;
};

#endif //POWERFIST_HPP
