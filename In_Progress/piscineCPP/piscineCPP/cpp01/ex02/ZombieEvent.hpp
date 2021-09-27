//
// Created by millefeuille on 23/03/2021.
//

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "../ex03/Zombie.hpp"

class ZombieEvent {
	public:
		void	setZombieType(std::string type);
		Zombie	*newZombie(std::string name);
		Zombie	*randomChump();
	private:
		std::string _type;
};


#endif //ZOMBIEEVENT_HPP
