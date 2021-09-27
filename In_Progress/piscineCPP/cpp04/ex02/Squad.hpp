//
// Created by millefeuille on 19/05/2021.
//

#ifndef SQUAD_HPP
#define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad{
	public:
		Squad();
		Squad(const Squad & src);
		~Squad();
		Squad & operator=(const Squad & rhs);

		ISpaceMarine **deepCopy() const;
		void	cleanSquad();

		bool isValid(ISpaceMarine *marine) const;
		int getCount() const;
		int push(ISpaceMarine *);
		ISpaceMarine * getUnit(int) const;
protected:
		int	_count;
		ISpaceMarine**	_marines;
};


#endif //SQUAD_HPP
