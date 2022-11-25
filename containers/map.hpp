/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:50:18 by apommier          #+#    #+#             */
/*   Updated: 2022/11/25 17:48:41 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./iterators/bidirectionnal_iterator.hpp"
#include "./iterators/pair.hpp"
#include "vector.hpp"

#define RED 1
#define BLACK 0

//typedef typename Alloc::template rebind<s_node<T> >::other

namespace ft
{

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T>>>

class map
{
	public :

	//-----------------------------
	//---------MEMBER TYPE---------
	//-----------------------------
	struct	node;

	typedef	Key													key_type;
	typedef	T													mapped_type;
	typedef	ft::pair<const Key, T>								value_type;
	typedef	std::size_t											size_type;
	typedef	std::ptrdiff_t										difference_type;
	typedef	Compare												key_compare;
	typedef	Compare												value_compare;
	typedef	Allocator											allocator_type;
	typedef typename Allocator::template rebind<node>::other	node_allocator_type;
	typedef	value_type&											reference;
	typedef	const value_type&									const_reference;
	typedef	typename Allocator::pointer							pointer;
	typedef	typename Allocator::const_pointer					const_pointer;
	typedef	ft::bidirectionnal_iterator<value_type, node>					iterator; 
	typedef	ft::bidirectionnal_iterator<value_type const, node const>	const_iterator;
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
	
	explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : _alloc(alloc)
	{
		
	}
	
	template< class InputIt >
	map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : _alloc(alloc)
	{
		
	}
	
	map( const map& x)
	{
		*this = x;
	}
	
	~map()
	{
		
	}

	map& operator=(const map& x)
	{
		_comp = x->_comp;
		_alloc = x->_alloc;
		_node_alloc = x->_node_alloc;
		_root = x->_root;
		_end = x->_end;
		_size = x->_size;
	}
	
	//----------------------------------
	//---------MEMBER FUNCTION----------
	//----------------------------------

		//-------------------------
		//--------Iterators--------
		//-------------------------
	iterator begin()
	{
		return iterator(_root);
	}
	
	const_iterator begin() const
	{
		return const_iterator(_root);
	}
	
	iterator end()
	{
		return iterator(_end);
	}
	
	const_iterator end() const
	{
		return const_iterator(_end);
	}
	
	reverse_iterator rbegin()
	{
		return reverse_iterator(this->end());
	}
	
	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(this->end());
	}
	
	reverse_iterator rend()
	{
		return reverse_iterator(this->begin());
	}
	
	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(this->begin());
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
		iterator tmp = this->find(k);
		
		if (tmp->m == _end)
			return (*((this->insert(make_pair(k, mapped_type()))).second)); //??????
		else
			return (*tmp.pair->second);
	}
	
	mapped_type& at (const key_type& k)
	{
		iterator tmp = this->find(k);
		
		if (tmp->m == _end)
			throw (std::out_of_range("ft::map::at"));
		else
			return (*tmp.pair->second);
	}
	
	const mapped_type& at (const key_type& k) const
	{
		iterator tmp = this->find(k);
		
		if (tmp->m == _end)
			throw (std::out_of_range("ft::map::at"));
		else
			return (*tmp.pair->second);
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
		map tmp;

		tmp->_comp = _comp;
		tmp->_alloc = _alloc;
		tmp->_node_alloc = _node_alloc;
		tmp->_root = _root;
		tmp->_end = _end;
		tmp->_size = _size;

		_comp = x->_comp;
		_alloc = x->_alloc;
		_node_alloc = x->_node_alloc;
		_root = x->_root;
		_end = x->_end;
		_size = x->_size;

		x->_comp = tmp-> _comp;
		x->_alloc = tmp->_alloc;
		x->_node_alloc = tmp->_node_alloc;
		x->_root = tmp->_root;
		x->_end = tmp->_end;
		x->_size = tmp->_size;
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
		node *x = _root;
		
		while (x != _end && x->pair->first != k)
		{
			if (k > x->pair->first)
				x = x->left;
			else
				x = x->right;
		}
		return (iterator(x));
	}
	
	const_iterator find (const key_type& k) const
	{
		node *x = _root;
		
		while (x != _end && x->pair->first != k)
		{
			if (k > x->pair->first)
				x = x->left;
			else
				x = x->right;
		}
		return (iterator(x));
	}
	
	size_type count (const key_type& k) const
	{
		if (find(k)->m == _end)
			return (0);
		return (1);
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
	
	void inorderHelper()
	{
	    if (_root == NULL)
	        return;
	    inorderHelper(_root->left);
	    std::cout << _root->data << "  ";
	    inorderHelper(_root->right);
	}
	
	void levelOrderHelper()
	{
    	if (_root == NULL)
    	    return;
    	ft::vector<node *> v;
    	v.push(_root);
    	while (!v.empty())
    	{
    	    node *temp = v.front();
    	    std::cout << temp->data << "  ";
    	    v.pop();
    	    if (temp->left != NULL)
    	        v.push(temp->left);
    	    if (temp->right != NULL)
    	        v.push(temp->right);
    	}
	}

	template<typename T_node>
	node *new_node(key_type key, mapped_type val)
	{
		node *ret;

		ret = _alloc.allocate(1);
		_alloc.construct(ret, node(key, val));

		//ret = _node_alloc::allocate(1);
		//_node_alloc::construct(ret, node(key, val));
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

	void delete_node(node *z)
	{
		node *x;
		node *y;
		
		if (z->left == _end || z->right == _end)//case1
			y = z;
		// else //case2
		// 	y = TREE-SUCCESSOR(z);
		if (y->left != _end)
			x = y->left;
		else
			x = y->right;
		x->parent = y->parent; // Do this, even if x is _end
		if (y->parent == _end)
			_root = x;
		else if (y == y->parent->left) //(*if y is a left child.*)
			y->parent->left = x;
		else 
			y->parent->right = x; //(*if y is a right child.*)
		if (y != z )
			z->pair->first = y->pair->first;
		//copy y’s satellite data into z
		if (y->color == BLACK)
			delete_fix(x);
		return (y);
	}

	void delete_fix(node *x)
	{
		node *w;
		node *z;
		
		while (x != _root && x->color == BLACK)
		{
			if (x == x->parent->left)
			{
				w = x->parent->right;
				if (w->color == RED) // Case 1
				{
					w->color = BLACK;
					x->parent->color = RED;
					left_rotate(x->parent);
					w = x->parent->right;
				}
				if (w->left->color == BLACK && w->right->color == BLACK)// Case 2
				{
					w->color = RED; 
					x = x->parent;
					x->parent = z->parent->parent;
				}
				else if (w->right->color == BLACK) // Case 3
				{
					w->left->color = BLACK;
					w->color = RED;
					right_rotate(w);
					w = x->parent->right;
				}
				w->color = x->parent->color; // Case 4
				x->parent->color = BLACK; // Case 4
				w->right->color = BLACK; // Case 4
				left_rotate(x->parent); // Case 4
				x = _root; // Case 4
			}
			else //same as 3 - 21 with “right” and “left” exchanged
			{
				w = x->parent->left;
				if (w->color == RED) // Case 1
				{
					w->color = BLACK; // Case 1
					x->parent->color = RED; // Case 1
					right_rotate(x->parent); // Case 1
					w = x->parent->left; // Case 1
				}
				if (w->right->color == BLACK && w->left->color == BLACK)
				{
					w->color = RED; // Case 2
					x = x->parent; // Case 2
					x->parent = z->parent->parent; // Case 2
				}
				else if (w->left->color == BLACK) // Case 3
				{
					w->right->color = BLACK; // Case 3
					w->color = RED; // Case 3
					left_rotate(w); // Case 3
					w = x->parent->left; // Case 3
				}
				w->color = x->parent->color; // Case 4
				x->parent->color = BLACK; // Case 4
				w->left->color = BLACK; // Case 4
				right_rotate(x->parent); // Case 4
				//x = _root; // Case 4 ???
				//left
			}
		}
		x->color = BLACK;
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
			if (key < new_parent->key)
				new_parent->left = x;
			else
				new_parent->right = x;
			x->color = RED;
			return (x);
		}
		this->insert_fix();
	}
};

}