//
// Created by Millefeuille on 01/05/2022.
//

#ifndef NODE_HPP
#define NODE_HPP

#include <stdexcept>

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class Node {
	public:
		typedef T value_type;
		typedef Alloc allocator_type;

		typedef std::allocator<Node> node_allocator;
		typedef typename node_allocator::pointer node_pointer;
		typedef typename node_allocator::reference node_reference;

		enum e_status {
			_left = 0,
			_right = 1
		};

		Node(value_type val = value_type()) : parent(node_pointer()) {
			_children[_left] = node_pointer();
			_children[_right] = node_pointer();
			allocator_type().construct(&data, val);
			at = -1;
			_nodeAllocator = node_allocator();
		}

		Node(const Node & src) : at() {
			allocator_type().construct(&data, value_type());
			_children[_left] = node_pointer();
			_children[_right] = node_pointer();
			*this = src;
		}

		void deleteChildren() {
			if (_children[_left]) {
				_nodeAllocator.destroy(_children[_left]);
				_nodeAllocator.deallocate(_children[_left], 1);
			}
			if (_children[_right]) {
				_nodeAllocator.destroy(_children[_right]);
				_nodeAllocator.deallocate(_children[_right], 1);
			}
			_children[_left] = node_pointer();
			_children[_right] = node_pointer();
		}

		~Node() {
			deleteChildren();
		}

		Node& operator=(const Node& rhs) {
			if (&rhs == this)
				return *this;
			allocator_type().construct(&data, rhs.data);
			_nodeAllocator = rhs._nodeAllocator;
			if (!rhs.parent)
				parent = node_pointer();

			deleteChildren();
			if (rhs._children[_left]) {
				node_pointer newC = _nodeAllocator.allocate(1);
				_nodeAllocator.construct(newC, *rhs._children[_left]);
				setChild(newC, _left);
			}
			if (rhs._children[_right]) {
				node_pointer newC = _nodeAllocator.allocate(1);
				_nodeAllocator.construct(newC, *rhs._children[_right]);
				setChild(newC, _right);
			}
			return *this;
		}

		static node_pointer leftmostFrom(node_pointer current) {
			if (!current->getChild(_left))
				return current;
			return leftmostFrom(current->getChild(_left));
		}

		static node_pointer rightmostFrom(node_pointer current) {
			if (!current->getChild(_right))
				return current;
			return rightmostFrom(current->getChild(_right));
		}

		node_pointer next() const {

			// If you have a right node, go at the leftmost from this node
			if (getChild(_right))
				return leftmostFrom(getChild(_right));

			// If you are at origin, and have no right node, you are the highest
			if (!parent)
				return node_pointer(this);

			// Otherwise, If you are at left of your parent, go up once
			if (at == _left)
				return parent;

			// Otherwise, Go up until you are not at right of your parent
			node_pointer cur = node_pointer(this);
			for (; !cur->parent || cur->at == _right; cur = cur->parent)
				// If you end up at origin, you were at the highest node
				if (!cur->parent)
					return node_pointer(this);
			return cur->parent;
		}

		node_pointer prev() const {
			// If you have a left node, go at the rightmost from this node
			if (getChild(_left))
				return rightmostFrom(getChild(_left));

			// If you are at origin, and have no left node, you are the highest
			if (!parent)
				return node_pointer(this);

			// Otherwise, If you are at right of your parent, go up once
			if (at == _right)
				return parent;

			// Otherwise, Go up until you are not at left of your parent
			node_pointer cur = node_pointer(this);
			for (; !cur->parent || cur->at == _left; cur = cur->parent)
				// If you end up at origin, you were at the lowest node
				if (!cur->parent)
					return node_pointer(this);
			return cur->parent;
		}

		Node *getChild(int index) const {
			if (index > _right || index < _left)
				throw std::out_of_range("out of range");
			return _children[index];
		}

		void setChild(Node *child, int index) {
			if (index > _right || index < _left)
				throw std::out_of_range("out of range");
			child->parent = this;
			_children[index] = child;
			_children[index]->at = index;
		}

		node_pointer parent;
		value_type data;
		int at;
	private:
		node_pointer _children[2];
		node_allocator _nodeAllocator;
	};
}

#endif //NODE_HPP
