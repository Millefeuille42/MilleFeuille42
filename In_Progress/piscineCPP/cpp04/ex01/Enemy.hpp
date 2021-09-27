//
//	Created by millefeuille on 18/5/2021
//

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>
# include <iostream>

class Enemy {
	public:
		Enemy(int hp, std::string const & type);
		virtual ~Enemy();
		Enemy & operator=(Enemy const & rhs);

		std::string getType() const ;
		int getHp() const;

		virtual void takeDamage(int);

	protected:
		std::string	_type;
		int	_hp;

	private:
		Enemy();
		Enemy(Enemy const & src);
};

#endif //ENEMY_HPP
