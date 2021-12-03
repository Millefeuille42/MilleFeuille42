//
// Created by mlabouri on 12/3/21.
//

#include <stdexcept>
#include "Span.hpp"

Span::Span() : _max(0) {}
Span::Span(unsigned int max) : _max(max) {}
Span::Span(const Span &src) {*this = src;}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
	_max = rhs._max;
	_numbers = rhs._numbers;
	return *this;
}

void Span::addNumber(int n) {
	if (_numbers.size() == _max)
		throw std::out_of_range("too many values");
	_numbers.push_back(n);
}

unsigned int Span::shortestSpan() {
	if (_numbers.size() <= 1)
		throw std::length_error("not enough values in list");
	std::sort(_numbers.begin(), _numbers.end());

	int min = _numbers.at(1) - _numbers.front();
	for (unsigned int i = 0; i < _numbers.size() - 1; i++)
		if (min > (_numbers.at(i + 1) - _numbers.at(i)))
			min = (_numbers.at(i + 1) - _numbers.at(i));

	return min;
}

unsigned int Span::longestSpan() {
	if (_numbers.size() <= 1)
		throw std::length_error("not enough values in list");

	std::sort(_numbers.begin(), _numbers.end());


	return _numbers.back() - _numbers.front();
}
