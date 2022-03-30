//
// Created by mlabouri on 3/15/22.
//

#ifndef INC_42_EXCEPTIONS_HPP
#define INC_42_EXCEPTIONS_HPP

#include <exception>

namespace ft {

	/** @interface IException
	 *
	 * Une interface pour les exceptions custom
	 *
	 * @inherit Hérite de std::exception
	 */

	class IException : public std::exception {
	public:
		virtual const char *what() const throw() = 0;
	};

	/** @interface invalid_argument
	 *
	 * Exception servant dans le cas ou un argument est invalide
	 *
	 * @inherit Hérite de IException
	 *
	 */

	class invalid_argument : public IException {
		const char *what() const throw() {
			return "invalid argument";
		}
	};
}

#endif //INC_42_EXCEPTIONS_HPP
