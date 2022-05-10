//
// Created by mlabouri on 4/11/22.
//

#ifndef INC_42_MAP_HPP
#define INC_42_MAP_HPP

#include <memory>
#include "includes/libs/functional.hpp"
#include "includes/libs/utility.hpp"
#include "includes/libs/stddef.hpp"
#include "includes/libs/algorithm.hpp"

#include "includes/iterators/normal_iterators.hpp"
#include "includes/iterators/reverse_iterator.hpp"

#include "includes/utils/map_iterator.hpp"

namespace ft {
	template <class Key, class Type,
			class Compare = ft::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key, Type> > >
	class map {
	public:
		/// Member Types
		typedef Key key_type;
		typedef Type mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::pointer const_pointer;
		typedef ft::size_t size_type;

	private:
		/// Nested Classes
		class _value_compare : private binary_function<value_type, value_type, bool> {
			friend class map;
		protected:
			Compare comp;
			_value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			result_type operator() (const first_argument_type& x, const second_argument_type& y) const {
				return comp(x.first, y.first);
			}
		};

		class _duct_tape : private binary_function<value_type, value_type, bool> {
		public:
			_duct_tape() : comp(Compare()) {}  // constructed with map's comparison object
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			result_type operator() (const first_argument_type& x, const second_argument_type& y) const {
				return comp(x.first, y.first);
			}
			Compare comp;
		};

	public:
		/// Member Types
		typedef _value_compare value_compare;
		///  Iterators
		typedef map_iterator<value_type>						iterator;
		typedef map_iterator<const value_type, value_type>		const_iterator;
		typedef reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename iterator::difference_type 				difference_type;

		/// Member Functions
		/// Constructors
		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _val_comp(value_compare(comp)) {
			_k_comp = comp;
			_allocator = alloc;
			_size = 0;
			_data = _treeAllocator.allocate(1);
			_treeAllocator.construct(_data, _tree_type());
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()) : _val_comp(value_compare(comp)) {
			_k_comp = comp;
			_allocator = alloc;
			_size = 0;
			_data = _treeAllocator.allocate(1);
			_treeAllocator.construct(_data, _tree_type());

			insert(first, last);
		}

		map(const map& x)
		: _val_comp(value_compare(key_compare())) {
			_data = NULL;
			*this = x;
		}

		/// Destructor
		~map() {
			if (_data) {
				_treeAllocator.destroy(_data);
				_treeAllocator.deallocate(_data, 1);
			}
			_data = NULL;
		}

		/// Member Operator Overloads
		map& operator=(const map& x) {
			if (this == &x)
				return *this;
			_k_comp = x._k_comp;
			_val_comp = x._val_comp;
			_size = x._size;
			_allocator = x._allocator;
			if (_data)
				_treeAllocator.destroy(_data);
			else
				_data = _treeAllocator.allocate(1);
			_treeAllocator.construct(_data, *x._data);
			return *this;
		}

		///Iterators
		iterator begin() {
			if (_data->empty())
				return end();
			return iterator(_data->getLeftmost());
		}

		const_iterator begin() const {
			if (_data->empty())
				return end();
			return const_iterator(_data->getLeftmost());
		}

		iterator end() {
			iterator ret;
			if (_data->empty()) {
				ret = iterator(node_pointer());
				ret.isPastTheEnd = true;
				return ret;
			}
			ret = iterator(_data->getRightmost());
			ret++;
			return ret;
		}

		const_iterator end() const {
			const_iterator ret;
			if (_data->empty()) {
				ret = const_iterator(node_pointer());
				ret.isPastTheEnd = true;
				return ret;
			}
			ret = ++const_iterator(_data->getRightmost());
			return ret;
		}

		reverse_iterator rbegin() {
			return reverse_iterator(this->end());
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(this->end());
		}

		reverse_iterator rend() {
			return reverse_iterator(this->begin());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(this->begin());
		}

