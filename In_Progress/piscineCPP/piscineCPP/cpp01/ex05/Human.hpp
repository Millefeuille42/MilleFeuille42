//
// Created by millefeuille on 3/23/21.
//

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human {
	public:
		Human();
		Human(std::string name);
		std::string	identify() const ;
		Brain const &getBrain() const ;
	private:
		Brain const _brain;
		std::string	_name;
};


#endif //HUMAN_HPP
