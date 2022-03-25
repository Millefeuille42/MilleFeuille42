//
// Created by mlabouri on 12/3/21.
//

#include <iostream>
#include "Span.hpp"

int main() {
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	Span sp2 = Span(1000);
	std::vector<int> test(1000, 10);
	test.at(42) = 21;

	sp2.addNumbers(test.begin(), test.end());
	std::cout << "shortest: " << sp2.shortestSpan() << std::endl;
	std::cout << "longest: " << sp2.longestSpan() << std::endl;
}
