//
// Created by Millefeuille on 01/05/2022.
//

#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include "Node.hpp"
#include "../libs/utility.hpp"
#include "../libs/functional.hpp"

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
			}
			origin = node_pointer();
			resetCurrent();
		}

		Tree(const Tree &src) {
			origin = node_pointer();
			resetCurrent();
			*this = src;
		}

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

		node_pointer find(const value_type & val, node_pointer cur) const {
			if (!origin)
				return node_pointer();
			if (cur == node_pointer())
				cur = origin;
			if (!_comp(val, cur->data)
			&& !_comp(cur->data, val))
				return cur;

			int nextPos = this->evalNextPos(cur, val);
			if (cur->getChild(nextPos))
				return this->find(val, cur->getChild(nextPos));
			return node_pointer();
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

		void deleteNode() {
			node_pointer successor = NULL;

			// Si le node current n'a pas d'enfants
			if (!current->getChild(_left) && !current->getChild(_right)) {
				// Supprimer la reference au node supprimé dans le parent
				if (current->parent)
					current->parent->setChildAddr(node_pointer(), current->at);
			}

			// Si le node current n'a qu'un enfant
			else if (!current->getChild(_left) || !current->getChild(_right)) {
				successor = current->getChild(_left);
				if (!successor)
					successor = current->getChild(_right);

				// Assigner les enfants de current a son parent
				if (current->parent) {
					current->parent->setChildAddr(successor, current->at);
					successor->parent = current->parent;
				}
			}

			else {
				// Prendre le NEXT de current
				successor = current->next();

				// Si NEXT n'est pas l'enfant imminent de current, l'enfant droite de next prend la place de next
				if (current->getChild(_right) != successor) {
					if (successor->getChild(_right))
						successor->parent->setChildAddr(successor->getChild(_right), successor->at);
					if (successor->parent) {
						successor->parent->setChildAddr(node_pointer(), successor->at);
					}
				}

				// Mettre NEXT a la place de current
				// Assigner le NEXT en tant qu'enfant du parent de current
				if (current->parent) {
					current->parent->setChildAddr(successor, current->at);
				}

				// Assigner les enfants de current a NEXT
				if (current->getChild(_left) != successor)
					successor->setChildAddr(current->getChild(_left), _left);
				if (current->getChild(_right) != successor)
					successor->setChildAddr(current->getChild(_right), _right);
			}


			// Delete reference to current's children and parent
			if (current->parent && current->parent->getChild(current->at) == current)
				current->parent->setChildAddr(node_pointer(), current->at);
			if (!current->parent) {
				origin = successor;
				if (successor) {
					successor->parent = node_pointer();
					successor->at = -1;
				}
			}
			current->setChildAddr(node_pointer(), _left);
			current->setChildAddr(node_pointer(), _right);
			current->parent = node_pointer();
			current->at = -3;
			_nodeAllocator.destroy(current);
			_nodeAllocator.deallocate(current, 1);
			current = node_pointer();
		}

	private:
		int evalNextPos(const value_type & val) const {
			if (_comp(val, current->data))
				return _left;
			return _right;
		}

		int evalNextPos(node_pointer cur, const value_type & val) const {
			if (_comp(val, cur->data))
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
