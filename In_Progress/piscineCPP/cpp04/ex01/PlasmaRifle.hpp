//
//	Created by millefeuille on 18/5/2021
//

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP


#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		~PlasmaRifle();
		void attack() const;
};

#endif //PLASMARIFLE_HPP
