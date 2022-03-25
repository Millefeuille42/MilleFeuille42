//
// Created by millefeuille on 23/03/2021.
//

#ifndef PONY_HPP
# define PONY_HPP

# include <string>
# include <iostream>

class Pony {
	private:
		int			_age;
		int			_legs;
		std::string _name;
	public:
		Pony();
		Pony(int age, const std::string name);
		~Pony();
		void sayIntro() const ;
};

void ponyOnTheStack(int age, const std::string name);
void ponyOnTheHeap(int age, const std::string name);

#endif
