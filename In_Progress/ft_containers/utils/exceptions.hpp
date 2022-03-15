//
// Created by mlabouri on 3/15/22.
//

#ifndef INC_42_EXCEPTIONS_HPP
#define INC_42_EXCEPTIONS_HPP

#include <exception>

namespace ft {
	class IException : public std::exception {
	public:
		virtual const char *what() const throw() = 0;
	};
	class out_of_range : public IException {
	public:
		const char *what() const throw() {
			return "out of range";
		}
	};
	class invalid_argument : public IException {
		const char *what() const throw() {
			return "invalid argument";
		}
	};
}

#endif //INC_42_EXCEPTIONS_HPP
