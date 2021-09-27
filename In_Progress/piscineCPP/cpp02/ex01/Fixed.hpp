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
		Fixed(int const val);
		Fixed(float const val);
		~Fixed();

		Fixed &	operator=(Fixed const & rhs);

		int		getRawBits() const;
		void	setRawBits(int const raw);

		int		toInt() const;
		float	toFloat() const;
	private:
		int	_rawValue;
		static char	const _bitNum = 8;
};

std::ostream &operator<<(std::ostream &, Fixed const &);

#endif //FIXED_HPP
