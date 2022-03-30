//
// Created by mlabouri on 3/15/22.
//

#ifndef INC_42_TYPE_TRAITS_HPP
#define INC_42_TYPE_TRAITS_HPP

#include "../iterators/iterator_tags.hpp"
#include "../iterators/iterator.hpp"

namespace ft {
	/**  is_derived_from */
	template <typename Derived, typename Base> struct is_derived_from {
		template <typename T> struct check {
			const static bool value = false;
		};

		template <> struct check<Base *> {
			const static bool value = true;
		};

		template <> struct check<void *> {
			const static bool value = false;
		};

		const static bool value = check<Derived *>::value;
	};


	/**  enable_if */
	template <bool B, class T = void> struct enable_if { };

	template <class T> struct enable_if<true, T> {
		typedef T type;
	};


	/**  is_type_equal */
	template <typename T, typename U> struct is_type_equal {
		const static bool value = false;
	};

	template <typename T> struct is_type_equal<T, T> {
		const static bool value = true;
	};


	/**  iterator_checks */
	template <typename T> struct is_input_iterator {
		const static bool value = is_type_equal<T, std::input_iterator_tag>::value;
	};

	template <typename T> struct is_output_iterator {
		const static bool value = is_type_equal<T, std::output_iterator_tag>::value;
	};

	template <typename T> struct is_forward_iterator {
		const static bool value = is_type_equal<T, std::forward_iterator_tag>::value;
	};

	template <typename T> struct is_bidirectional_iterator {
		const static bool value = is_type_equal<T, std::bidirectional_iterator_tag>::value;
	};

	template <typename T> struct is_random_access_iterator {
		const static bool value = is_type_equal<T, std::random_access_iterator_tag>::value;
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
