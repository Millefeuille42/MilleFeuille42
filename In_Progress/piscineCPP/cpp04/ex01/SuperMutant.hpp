//
//	Created by millefeuille on 18/5/2021
//

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy {
	public:
		SuperMutant();
		~SuperMutant();
		void takeDamage(int);
};

#endif //SUPERMUTANT_HPP
