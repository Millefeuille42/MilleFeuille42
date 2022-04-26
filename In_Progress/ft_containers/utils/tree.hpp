//
// Created by mlabouri on 4/12/22.
//

#ifndef INC_42_TREE_HPP
#define INC_42_TREE_HPP

#include <memory>
#include <cstdlib>
#include <stdexcept>
#include "../libs/functional.hpp"
#include "../libs/stddef.hpp"
#include "../libs/utility.hpp"

namespace ft {
	template <class Container, class Compare = ft::less<typename Container::value_type> >
	class tree {
	public:
		/// Member Types
		typedef Compare compare;

		typedef pair<const typename Container::key_type, typename Container::mapped_type> value_type;
		typedef typename std::allocator<typename value_type::second_type>::pointer pointer;
		typedef typename std::allocator<typename value_type::second_type>::reference reference;

		typedef typename Container::allocator_type allocator_type;
		typedef typename Container::size_type size_type;

	private:
		enum e_status {
			_left = 0,
			_right = 1,
			_parent = 2
		};

		class node {
		public:
			typedef typename Container::pointer pointer;

		public:
			node(pointer ptr = pointer()) : parent(NULL) {
				_children[_left] = NULL;
				_children[_right] = NULL;
				data = ptr;
				at = -1;
			}

			node(const node & src) { *this = src; }

			~node() {
				delete _children[_left];
				delete _children[_right];
			}

			node& operator=(const node& rhs) {
				if (&rhs == this)
					return *this;
				data = rhs.data;
				if (!rhs.parent)
					parent = NULL;

				delete _children[_left];
				_children[_left] = NULL;
				delete _children[_right];
				_children[_right] = NULL;
				if (rhs._children[_left]) {
					node *newC = new node(*rhs._children[_left]);
					setChild(newC, _left);
				}
				if (rhs._children[_right]) {
					node *newC = new node(*rhs._children[_right]);
					setChild(newC, _right);
				}
				return *this;
			}

			node *getChild(int index) const {
				if (index > _right || index < _left)
					throw std::out_of_range("out of range");
				return _children[index];
			}

			void setChild(node *child, int index) {
				if (index > _right || index < _left)
					throw std::out_of_range("out of range");
				child->parent = this;
				_children[index] = child;
				_children[index]->at = index;
			}

		public:
			node *parent;
			pointer data;
			int at;
		private:
			node *_children[2];
		};

	public:
		// TODO Manage empty tree

		tree(pointer ptr = pointer(), allocator_type alloc = allocator_type())
		: _allocator(alloc) {
			origin = new node(ptr, _allocator);
			this->resetCurrent();
			_size = 1;
			pastTheEnd = false;
			beforeBegin = false;
			_comp = compare();
		}

		tree(const tree & src) {
			*this = src;
			_comp = compare();
		}

		~tree() { delete origin; }

		tree& operator=(const tree &rhs) {
			if (&rhs == this)
				return *this;
			_allocator = rhs._allocator;
			_size = rhs._size;
			delete origin;
			origin = new node(*rhs.origin);
			this->resetCurrent();
			pastTheEnd = rhs.pastTheEnd;
			beforeBegin = rhs.beforeBegin;
			return *this;
		}

		void toPastTheEnd() {
			pastTheEnd = true;
			beforeBegin = false;
		}

		void toBeforeBegin() {
			pastTheEnd = false;
			beforeBegin = true;
		}

		void next() {
			if (pastTheEnd)
				return;

			if (beforeBegin) {
				beforeBegin = false;
				this->leftmost();
				return ;
			}

			// If you have a right node, go at the leftmost from this node
			if (!this->isSideEmpty(_right)) {
				this->moveTo(_right);
				this->leftmostFromCurrent();
				return ;
			}

			// If you are at origin, and have no right node, you are the highest
			if (!current->parent) {
				return ;
			}

			// Otherwise, If you are at left of your parent, go up once
			if (current->at == _left) {
				moveTo(_parent);
				return ;
			}

			// Otherwise, Go up until you are not at right of your parent
			node *old = current;
			for (; !current->parent || current->at == _right; moveTo(_parent)) {
				// If you end up at origin, you were at the highest node
				if (!current->parent) {
					current = old;
					pastTheEnd = true;
					return ;
				}
			}
			moveTo(_parent);
		}

		void prev() {
			if (beforeBegin)
				return ;

			if (pastTheEnd) {
				pastTheEnd = false;
				this->rightmost();
				return ;
			}

			// If you have a left node, go at the rightmost from this node
			if (this->isSideEmpty(_left)) {
				this->moveTo(_left);
				this->rightmostFromCurrent();
				return ;
			}

			// If you are at origin, and have no left node, you are the highest
			if (!current->parent) {
				return ;
			}

			// Otherwise, If you are at right of your parent, go up once
			if (current->at == _right) {
				moveTo(_parent);
				return ;
			}

			// Otherwise, Go up until you are not at left of your parent
			node *old = current;
			for (; !current->parent || current->at == _left; moveTo(_parent)) {
				// If you end up at origin, you were at the lowest node
				if (!current->parent) {
					current = old;
					beforeBegin = true;
					return ;
				}
			}
			moveTo(_parent);
		}

		void append(pointer ptr) {
			if (!_comp(*ptr, *current->data) && !_comp(*current->data, *ptr)) {
				_allocator.deallocate(current->data);
				current->data = ptr;
				return ;
			}
			int nextPos = this->evalNextPos(ptr);
			if (!this->isSideEmpty(nextPos)) {
				this->moveTo(nextPos);
				this->append(ptr);
				return ;
			}
			// TODO Add child creation
			current->setChild(nextPos);
		}

		bool find(const value_type & val) {
			if (!_comp(val, *current->data) && !_comp(*current->data, val))
				return true;

			int nextPos = this->evalNextPos(val);
			if (!this->isSideEmpty(nextPos)) {
				this->moveTo(nextPos);
				return this->find(val);
			}
			return false ;
		}

		size_type getSize() const {
			return _size;
		}

		reference operator*() {
			return *current->data;
		} // dereference

		const reference operator*() const {
			return *current->data;
		} // dereference

		pointer operator->() {
			return current->data;
		} // structure dereference

		const pointer operator->() const {
			return current->data;
		} // structure dereference

		void leftmost() {
			this->resetCurrent();
			if (this->isSideEmpty(_left))
				return ;
			this->moveTo(_left);
			this->leftmost();
		}

		void rightmost() {
			this->resetCurrent();
			if (this->isSideEmpty(_right))
				return ;
			this->moveTo(_right);
			this->rightmost();
		}

		void resetCurrent() {
			current = origin;
		}

	private:
		int evalNextPos(pointer ptr) {
			if (_comp(*ptr, current->data))
				return _left;
			return _right;
		}

		bool isSideEmpty(int pos) {
			return !current->getChild(pos);
		}

		void moveTo(int pos) {
			if (pos == _parent) {
				current = current->parent;
				return ;
			}
			current = current->getChild(pos);
		}

		void leftmostFromCurrent() {
			if (this->isSideEmpty(_left))
				return ;
			this->moveTo(_left);
			this->leftmost();
		}

		void rightmostFromCurrent() {
			if (this->isSideEmpty(_right))
				return ;
			this->moveTo(_right);
			this->rightmost();
		}

	public:
		node *origin;
		node *current;
		node *tmp;
		bool pastTheEnd;
		bool beforeBegin;
	private:
		allocator_type _allocator;
		size_type _size;
		compare _comp;
	};
}

#endif //INC_42_TREE_HPP
