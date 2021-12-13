//
// Created by mlabouri on 9/27/21.
//

#include "Brain.hpp"

Brain::Brain() : _lastIdea(0) {
	std::cout << "Default constructor of Brain called!" << std::endl;
}

Brain::Brain(const Brain &src) {
	std::cout << "Copy constructor of Brain called!" << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << "Destructor of Brain called!" << std::endl;
}

Brain &Brain::operator=(const Brain &src) {
	std::cout << "Copy operator of Brain called!" << std::endl;
	for (int i = 0; i < _lastIdea; i++) {
		_ideas[i] = src._ideas[i];
	}
	_lastIdea = src._lastIdea;
	return *this;
}

void Brain::addIdea(const std::string &idea) {
	if (_lastIdea >= 100)
		return ;
	_ideas[_lastIdea] = idea;
	_lastIdea++;
}

void Brain::displayIdeas() {
	for (int i = 0; i < _lastIdea; i++) {
		std::cout << _ideas[i] << std::endl;
	}
}

const std::string *Brain::getIdeas() const {
	return _ideas;
}

void Brain::deepCopy(Brain &src) {
	for (int i = 0; i < src._lastIdea; i++) {
		_ideas[i] = src._ideas[i];
	}
	_lastIdea = src._lastIdea;
}
