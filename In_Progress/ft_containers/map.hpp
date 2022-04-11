//
// Created by mlabouri on 4/11/22.
//

#ifndef INC_42_MAP_HPP
#define INC_42_MAP_HPP

#include <memory>
#include "utils/functional.hpp"
#include "utils/utility.hpp"
#include "utils/stddef.hpp"

namespace ft {
	template <class Key, class Type,
			class Compare = ft::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key, Type> > >
	class map {
	public:
		/// Member Types
		typedef Key key_type;
		typedef Type mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::pointer const_pointer;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		/// Nested Classes
		class _value_compare : binary_function<value_type, value_type, bool> {
			friend class map;
		protected:
			Compare comp;
			_value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
		};

		/// Member Variables
		size_type _size;
		allocator_type _allocator;

	public:

		/// Member Types
		typedef _value_compare value_compare;
		// iterator
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator

		/// Member Functions
		/// Constructors
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type());

		map(const map& x);

		/// Destructor
		~map();

		/// Member Operator Overloads
		map& operator= (const map& x);

		///Iterators
		iterator begin();

		const_iterator begin() const;

		iterator end();

		const_iterator end() const;

		reverse_iterator rbegin();

		const_reverse_iterator rbegin() const;

		reverse_iterator rend();

		const_reverse_iterator rend() const;

		/// Capacity
		bool empty() const {
			return _size == 0;
		}

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return _allocator.max_size();
		}

		/// Access
		mapped_type& operator[] (const key_type& k);

		/// Modifiers
		pair<iterator,bool> insert (const value_type& val);

		iterator insert (iterator position, const value_type& val);

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last);

		void erase (iterator position);

		size_type erase (const key_type& k);

		void erase (iterator first, iterator last);

		void swap (map& x);

		void clear();

		/// Observers
		key_compare key_comp() const {
			return key_compare();
		}

		value_compare value_comp() const {
			return value_compare();
		}

		/// Operations
		iterator find (const key_type& k);

		const_iterator find (const key_type& k) const;

		size_type count (const key_type& k) const;

		iterator lower_bound (const key_type& k);

		const_iterator lower_bound (const key_type& k) const;

		iterator upper_bound (const key_type& k);

		const_iterator upper_bound (const key_type& k) const;

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

		pair<iterator,iterator>             equal_range (const key_type& k);

		/// Allocator
		allocator_type get_allocator() const {
			return _allocator;
		}
	};

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y);

	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs );
}

#endif //INC_42_MAP_HPP
