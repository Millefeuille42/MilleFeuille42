//
// Created by millefeuille on 24/03/2021.
//

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(Fixed const & src);
		~Fixed();

		Fixed &	operator=(Fixed const & rhs);

		int	getRawBits() const;
		void	setRawBits(int const raw);
	private:
		int	_value;
		static char	const _bitNum = 8;
};


#endif //FIXED_HPP
