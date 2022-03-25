//
// Created by millefeuille on 23/03/2021.
//

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class Zombie {
	public:
		Zombie(const std::string name, const std::string type);
		Zombie();
		~Zombie();
		void announce() const;
	private:
		std::string _color;
		std::string _name;
		std::string _type;
};


#endif //ZOMBIE_HPP
