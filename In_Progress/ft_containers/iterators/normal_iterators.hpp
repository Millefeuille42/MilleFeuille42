//
// Created by mlabouri on 12/17/21.
//

#ifndef NORMAL_ITERATOR_HPP
#define NORMAL_ITERATOR_HPP

#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "iterator_tags.hpp"
#include "../utils/exceptions.hpp"
#include "../utils/type_traits.hpp"

/// Has no interest as is, it's just for reference when building iterators
namespace ft {
	template<typename type>
	class normal_input_iterator : public iterator<std::input_iterator_tag, type> {};

	template<typename type>
	class normal_output_iterator : public iterator<std::output_iterator_tag, type> {};

	template<typename type>
	class normal_forward_iterator : public iterator<std::forward_iterator_tag, type> {};

	template<typename type>
	class normal_bidirectional_iterator : public iterator<std::bidirectional_iterator_tag, type> {};

	template<typename type>
	class normal_random_access_iterator : public iterator<std::random_access_iterator_tag, type> {};


	template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n) {
		typedef iterator_traits<InputIterator> traits;

		if (is_bidirectional_iterator<typename traits::iterator_category>::value
			|| is_random_access_iterator<typename traits::iterator_category>::value) {
			if (n <  0)
				throw ft::out_of_range();
		}

		if (is_random_access_iterator<typename traits::iterator_category>::value) {
			it += n;
			return;
		}
		for (Distance i = 0; i < n; i++) {
			it++;
		}
	}

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	iterDistance(InputIterator first, InputIterator last) {
		typename iterator_traits<InputIterator>::difference_type diff = 0;
		for (; first != last ; first++) {
			diff++;
		}
		return diff;
	}

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	trueDistance(InputIterator first, InputIterator last, std::input_iterator_tag tag) {
		(void) tag;
		return iterDistance(first, last);
	}

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	trueDistance(InputIterator first, InputIterator last, std::output_iterator_tag tag) {
		(void) tag;
		(void) first;
		(void) last;
		throw ft::invalid_argument();
	}

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	trueDistance(InputIterator first, InputIterator last, std::forward_iterator_tag tag) {
		(void) tag;
		return iterDistance(first, last);
	}

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	trueDistance(InputIterator first, InputIterator last, std::bidirectional_iterator_tag tag) {
		(void) tag;
		return iterDistance(first, last);
	}

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	trueDistance(InputIterator first, InputIterator last, std::random_access_iterator_tag tag) {
		(void) tag;
		if (last - first < 0)
			return first - last;
		return (last - first);
	}

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last) {
		typedef iterator_traits<InputIterator> traits;
		return trueDistance(first, last, typename traits::iterator_category());
	}
}

#endif //NORMAL_ITERATOR_HPP
