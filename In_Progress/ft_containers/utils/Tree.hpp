//
// Created by Millefeuille on 01/05/2022.
//

#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include "Node.hpp"
#include "../libs/utility.hpp"
#include "../libs/functional.hpp"

// TODO Delete operation
namespace ft {
	template <class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
	class Tree {
	public:
		typedef T value_type;
		typedef Compare comp;
		typedef Node<value_type, Alloc> node_val;

		typedef typename node_val::allocator_type allocator_type;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;

		typedef typename node_val::node_allocator node_allocator;
		typedef typename node_val::node_pointer node_pointer;
		typedef typename node_val::node_reference node_reference;

		enum e_status {
			_left = 0,
			_right = 1,
			_parent = 2
		};

		Tree() : _comp(comp()) {
			_nodeAllocator = node_allocator();
			origin = node_pointer();
			resetCurrent();
		}

		Tree(value_type val) {
			_nodeAllocator = node_allocator();
			_comp = comp();
			origin = _nodeAllocator.allocate(1);
			*origin = node_val(val);
			resetCurrent();
		}

		~Tree() {
			if (origin) {
				_nodeAllocator.destroy(origin);
				_nodeAllocator.deallocate(origin, 1);
				origin = node_pointer();
			}
		}

		Tree(const Tree &src) { *this = src;}

		Tree &operator=(const Tree &rhs) {
			if (&rhs == this)
				return *this;
			_comp = rhs._comp;
			_nodeAllocator = rhs._nodeAllocator;
			if (origin) {
				_nodeAllocator.destroy(origin);
				_nodeAllocator.deallocate(origin, 1);
				origin = node_pointer();
			}
			if (rhs.origin) {
				origin = _nodeAllocator.allocate(1);
				*origin = node_val(*rhs.origin);
				_nodeAllocator.construct(origin, *rhs.origin);
			}
			else
				origin = node_pointer();
			resetCurrent();
			return *this;
		}

		pair<node_pointer, bool> append(value_type val) {
			if (!origin) {
				origin = _nodeAllocator.allocate(1);
				_nodeAllocator.construct(origin, val);
				resetCurrent();
				return ft::make_pair(current, true);
			}
			if (!_comp(val, current->data)
			&& !_comp(current->data, val)) {
				return ft::make_pair(current, false);
			}
			int nextPos = evalNextPos(val);
			if (!isSideEmpty(nextPos)) {
				moveTo(nextPos);
				return append(val);
			}
			node_pointer newC = _nodeAllocator.allocate(1);
			_nodeAllocator.construct(newC, val);
			current->setChild(newC, nextPos);
			moveTo(nextPos);
			return ft::make_pair(current, true);
		}

		bool find(const value_type & val) {
			if (!origin)
				return false;
			if (!_comp(val, current->data)
				&& !_comp(current->data, val))
				return true;
			int nextPos = this->evalNextPos(val);
			if (!this->isSideEmpty(nextPos)) {
				this->moveTo(nextPos);
				return this->find(val);
			}
			return false;
		}

		bool find(const value_type & val, node_pointer cur) const {
			if (!origin)
				return false;
			if (cur == node_pointer())
				cur = origin;
			if (!_comp(val, cur->data)
			&& !_comp(cur->data, val))
				return true;

			int nextPos = this->evalNextPos(val);
			if (!this->isSideEmpty(nextPos))
				return this->find(val, cur->getChild(nextPos));
			return false ;
		}

		bool empty() const {
			return origin == node_pointer();
		};

		void next() {
			current = current->next();
		}

		void prev() {
			current = current->prev();
		};

		void leftmost() {
			current = current->leftmostFrom(origin);
		}

		void rightmost() {
			current = current->rightmostFrom(origin);
		}

		node_pointer getLeftmost() const {
			return current->leftmostFrom(origin);
		}

		node_pointer getRightmost() const {
			return current->rightmostFrom(origin);
		}

		void resetCurrent() {
			current = origin;
		}

	private:
		int evalNextPos(const value_type & val) const {
			if (_comp(val, current->data))
				return _left;
			return _right;
		}

		bool isSideEmpty(int pos) const {
			return !current->getChild(pos);
		}

		void moveTo(int pos) {
			if (pos == _parent) {
				current = current->parent;
				return ;
			}
			current = current->getChild(pos);
		}

		node_pointer getChild(int pos) const {
			if (pos == _parent)
				return current->parent;
			return current->getChild(pos);
		}

	public:
		node_pointer origin;
		node_pointer current;
	private:
		node_allocator _nodeAllocator;
		comp _comp;
	};
}

#endif //TREE_HPP
