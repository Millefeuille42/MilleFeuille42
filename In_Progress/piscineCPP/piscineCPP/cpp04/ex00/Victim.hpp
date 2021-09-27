//
// Created by millefeuille on 30/03/2021.
//

#ifndef VICTIM_HPP
#define VICTIM_HPP


#include <string>

class Victim {
	public:
		Victim(std::string const & name);
		Victim(Victim const & src);

		Victim & operator=(Victim const & rhs);

		~Victim();

		std::string	getName() const ;

	virtual void getPolymorphed() const ;


	protected:
		std::string	_name;


	private:
		Victim();
};

std::ostream &operator<<(std::ostream & stream, Victim const & rhs);

#endif //VICTIM_HPP