//
// Created by millefeuille on 30/03/2021.
//

#ifndef KNIGHT_HPP
#define KNIGHT_HPP


#include "Victim.hpp"

class Knight : public Victim {
	public:
		Knight(std::string const & name);
		Knight(Knight const & src);

		~Knight();

		void getPolymorphed() const ;


	private:
		Knight();
};


#endif //KNIGHT_HPP
