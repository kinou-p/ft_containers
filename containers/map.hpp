/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:50:18 by apommier          #+#    #+#             */
/*   Updated: 2022/11/24 17:45:57 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./iterators/bidirectionnal_iterator.hpp"
#include "./iterators/pair.hpp"

#define RED 1
#define BLACK 0

//typedef typename Alloc::template rebind<s_node<T> >::other

namespace ft
{

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key, T>>>

class map
{
	public :

	//-----------------------------
	//---------MEMBER TYPE---------
	//-----------------------------
	struct	node;

	typedef	Key													key_type;
	typedef	T													mapped_type;
	typedef	std::pair<const Key, T>								value_type;
	typedef	std::size_t											size_type;
	typedef	std::ptrdiff_t										difference_type;
	typedef	Compare												key_compare;
	typedef	Allocator											allocator_type;
	typedef typename Allocator::template rebind<node>::other	node_allocator_type;
	typedef	value_type&											reference;
	typedef	const value_type&									const_reference;
	typedef	typename Allocator::pointer							pointer;
	typedef	typename Allocator::const_pointer					const_pointer;
	typedef	ft::bidirectionnal_iterator							iterator; 
	typedef	ft::bidirectionnal_iterator							const_iterator;
	typedef	std::reverse_iterator<iterator>						reverse_iterator;
	typedef	std::reverse_iterator<const_iterator>				const_reverse_iterator;

	struct node{
		bool		color;
		node		*parent;
		node		*right;
		node		*left;
		value_type	pair;

		node(key_type &key, mapped_type &val) 
		: pair(make_pair(key, val)), parent(0), right(this->_end), left(this->_end), color(0) {}
	};
	//-----------------------------
	//-----PRIVATE MEMBER TYPE-----
	//-----------------------------
	private :

		key_compare			_comp;
		allocator_type		_alloc;
		node_allocator_type	_node_alloc;
		
		node				*_root;
		node				*_end;
		size_type			_size;
	
	public :

	//---------------------------------------
	//---------COPLIEN FORM FUNCTION---------
	//---------------------------------------
	
	explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
	{
		
	}
	
	template< class InputIt >
	map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
	{
		
	}
	
	map( const map& x)
	{
		
	}
	
	~map()
	{
		
	}

	map& operator=( const map& x )
	{
		
	}
	
	//----------------------------------
	//---------MEMBER FUNCTION----------
	//----------------------------------

		//-------------------------
		//--------Iterators--------
		//-------------------------
	iterator begin()
	{
		
	}
	
	const_iterator begin() const
	{
		
	}
	
	iterator end()
	{
		
	}
	
	const_iterator end() const
	{
		
	}
	
	reverse_iterator rbegin()
	{
		
	}
	
	const_reverse_iterator rbegin() const
	{
		
	}
	
	reverse_iterator rend()
	{
		
	}
	
	const_reverse_iterator rend() const
	{
		
	}
	
	
		//------------------------
		//--------Capacity--------
		//------------------------
	
	bool empty() const
	{
		if (!_size)
			return (1);
		return(0);
	}
	
	size_type size() const
	{
		return (_size);
	}
	
	size_type max_size() const
	{
		return (_alloc.max_size());
	}
	

		//------------------------------
		//--------Element access--------
		//------------------------------
	mapped_type& operator[] (const key_type& k)
	{
		
	}
	
	mapped_type& at (const key_type& k)
	{
		
	}
	
	const mapped_type& at (const key_type& k) const
	{
		
	}
	

		//-------------------------
		//--------Modifiers--------
		//-------------------------
	ft::pair<iterator,bool> insert (const value_type& val)
	{
		
	}	
	
	iterator insert (iterator position, const value_type& val)
	{
		
	}
	
	template <class InputIterator>  void insert (InputIterator first, InputIterator last)
	{
		
	}
	
	void erase (iterator position)
	{
		
	}
	
	size_type erase (const key_type& k)
	{
		
	}
	
	void erase (iterator first, iterator last)
	{
		
	}
	
	void swap (map& x)
	{
		
	}
	
	void clear()
	{
		
	}
	
		//-------------------------
		//--------Observers--------
		//-------------------------
	
	key_compare key_comp() const
	{
		
	}
	
	value_compare value_comp() const
	{
		
	}
	
	
		//-------------------------
		//-------Operations--------
		//------------------------- 

	iterator find (const key_type& k)
	{
		
	}
	
	const_iterator find (const key_type& k) const
	{
		
	}
	
	size_type count (const key_type& k) const
	{
		
	}
	
	iterator lower_bound (const key_type& k)
	{
		
	}
	
	const_iterator lower_bound (const key_type& k) const
	{
		
	}
	
	iterator upper_bound (const key_type& k)
	{
		
	}
	
	const_iterator upper_bound (const key_type& k) const
	{
		
	}
	
	ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		
	}
	
	ft::pair<iterator,iterator>			 equal_range (const key_type& k)
	{
		
	}

	/* ************************************************************************** */
	/* ******************************TREE FUNCTIONS****************************** */
	/* ************************************************************************** */

	private :
	
	template<typename T_node>
	node *new_node(key_type key, mapped_type val)
	{
		node *ret;
		
		ret = _node_alloc::allocate(1);
		_node_alloc::construct(ret, node(key, val));
		return (ret);
	}

	void left_rotate(node *elem) //x == elem
	{
		node *pt_right = elem->right;
		
		elem->right = pt_right->left;
		if (elem->right != NULL)
			elem->right->parent = elem;
 		pt_right->parent = elem->parent;
 		if (elem->parent == NULL)
		   _root = pt_right;
		else if (elem == elem->parent->left)
			elem->parent->left = pt_right;
		else
			elem->parent->right = pt_right;
		pt_right->left = elem;
		elem->parent = pt_right;
	}

	void right_rotate(node *elem)
	{
		node *pt_left = elem->left;

		elem->left = pt_left->right;
		if (elem->left != NULL)
			elem->left->parent = elem;
		pt_left->parent = elem->parent;
		if (elem->parent == NULL)
			_root = pt_left;
		 else if (elem == elem->parent->left)
			elem->parent->left = pt_left;
		 else
			elem->parent->right = pt_left;
		pt_left->right = elem;
		elem->parent = pt_left;
	}

	void delete_fix()
	{
		
	} 

	void delete_node()
	{
		
	} 

	void insert_fix(node *new_elem, node *parent)
	{
		node *uncle = NULL;
		
		while (new_elem->parent->color == RED)
		{
			if (new_elem->parent->parent && new_elem->parent == new_elem->parent->parent->left )
			{
				uncle = new_elem->parent->parent->right;
				if (uncle != _end && uncle->color == RED) //uncle is red == only recoloring
				{
					new_elem->parent->color = BLACK; //parent
					uncle->color = BLACK;
					new_elem->parent->parent->color = RED; //grandparent
					new_elem = new_elem->parent->parent;
				}
				else
				{
					if (new_elem == new_elem->parent->right) //if elem is right child
					{
						new_elem = new_elem->parent;
						left_rotate(new_elem);
					}
					new_elem->parent->color = BLACK;
			 		new_elem->parent->parent->color = RED;
					right_rotate(new_elem->parent->parent);
				}
			}
			else
			{
				uncle = new_elem->parent->parent->left;
				if (uncle != _end && uncle->color == RED) //uncle is red == only recoloring
				{
					new_elem->parent->color = BLACK; //parent
					uncle->color = BLACK;
					new_elem->parent->parent->color = RED; //grandparent
					new_elem = new_elem->parent->parent;
				}
				else
				{
					if (new_elem == new_elem->parent->left) //if elem is right child
					{
						new_elem = new_elem->parent;
						right_rotate(new_elem);
					}
					new_elem->parent->color = BLACK;
			 		new_elem->parent->parent->color = RED;
					left_rotate(new_elem->parent->parent);
				}
			}
		}
		_root->color = BLACK;
	}
	
	node *insert(key_type key, mapped_type val)
	{
		node	*x = _root;
		node	*new_parent;

		if (this->empty())
		{
			_root = new_node(key, val);
			_end = _root;
			_size = 1;
			return _root;
		}
		else
		{
			while (x != _end)
			{
				new_parent = x;
				if (key < x->key)
					x = x->right;
				else if (key > x->key)
					x = x->left;
				else
					return (x);
			}
			x = new_node(key, val);
			x->parent = new_parent;
			if (key < new_parent.key)
				new_parent.left = x;
			else
				new_parent.right = x;
			x->color = RED;
			return (x);
		}
		this->insert_fix();
	}
};

}