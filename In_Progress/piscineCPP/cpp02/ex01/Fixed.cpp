//
// Created by millefeuille on 24/03/2021.
//

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _rawValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int val) : _rawValue(val << this->_bitNum) {}

Fixed::Fixed(const float val) {
	_rawValue = roundf(val * (1 << this->_bitNum));
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		_rawValue = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits number called" << std::endl;
	return _rawValue;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits number called" << std::endl;
	_rawValue = raw;
}

int Fixed::toInt() const {
	return _rawValue >> _bitNum;
}

float Fixed::toFloat() const {
	return (float)this->_rawValue / (1 << this->_bitNum);
}

std::ostream &operator<<(std::ostream &stream, Fixed const &n) {
	return stream << n.toFloat();
}
