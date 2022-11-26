/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectionnal_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:50:53 by apommier          #+#    #+#             */
/*   Updated: 2022/11/26 16:26:57 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define _end 0

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
		typedef Node						node_type;
		
	private :
		
		node_type *_root;
		node_type *_node;

	public :

		bidirectionnal_iterator() : _node(NULL) {}
		bidirectionnal_iterator(node_type *root, node_type *node) : _root(root), _node(node) {}
		bidirectionnal_iterator(bidirectionnal_iterator const &rhs) { *this = rhs; }

		~bidirectionnal_iterator() {}

		bidirectionnal_iterator &operator=(bidirectionnal_iterator const &rhs)
		{
			if (this != &rhs) 
			{
				this->_root = rhs._root;
				//this->_end = rhs._end;
				this->_node = rhs._node;
			}
			return (*this);
		}
		
		operator bidirectionnal_iterator<const T, const Node>() const
		{
		 	return (bidirectionnal_iterator<const T, const Node>(_root, _node));
		}

		node_type	*base() { return (_node); }

		friend bool operator==(const bidirectionnal_iterator &rhs, const bidirectionnal_iterator &lhs) { return (lhs._node == rhs._node); }
		friend bool operator!=(const bidirectionnal_iterator &rhs, const bidirectionnal_iterator &lhs) { return (lhs._node != rhs._node); }
		
		reference operator*() { return (_node->data); }
		const_reference	operator*() const { return (_node->data); }
		pointer operator->() { return (&(_node->data)); }
		const_pointer operator->() const { return (&(_node->data)); }
		
		bidirectionnal_iterator &operator ++()
		{
			if (_node != NULL)
				_node = successor(_node);
			return (*this);
		}
		
		bidirectionnal_iterator operator ++(int)
		{
			bidirectionnal_iterator tmp(*this);
			++(*this);
			return (tmp);
		}
		
		bidirectionnal_iterator &operator --()
		{
			if (_node == _end)
				_node = maximum(_root);
			else
				_node = predecessor(_node);
			return (*this);
		}
		
		bidirectionnal_iterator operator --(int)
		{
			bidirectionnal_iterator tmp(*this);
			++(*this);
			return (tmp);
		}
	
	private :

		node_type *maximum(node_type *ptr)
		{
			while (ptr->right != _end)
				ptr = ptr->right;
			return (ptr);
		}
		
		node_type *minimum(node_type *ptr)
		{
			while (ptr->left != _end)
				ptr = ptr->left;
			return (ptr);
		}

		node_type *predecessor(node_type *x)
		{
			if (x->left != _end)
			{
				return maximum(x->left);
			}
			node_type *y = x->parent;
			while (y != NULL && x == y->left)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}
		
		node_type *successor(node_type *x)
		{
			if (x->right != _end)
				return minimum(x->right);
			node_type *y = x->parent;
			while (y != NULL && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			if (y == NULL)
				return _end;
			return y;
		}
};

}