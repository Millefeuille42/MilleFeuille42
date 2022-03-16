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
	class normal_input_iterator : public iterator<input_iterator_tag, type> {
		/** Constructors */
		normal_input_iterator(const normal_input_iterator& src) {(void)src;};
		/** Destructor */
		~normal_input_iterator() {};

		/** Members Function*/
		/** Member Operator Overloads */
		normal_input_iterator& operator=(const normal_input_iterator& rhs) {(void)rhs;};

		/** prefix ++a */
		virtual normal_input_iterator& operator++() {};
		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		virtual normal_input_iterator operator++(const int) {};
		virtual bool operator==(const normal_input_iterator& rhs) const {(void)rhs;};
		virtual bool operator!=(const normal_input_iterator& rhs) const {(void)rhs;};
		virtual type& operator*() {}; // dereference
		virtual type* operator->() {}; // structure dereference
	};

	template<typename type>
	class normal_output_iterator : public iterator<output_iterator_tag, type> {
		/** Constructors */
		normal_output_iterator(const normal_output_iterator& src) {(void)src;};
		/** Destructor */
		~normal_output_iterator() {};

		/** Members Function*/
		/** Member Operator Overloads */
		normal_output_iterator& operator=(const normal_output_iterator& rhs) {(void)rhs;};

		/** prefix ++a */
		virtual normal_output_iterator& operator++() {};
		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		virtual normal_output_iterator operator++(const int) {};
		virtual bool operator==(const normal_output_iterator& rhs) const {(void)rhs;};
		virtual bool operator!=(const normal_output_iterator& rhs) const {(void)rhs;};
		virtual type& operator*() {}; // dereference
		virtual type* operator->() {}; // structure dereference
	};

	template<typename type>
	class normal_forward_iterator : public iterator<forward_iterator_tag, type> {
		/** Constructors */
		normal_forward_iterator() {};
		normal_forward_iterator(const normal_forward_iterator& src) {(void)src;};
		/** Destructor */
		~normal_forward_iterator() {};

		/** Members Function*/
		/** Member Operator Overloads */
		normal_forward_iterator& operator=(const normal_forward_iterator& rhs) {(void)rhs;};

		/** prefix ++a */
		virtual normal_forward_iterator& operator++() {};
		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		virtual normal_forward_iterator operator++(const int) {};
		virtual bool operator==(const normal_forward_iterator& rhs) const {(void)rhs;};
		virtual bool operator!=(const normal_forward_iterator& rhs) const {(void)rhs;};
		virtual type& operator*() {}; // dereference
		virtual type* operator->() {}; // structure dereference
	};

	template<typename type>
	class normal_bidirectional_iterator : public iterator<bidirectional_iterator_tag, type> {
		/** Constructors */
		normal_bidirectional_iterator() {};
		normal_bidirectional_iterator(const normal_bidirectional_iterator& src) {(void)src;};
		/** Destructor */
		~normal_bidirectional_iterator() {};

		/** Members Function*/
		/** Member Operator Overloads */
		normal_bidirectional_iterator& operator=(const normal_bidirectional_iterator& rhs) {(void)rhs;};

		/** prefix ++a */
		virtual normal_bidirectional_iterator& operator++() {};
		/** postfix a++ || int to differentiate between prefix and postfix increment operators. */
		virtual normal_bidirectional_iterator operator++(const int) {};
		virtual bool operator==(const normal_bidirectional_iterator& rhs) const {(void)rhs;};
		virtual bool operator!=(const normal_bidirectional_iterator& rhs) const {(void)rhs;};
		virtual type& operator*() {}; // dereference
		virtual type* operator->() {}; // structure dereference
		virtual normal_bidirectional_iterator& operator--() {}; //prefix --a
		virtual normal_bidirectional_iterator operator--(const int) {}; // postfix a-- || int to differentiate between prefix and postfix increment operators.
	};

	template<typename type>
class normal_random_access_iterator : public iterator<ft::random_access_iterator_tag, type> {};

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
	typename iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last) {
		typedef iterator_traits<InputIterator> traits;

		if (is_output_iterator<typename traits::iterator_category>::value) {
			throw ft::invalid_argument();
		}
		if (is_random_access_iterator<typename traits::iterator_category>::value)
			return (last - first);

		typename traits::difference_type diff = 0;
			for (; first != last ; first++) {
				diff++;
			}
		return diff;
	}
}

#endif //NORMAL_ITERATOR_HPP
