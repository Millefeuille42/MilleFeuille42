//
// Created by mlabouri on 4/11/22.
//

#ifndef INC_42_UTILITY_HPP
#define INC_42_UTILITY_HPP

namespace ft {
	template <class T1, class T2> struct pair {
		/// Member Types
		typedef T1 first_type;
		typedef T2 second_type;

		/// Constructors
		pair() : first(first_type()), second(second_type()) {}

		template<class U, class V> pair(const pair<U,V>& src) {
			*this = src;
		}

		pair(const first_type& a, const second_type& b) : first(a), second(b) {}

		/// Member Functions
		pair& operator=(const pair& rhs) {
			first = rhs.first;
			second = rhs.second;
		}

		/// Member Variables
		first_type	first;
		second_type	second;
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first < rhs.first || (lhs.first < rhs.first && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs > rhs);
	}

	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {
		return pair<T1,T2>(x,y);
	}

}

#endif //INC_42_UTILITY_HPP
