//
// Created by mlabouri on 9/27/21.
//

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal *animals[2];
	Brain *brain;

	for (int i = 0; i < 2; i++)
	{
		std::cout << i << std::endl;
		if (i % 2) {
			animals[i] = new Dog();
			continue ;
		}
		animals[i] = new Cat();
	}

	brain = animals[1]->getBrain();
	brain->addIdea("potato");
	brain->addIdea("oh, squirrel");
	brain->addIdea("*yawn*");

	std::cout << std::endl;
	for (int i = 0; i < 2; i++) {
		std::cout << i << std::endl;
		brain->displayIdeas();
		std::cout << "-----" << std::endl;
		delete animals[i];
		std::cout << std::endl;
	}
}