		/// Capacity
		bool empty() const {
			return _data->empty();
		}

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return _allocator.max_size();
		}

		/// Access
		mapped_type& operator[](const key_type& k) {
			// Get iterator on the newly inserted key, or existing key
			iterator el = insert(ft::make_pair(k,mapped_type())).first;
			// Isolate value_type from iterator
			// Return reference on value of pair
			return (*el).second;
		}

		/// Modifiers
		pair<iterator,bool> insert(const value_type& val) {
			_data->resetCurrent();
			pair<node_pointer, bool> ret = _data->append(val);
			if (ret.second)
				_size++;
			return ft::make_pair(iterator(ret.first), ret.second);
		}

		iterator insert (iterator position, const value_type& val) {
			(void) position;
			return insert(val).first;
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			for (; first != last; first++)
				insert(*first);
		}

		void erase (iterator position) {
			erase(position->first);
		}

		size_type erase (const key_type& k) {
			_data->resetCurrent();
			if (!_data->find(ft::make_pair(k, mapped_type())))
				return 0;
			_data->deleteNode();
			_size--;
			return 1;
		}

		void erase (iterator first, iterator last) {
			for (iterator next = first; first != last; first = next) {
				next++;
				erase(first);
			}
		}

		void swap (map& x) {
			_tree_type *tmpData = _data;
			size_type tmpSize = _size;

			_data = x._data;
			_size = x._size;

			x._data = tmpData;
			x._size = tmpSize;
		}

		void clear() {
			_size = 0;
			if (_data)
				_treeAllocator.destroy(_data);
			_treeAllocator.construct(_data, _tree_type());
		}

		/// Observers
		key_compare key_comp() const {
			return _k_comp;
		}

		value_compare value_comp() const {
			return _val_comp;
		}

		/// Operations
		iterator find (const key_type& k) {
			_data->resetCurrent();
			if (!_data->find(ft::make_pair(k, mapped_type())))
				return end();
			return iterator(_data->current);
		}

		const_iterator find (const key_type& k) const {
			node_pointer ret = _data->find(ft::make_pair(k, mapped_type()), node_pointer());
			if (!ret)
				return end();
			return const_iterator(ret);
		}

		size_type count (const key_type& k) const {
			if (!_data->find(ft::make_pair(k, mapped_type()), node_pointer()))
				return 0;
			return 1;
		}

		iterator lower_bound (const key_type& k) {
			iterator it = begin();
			while (it != end() && _k_comp(it->first, k))
				it++;
			return it;
		}

		const_iterator lower_bound (const key_type& k) const {
			const_iterator it = begin();
			while (it != end() && _k_comp(it->first, k))
				it++;
			return it;
		}

		iterator upper_bound (const key_type& k) {
			iterator it = begin();

			while (it != end())
			{
				if (_k_comp(k, it->first))
					return it;
				it++;
			}
			return it;
		}

		const_iterator upper_bound (const key_type& k) const {
			const_iterator it = begin();

			while (it != end())
			{
				if (_k_comp(k, it->first))
					return it;
				it++;
			}
			return it;
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		pair<iterator,iterator>             equal_range (const key_type& k) {
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		/// Allocator
		allocator_type get_allocator() const {
			return _allocator;
		}

		/// Member Variables
	private:
		typedef Tree<value_type, _duct_tape, allocator_type> _tree_type;
		typedef std::allocator<_tree_type> _tree_allocator;
		typedef typename _tree_type::node_pointer node_pointer;

		_tree_type *_data;
		size_type _size;
		allocator_type _allocator;
		_tree_allocator _treeAllocator;
		key_compare _k_comp;
		value_compare _val_comp;
	};

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) {
		x.swap(y);
	}


	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs ) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
										   rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs ) {
		return !(lhs == rhs);

	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs ) {
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs ) {
		return !(lhs > rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs ) {
		return !(lhs < rhs);
	}
}

#endif //INC_42_MAP_HPP
