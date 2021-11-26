//
// Created by mlabouri on 9/27/21.
//

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Cat* i = new Cat();
	const Dog* j = new Dog();

	i->getBrain()->addIdea("potato");
	i->getBrain()->addIdea("cheese");
	i->getBrain()->addIdea("lobster");
	i->getBrain()->addIdea("fish");

	std::cout << std::endl;
	i->getBrain()->displayIdeas();

	j->getBrain()->deepCopy(*i->getBrain());
	j->getBrain()->addIdea("chicken");

	std::cout << std::endl;
	j->getBrain()->displayIdeas();
	std::cout << std::endl;
	i->getBrain()->displayIdeas();
	std::cout << std::endl;

	delete i;
	const Dog* k = new Dog(*j);
	delete j;
	k->getBrain()->addIdea("beef");
	std::cout << std::endl;
	k->getBrain()->displayIdeas();
	delete k;
}