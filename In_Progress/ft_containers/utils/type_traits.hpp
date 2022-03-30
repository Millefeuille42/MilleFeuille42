//
// Created by mlabouri on 3/15/22.
//

#ifndef INC_42_TYPE_TRAITS_HPP
#define INC_42_TYPE_TRAITS_HPP

#include "../iterators/iterator.hpp"

namespace ft {

	/** @struct enable_if
	 *
	 * @brief https://www.cplusplus.com/reference/type_traits/enable_if/
	 *
	 * Rend disponible la variable interne type, étant T si la condition B est true.
	 * Ne compilant donc pas si B est faux.
	 * Cette version est la spécialisation de template ou B est false, donc ou type n'existe pas
	 *
	 * @tparam B < La condition évaluée
	 * @tparam T < Le type que l'on souhaite rendre, ou non, disponible
	 */

	template <bool B, class T = void> struct enable_if { };

	/** @struct enable_if
     *
     * @brief https://www.cplusplus.com/reference/type_traits/enable_if/
     *
     * Rend disponible la variable interne type, étant T si la condition B est true.
     * Ne compilant donc pas si B est faux.
     * Cette version est la spécialisation de template ou B est true, donc où type existe
     *
     * @tparam T < Le type que l'on souhaite rendre, ou non, disponible
     */

	template <class T> struct enable_if<true, T> {
		typedef T type;
	};

	/** is_integral */
	template <bool B, typename T> struct is_integral_type {
		typedef T type;
		static const bool value = B;
	};

	template <typename T = void> struct is_integral : is_integral_type<false, T> { };

	template <> struct is_integral<bool> : is_integral_type<true, bool> { };

	template <> struct is_integral<char> : is_integral_type<true, char> { };
	template <> struct is_integral<signed char> : is_integral_type<true, signed char> { };
	template <> struct is_integral<unsigned char> : is_integral_type<true, unsigned char> { };

	template <> struct is_integral<wchar_t> : is_integral_type<true, wchar_t> { };
	template <> struct is_integral<short int> : is_integral_type<true, short int> { };

	template <> struct is_integral<unsigned short int> : is_integral_type<true, unsigned short int> { };
	template <> struct is_integral<int> : is_integral_type<true, int> { };
	template <> struct is_integral<unsigned int> : is_integral_type<true, unsigned int> { };
	template <> struct is_integral<long int> : is_integral_type<true, long int> { };
	template <> struct is_integral<unsigned long int> : is_integral_type<true, unsigned long int> { };
}

#endif //INC_42_TYPE_TRAITS_HPP
