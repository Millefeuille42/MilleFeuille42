//
//	Created by millefeuille on 19/5/2021
//

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
	public:
		TacticalMarine();
		TacticalMarine(TacticalMarine const & src);
		~TacticalMarine();
		TacticalMarine & operator=(TacticalMarine const & rhs);

		void announce() const;

		ISpaceMarine * clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

private:
	std::string _name;
public:
	const std::string &getName() const;
};

#endif //TACTICALMARINE_HPP
