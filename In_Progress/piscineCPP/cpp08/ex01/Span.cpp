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

	std::vector<int> tmp(_numbers);
	std::sort(tmp.begin(), tmp.end());

	int min = tmp.at(1) - tmp.front();
	for (unsigned int i = 0; i < tmp.size() - 1; i++)
		if (min > (tmp.at(i + 1) - tmp.at(i)))
			min = (tmp.at(i + 1) - tmp.at(i));

	return min;
}

unsigned int Span::longestSpan() {
	if (_numbers.size() <= 1)
		throw std::length_error("not enough values in list");
	std::vector<int> tmp(_numbers);
	std::sort(tmp.begin(), tmp.end());

	return tmp.back() - tmp.front();
}
