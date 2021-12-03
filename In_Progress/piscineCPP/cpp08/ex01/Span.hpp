//
// Created by mlabouri on 12/3/21.
//

#ifndef INC_42_SPAN_HPP
#define INC_42_SPAN_HPP


#include <vector>
#include <algorithm>

class Span {
public:
	Span();
	Span(unsigned int max);
	Span(const Span& src);

	~Span();

	Span& operator=(const Span& rhs);

	void addNumber(int n);

	template <class Iterator>
	void addNumbers(Iterator start, Iterator end) {
		if (std::distance(start, end) + _numbers.size() > _max)
			throw std::out_of_range("too many values");
		std::copy(start, end, std::back_inserter(_numbers));
	}

	unsigned int shortestSpan();
	unsigned int longestSpan();

private:
	std::vector<int> _numbers;
	unsigned int _max;
};


#endif //INC_42_SPAN_HPP
