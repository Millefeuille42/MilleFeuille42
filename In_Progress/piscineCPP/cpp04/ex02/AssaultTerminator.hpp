//
//	Created by millefeuille on 19/5/2021
//

#ifndef AssaultTerminator_HPP
# define AssaultTerminator_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
	public:
		AssaultTerminator();
		AssaultTerminator(AssaultTerminator const & src);
		~AssaultTerminator();
		AssaultTerminator & operator=(AssaultTerminator const & rhs);

		void announce() const;

		ISpaceMarine * clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

private:
public:
	const std::string &getName() const;

private:
	std::string _name;
};

#endif //AssaultTerminator_HPP
