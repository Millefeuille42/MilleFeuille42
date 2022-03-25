//
// Created by mlabouri on 9/27/21.
//

#ifndef INC_42_BRAIN_HPP
# define INC_42_BRAIN_HPP

# include <string>
# include <iostream>

class Brain {
public:
	Brain();
	Brain(const Brain &src);

	virtual ~Brain();

	void deepCopy(Brain &src);

	const std::string *getIdeas() const;
	void addIdea(const std::string &idea);
	void displayIdeas();

	Brain &operator=(const Brain &src);
protected:
	std::string	_ideas[100];
	int	_lastIdea;

};


#endif //INC_42_BRAIN_HPP
