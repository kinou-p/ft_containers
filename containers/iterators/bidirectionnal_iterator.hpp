/* ************************************************************************** */
/*																			*/
/*														:::		::::::::	 */
/*	 bidirectionnal_iterator.hpp						:+:		:+:	:+:	 */
/*													+:+ +:+		 +:+	 */
/*	 By: apommier <apommier@student.42.fr>			+#+	+:+		 +#+		*/
/*												+#+#+#+#+#+	 +#+			 */
/*	 Created: 2022/11/22 14:50:53 by apommier			#+#	#+#			 */
/*	 Updated: 2022/11/27 21:22:24 by apommier		 ###	 ########.fr		 */
/*																			*/
/* ************************************************************************** */

#pragma once

//#define _end 0

namespace ft
{

template<class T, class Node>
class bidirectionnal_iterator
{
	public :
	
		typedef T							value_type;
		typedef	std::ptrdiff_t				difference_type;
		typedef	T*							pointer;
		typedef	const T*					const_pointer;
		typedef	T&							reference;
		typedef	const T&					const_reference;
		typedef bidirectionnal_iterator		iterator_category;
		typedef Node						node;
		typedef Node*						NodePtr;
		
	private :
		
		NodePtr _root;
		NodePtr _end; 
		NodePtr _node;

	public :

		bidirectionnal_iterator() : _root(NULL), _end(NULL), _node(NULL) {}
		bidirectionnal_iterator(NodePtr root, NodePtr end, NodePtr node) : _root(root), _end(end), _node(node) { /*_end = NULL*/ }
		bidirectionnal_iterator(bidirectionnal_iterator const &rhs) { *this = rhs; }

		~bidirectionnal_iterator() {}

		bidirectionnal_iterator &operator=(bidirectionnal_iterator const &rhs)
		{
			if (this != &rhs) 
			{
				this->_root = rhs._root;
				this->_end = rhs._end;
				this->_node = rhs._node;
			}
			return (*this);
		}
		
		operator bidirectionnal_iterator<const T, const Node>() const
		{
		 	return (bidirectionnal_iterator<const T, const Node>(_root, _end, _node));
		}

		NodePtr base() { return (_node); }

		friend bool operator==(const bidirectionnal_iterator &rhs, const bidirectionnal_iterator &lhs)
		{
			if (!lhs._node && !rhs._node)
			 	return (true);
			else if (!lhs._node || !rhs._node)
			 	return (false);
			return (lhs._node == rhs._node);
		}
		
		friend bool operator!=(const bidirectionnal_iterator &rhs, const bidirectionnal_iterator &lhs)
		{
			if (!lhs._node && !rhs._node)
			 	return (false);
			else if (!lhs._node || !rhs._node)
			 	return (true);
			return (lhs._node != rhs._node);
		}
		
		reference operator*() { return (_node->data); }
		const_reference	operator*() const { return (_node->data); }
		pointer operator->() { return (&(_node->data)); }
		const_pointer operator->() const { return (&(_node->data)); }
		


			bidirectionnal_iterator &operator++() {
				if (_node != _end)
					_node = successor(_node);
				return (*this);
			}

			bidirectionnal_iterator operator++(int) {
				bidirectionnal_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			bidirectionnal_iterator &operator--() {
				if (_node == _end) {
					_node = maximum(_root);
				}
				else
					_node = predecessor(_node);
				return (*this);
			}

			bidirectionnal_iterator operator--(int) {
				bidirectionnal_iterator tmp(*this);
				operator--();
				return (tmp);
			}


			NodePtr maximum(NodePtr ptr) {
				while (ptr->right != _end)
					ptr = ptr->right;
				return (ptr);
			}

			NodePtr minimum(NodePtr ptr) {
				while (ptr->left != _end)
					ptr = ptr->left;
				return (ptr);
			}

			NodePtr predecessor(NodePtr x) {
				if (x->left != _end)
				{
					return maximum(x->left);
				}
				NodePtr y = x->parent;
				while (y != NULL && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			NodePtr successor(NodePtr x) {
				if (x->right != _end)
					return minimum(x->right);
				NodePtr y = x->parent;
				while (y != NULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				if (y == NULL)
					return _end;
				return y;
			}

	private :

};

}