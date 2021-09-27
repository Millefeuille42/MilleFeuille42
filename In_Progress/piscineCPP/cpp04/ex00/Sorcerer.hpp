//
// Created by millefeuille on 30/03/2021.
//

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <string>
#include "Victim.hpp"
#include "Peon.hpp"
#include "Knight.hpp"

class Sorcerer {
	public:
		Sorcerer(const std::string& name, const std::string& title);
		Sorcerer(Sorcerer const & src);

		Sorcerer & operator=(Sorcerer const & rhs);

		~Sorcerer();

		std::string getName() const ;
		std::string getTitle() const ;
		void	polymorph(Victim const & target) const ;
		void	polymorph(Peon const & target) const ;
		void	polymorph(Knight const & target) const ;

	private:
		Sorcerer();

		std::string _name;
		std::string _title;
};

std::ostream &operator<<(std::ostream & stream, Sorcerer const & rhs);

#endif //SORCERER_HPP
