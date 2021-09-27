//
// Created by millefeuille on 30/03/2021.
//

#ifndef PEON_HPP
#define PEON_HPP


#include "Victim.hpp"

class Peon : public Victim {
	public:
		Peon(std::string const & name);
		Peon(Peon const & src);

		~Peon();

		void getPolymorphed() const ;


	private:
		Peon();
};


#endif //PEON_HPP
