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
	 * A la compilation, rend disponible la variable interne type, étant T si la condition B est true.
	 * Ne compilant donc pas si l'on accède au champ "type" alors que B est faux.
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
     * A la compilation, rend disponible la variable interne type, étant T si la condition B est true.
     * Ne compilant donc pas si l'on accède au champ "type" alors que B est faux.
     * Cette version est la spécialisation de template ou B est true, donc où type existe
     *
     * @tparam T < Le type que l'on souhaite rendre, ou non, disponible
     */

	template <class T> struct enable_if<true, T> {
		typedef T type;
	};

	/** @struct is_integral_type
	 *
	 * A la compilation, met le champ "value" a true ou false selon si le type fournit est intégral ou non.
	 * Ceci constitue du squelette de is_integral, l'attribution du champ value se fera a l'aide des spécialisations de template.
	 * Exemples disponible dans la définition de is_integral
	 *
	 * @tparam B < a l'initialisation de la struct, préciser true si l'on considère que le type est intégral, false le cas contraire
	 * @tparam T < Le type concerné, rangé au cas ou on voudrait accéder a celui-ci
	 */

	template <bool B, typename T> struct is_integral_type {
		typedef T type; /// < Le type concerné, rangé au cas ou on voudrait accéder a celui-ci
		static const bool value = B; /// < true si intégral, false le cas contraire
	};

	/** @struct is_integral
	 *
	 * @brief https://www.cplusplus.com/reference/type_traits/is_integral/?kw=is_integral
	 *
	 * @inherit Hérite de la structure squelette is_integral_type,
	 * a l'initialisation de celle ci,
	 * on précise dans les paramètre de template si l'on considère le type comme intégral ou non
	 *
	 * Template par défaut de is_integral, si l'on a pas réalisé de spécialisation de template pour un type précis,
	 * il sera initialisé comme false.
	 *
	 * Par exemple, si l'on décide que char est intégral,
	 * on va créer une spécialisation de template de is_integral pour char, puis on va préciser true dans le paramètre B du parent.
	 * De ce fait, a la compilation, is_integral<char>::value va retourner true
	 *
	 * @tparam T < Le type que l'on souhaite évaluer
	 */

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
