//
// Created by mlabouri on 4/11/22.
//

#ifndef INC_42_MAP_HPP
#define INC_42_MAP_HPP

#include <memory>
#include "libs/functional.hpp"
#include "libs/utility.hpp"
#include "libs/stddef.hpp"

#include "iterators/normal_iterators.hpp"
#include "iterators/reverse_iterator.hpp"
#include "utils/map_iterator.hpp"

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
		typedef ft::size_t size_type;

	private:
		enum e_status {
			_left = 0,
			_right = 1,
			_parent = 2
		};

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
			result_type operator() (const first_argument_type& x, const second_argument_type& y) const {
				return comp(x.first, y.first);
			}
		};

	public:
		/// Member Types
		typedef _value_compare value_compare;
		///  Iterators
	public:
		typedef map_iterator<value_type, map, key_compare>						iterator;
		typedef map_iterator<const value_type, map, key_compare>				const_iterator;
		typedef reverse_iterator<iterator>										reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
		typedef typename iterator::difference_type 								difference_type;

		/// Member Functions
		/// Constructors
		// TODO Constructors
		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _val_comp(value_compare(comp)) {
			_k_comp = comp;
			_allocator = alloc;
			_size = 0;
			_data = new _tree();
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type());

		map(const map& x)
		: _val_comp(value_compare(key_compare())) {
			*this = x;
		};

		/// Destructor
		~map() {
			for (; !_data->pastTheEnd; _data->next()) {
				_allocator.destroy(_data->current->data);
			}
			_data->resetCurrent();
			delete _data;
		}

		/// Member Operator Overloads
		map& operator=(const map& x) {
			if (this == &x)
				return *this;
			_k_comp = x._k_comp;
			_val_comp = x._val_comp;
			_size = x._size;
			_allocator = x._allocator;
			_data->deepCopy(*x._data);
			return *this;
		}

		///Iterators
		iterator begin() {
			_tree tmp = *_data;
			tmp.leftmost();
			return iterator(tmp);
		};

		const_iterator begin() const {
			_tree tmp = *_data;
			tmp.leftmost();
			return const_iterator(tmp);
		};

		iterator end() {
			_tree tmp = *_data;
			tmp.pastTheEnd();
			return iterator(tmp);
		};

		const_iterator end() const {
			_tree tmp = *_data;
			tmp.pastTheEnd();
			return const_iterator(tmp);
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
			return _size == 0;
		}

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return _allocator.max_size();
		}

		/// Access
		mapped_type& operator[](const key_type& k) {
			mapped_type &ret = mapped_type();
			_data->tmp = _data->current;

			if (!_data->find(make_pair(k,mapped_type()))) {
				// Insert value
				_size++;
			} else
				ret = (*_data->current->data).second;
			_data->current = _data->tmp;
			return ret;
		}

		/// Modifiers
		pair<iterator,bool> insert(const value_type& val) {
			_data->tmp = _data->current;
			if (_data->find(val)) {
				_data->current = _data->tmp;
				return make_pair(iterator(_data), false);
			}
			_data->resetCurrent();
			pointer valPtr = _allocator.allocate(1);
			_allocator.construct(valPtr, val);
			_data->append(valPtr);
			_size++;
			_data->current = _data->tmp;
			return make_pair(iterator(_data), true);
		}

		iterator insert (iterator position, const value_type& val);

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last);

		void erase (iterator position);

		size_type erase (const key_type& k);

		void erase (iterator first, iterator last);

		void swap (map& x) {
			_tree *tmpData = _data;
			size_type tmpSize = _size;

			_data = x._data;
			_size = x._size;

			x._data = tmpData;
			x._size = tmpSize;
		}

		void clear() {
			_data->leftmost();
			for (; _data->pastTheEnd; _data->next())
				_allocator.deallocate(_data->current->data);
			_data->resetCurrent();
			delete _data;
			_size = 0;
			_data = new _tree();
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
			_data->tmp = _data->current;

			if (!_data->find(make_pair(k,mapped_type()))) {
				_data->current = _data->tmp;
				return this->end();
			}

			iterator ret = iterator(_data);
			_data->current = _data->tmp;
			return ret;
		}

		const_iterator find (const key_type& k) const {
			_data->tmp = _data->current;

			if (!_data->find(make_pair(k,mapped_type()))) {
				_data->current = _data->tmp;
				return this->end();
			}

			const_iterator ret = iterator(_data);
			_data->current = _data->tmp;
			return ret;
		}

		size_type count (const key_type& k) const {
			_data->tmp = _data->current;

			if (!_data->find(make_pair(k,mapped_type()))) {
				_data->current = _data->tmp;
				return 0;
			}

			_data->current = _data->tmp;
			return 1;
		}

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

		/// Member Variables
	private:
		typedef tree<map, key_compare> _tree;

		_tree *_data;
		size_type _size;
		allocator_type _allocator;
		key_compare _k_comp;
		value_compare _val_comp;
	};

	// TODO Non member operators
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
