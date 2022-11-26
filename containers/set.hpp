/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:23:32 by apommier          #+#    #+#             */
/*   Updated: 2022/11/26 17:04:29 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./iterators/bidirectionnal_iterator.hpp"
#include "./iterators/pair.hpp"
#include "./iterators/make_pair.hpp"
#include "vector.hpp"

#define RED 1
#define BLACK 0
#define _end 0

//typedef typename Alloc::template rebind<s_node<T> >::other

namespace ft
{

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T> > >

class set
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
	
	class value_compare;

	protected :

		key_compare			_comp;
		allocator_type		_alloc;
		node_allocator_type	_node_alloc;
		
		node				*_root;
		size_type			_size;

	public :
	
	
	struct node{
		value_type	data;
		node		*parent;
		node		*right;
		node		*left;
		bool		color;

		//node() : parent(0), right(set::_end), left(set::_end), color(0) {}
		node(key_type const &key, mapped_type const &val) 
		: data(ft::make_pair(key, val)), parent(0), right(_end), left(_end), color(0)
		{}
			//std::cout << "end in construct= " << _end << std::endl;
	};
	//-----------------------------
	//-----PRIVATE MEMBER TYPE-----
	//-----------------------------

	
	public :

	//---------------------------------------
	//---------COPLIEN FORM FUNCTION---------
	//---------------------------------------
	
	explicit set( const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc), _root(_end)
	{
		//_end = _node_alloc.allocate(1);
		//_node_alloc.construct(_end, node());
		_size = 0;
	}
	
	template< class InputIt >
	set( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc), _root(_end) 
	{
		_size = 0;
		//_end = _node_alloc.allocate(1);
		//_node_alloc.construct(_end, node());
		this->insert(first, last);	
	}
	
	set( const set& x)
	{
		*this = x;
	}
	
	~set()
	{
		
	}

	set& operator=(const set& x)
	{
		_comp = x._comp;
		_alloc = x._alloc;
		_node_alloc = x._node_alloc;
		_root = x._root;
		//_end = x._end;
		_size = x._size;
		return (*this);
	}

	//----------------------------------
	//---------MEMBER FUNCTION----------
	//----------------------------------

		//-------------------------
		//--------Iterators--------
		//-------------------------
	iterator begin()
	{
		return iterator(_root, _root);
	}
	
	const_iterator begin() const
	{
		return const_iterator(_root, _root);
	}
	
	iterator end()
	{
		return iterator(_root, _end);
	}
	
	const_iterator end() const
	{
		return const_iterator(_root, _end);
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
		//ft::pair<> new_pair = ft::make_pair(k, mapped_type());
		value_type	new_pair = ft::make_pair(k, mapped_type());
		
		if (tmp.base() == _end)
			return this->insert_node(new_pair.first, new_pair.second)->data.second; //??????
		else
			return ((*tmp).second);
	}
	
	mapped_type& at (const key_type& k)
	{
		iterator tmp = this->find(k);
		
		if (tmp->m == _end)
			throw (std::out_of_range("ft::set::at"));
		else
			return (*tmp.pair.second);
	}
	
	const mapped_type& at (const key_type& k) const
	{
		iterator tmp = this->find(k);
		
		if (tmp->m == _end)
			throw (std::out_of_range("ft::set::at"));
		else
			return (*tmp.pair.second);
	}
	
		//-------------------------
		//--------Modifiers--------
		//-------------------------
	ft::pair<iterator,bool> insert (const value_type& val)
	{
		// if (this->insert_node(val.first, val.second))
		// 	_size++;
		node *pt = new_node(val.first, val.second);
		_root = insert_node(_root, pt);
		fixViolation(_root, pt);
	}	
	
	iterator insert (iterator position, const value_type& val)
	{
		(void)position;
		// if (this->insert_node(val.first, val.second))
		// 	_size++;
		node *pt = new_node(val.first, val.second);
		_root = insert_node(_root, pt);
		fixViolation(_root, pt);
	}
	
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{
		int i = 0;
		while (first != last)
		{
			// std::cout << "i === " << i++ << std::endl;
			// if (this->insert_node(_root, new_node((*first).first, (*first).second)))
			// 	_size++;
			// first++;
			node *pt = new_node((*first).first, (*first).second);
			_root = insert_node(_root, pt);
			fixViolation(_root, pt);
			first++;
		}
	}
	
	void erase (iterator position)
	{
		delete_node(position.base());
	}
	
	size_type erase (const key_type& k)
	{
		delete_node(find(k).base());
		return(1);
	}
	
	void erase (iterator first, iterator last)
	{
		while (first != last)
		{
			delete_node(first.base());
			first++;
		}
	}
	
	void swap (set& x)
	{
		set tmp;

		tmp->_comp = _comp;
		tmp->_alloc = _alloc;
		tmp->_node_alloc = _node_alloc;
		tmp->_root = _root;
		//tmp->_end = _end;
		tmp->_size = _size;

		_comp = x->_comp;
		_alloc = x->_alloc;
		_node_alloc = x->_node_alloc;
		_root = x->_root;
		//_end = x->_end;
		_size = x->_size;

		x->_comp = tmp-> _comp;
		x->_alloc = tmp->_alloc;
		x->_node_alloc = tmp->_node_alloc;
		x->_root = tmp->_root;
		//x->_end = tmp->_end;
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
		return (_comp);
	}
	
	value_compare value_comp() const
	{
		return (value_compare(_comp));
	}
	
	
		//-------------------------
		//-------Operations--------
		//------------------------- 

	iterator find (const key_type& k)
	{
		node *x = _root;
		int i = 0;
		while (x != _end && x->data.first != k)
		{
			std::cout << "i === " << i << std::endl;
			if (k > x->data.first)
				x = x->left;
			else
				x = x->right;
			i++;
		}
		return (iterator(_root, _end, x));
	}
	
	const_iterator find (const key_type& k) const
	{
		node *x = _root;
		
		while (x != _end && x->data.first != k)
		{
			if (k > x->data.first)
				x = x->left;
			else
				x = x->right;
		}
		return (iterator(_root, _end, x));
	}
	
	size_type count (const key_type& k) const
	{
		if (find(k)->m == _end)
			return (0);
		return (1);
	}
	
	iterator lower_bound (const key_type& k)
	{
		iterator it = begin(), ite = end();

		while (it != ite && !(_comp((*it).first, k)))
			it++;
		return (it);
	}
	
	const_iterator lower_bound (const key_type& k) const
	{
		const_iterator it = begin(), ite = end();

		while (it != ite && !(_comp((*it).first, k)))
			it++;
		return (it);
	}
	
	iterator upper_bound (const key_type& k)
	{
		iterator it = begin(), ite = end();

		while (it != ite && !(_comp((*it).first, k)))
			it++;
		return (it);
	}
	
	const_iterator upper_bound (const key_type& k) const
	{
		const_iterator it = begin(), ite = end();

		while (it != ite && _comp((*it).first, k))
			it++;
		return (it);
	}
	
	ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		return (ft::make_pair(lower_bound(k), upper_bound(k)));
	}
	
	ft::pair<iterator,iterator>			 equal_range (const key_type& k)
	{
		return (ft::make_pair(lower_bound(k), upper_bound(k)));
	}

	/* ************************************************************************** */
	/* ************************************************************************** */
	/* ************************************************************************** */
	/* ******************************TREE FUNCTIONS****************************** */
	/* ************************************************************************** */
	/* ************************************************************************** */
	/* ************************************************************************** */

	private :

	void rotateLeft(node *&root, node *&pt)
	{
		node *pt_right = pt->right;
		pt->right = pt_right->left;
		if (pt->right != NULL)
			pt->right->parent = pt;
		pt_right->parent = pt->parent;
		if (pt->parent == NULL)
			root = pt_right;
		else if (pt == pt->parent->left)
			pt->parent->left = pt_right;
		else
			pt->parent->right = pt_right;
		pt_right->left = pt;
		pt->parent = pt_right;
	}
	
	
	void rotateRight(node *&root, node *&pt)
	{
	
		node *pt_left = pt->left;
		pt->left = pt_left->right;
		if (pt->left != NULL)
			pt->left->parent = pt;
		pt_left->parent = pt->parent;
		if (pt->parent == NULL)
			root = pt_left;
		else if (pt == pt->parent->left)
			pt->parent->left = pt_left;
		else
			pt->parent->right = pt_left;
		pt_left->right = pt;
		pt->parent = pt_left;
	}

	node* insert_node(node* root, node *pt)
	{
		/* If the tree is empty, return a new node */
		if (root == NULL)
		   return pt;	 
		/* Otherwise, recur down the tree */
		if (pt->data < root->data)
		{
			root->left = insert_node(root->left, pt);
			root->left->parent = root;
		}
		else if (pt->data > root->data)
		{
			root->right = insert_node(root->right, pt);
			root->right->parent = root;
		}
		/* return the (unchanged) node pointer */
		return root;
	}

	void fixViolation(node *&root, node *&pt)
	{
		node *parent_pt = NULL;
		node *grand_parent_pt = NULL;
		while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
		{
			parent_pt = pt->parent;
			grand_parent_pt = pt->parent->parent;
			/*  Case : A Parent of pt is left child of Grand-parent of pt */
			if (parent_pt == grand_parent_pt->left)
			{
				node *uncle_pt = grand_parent_pt->right;
				/* Case : 1 The uncle of pt is also red Only Recoloring required */
				if (uncle_pt != NULL && uncle_pt->color == RED)
				{
					grand_parent_pt->color = RED;
					parent_pt->color = BLACK;
					uncle_pt->color = BLACK;
					pt = grand_parent_pt;
				}
				else
				{
					/* Case : 2 pt is right child of its parent Left-rotation required */
					if (pt == parent_pt->right)
					{
						rotateLeft(root, parent_pt);
						pt = parent_pt;
						parent_pt = pt->parent;
					}
	 				/* Case : 3 pt is left child of its parent Right-rotation required */
					rotateRight(root, grand_parent_pt);
					swapColors(parent_pt, grand_parent_pt);
					pt = parent_pt;
				}
			}
			/* Case : B Parent of pt is right child of Grand-parent of pt */
			else
			{
				node *uncle_pt = grand_parent_pt->left;
				/*  Case : 1 The uncle of pt is also red Only Recoloring required */
				if ((uncle_pt != NULL) && (uncle_pt->color == RED))
				{
					grand_parent_pt->color = RED;
					parent_pt->color = BLACK;
					uncle_pt->color = BLACK;
					pt = grand_parent_pt;
				}
				else
				{
					/* Case : 2 | pt is left child of its parent | Right-rotation required */
					if (pt == parent_pt->left)
					{
						rotateRight(root, parent_pt);
						pt = parent_pt;
						parent_pt = pt->parent;
					}
					/* Case : 3 pt is right child of its parent Left-rotation required */
					rotateLeft(root, grand_parent_pt);
					swapColors(parent_pt, grand_parent_pt);
					pt = parent_pt;
				}
			}
		}
		root->color = BLACK;
	}

	/* ************************************************************************** */
	/* **********************************DELETE********************************** */
	/* ************************************************************************** */


	node *uncle(node *x)
	{
		if (x->parent == NULL or x->parent->parent == NULL)
			return NULL;
		if (x->parent->isOnLeft())
			return x->parent->parent->right;
		else
			return x->parent->parent->left;
	}

	bool isOnLeft(node *x) { return this == x->parent->left; }
 
	// returns pointer to sibling
	node *sibling(node *x)
	{
		// sibling null if no parent
		if (x->parent == NULL)
			return NULL;
		if (isOnLeft())
			return x->parent->right;
		return x->parent->left;
	}
 
  // moves node down and moves given node in its place
	void moveDown(node *nParent, node *x)
	{
		if (x->parent != NULL)
		{
			if (isOnLeft())
				x->parent->left = nParent;
		else
			x->parent->right = nParent;
		}
		nParent->parent = x->parent;
		x->parent = nParent;
	}

	bool hasRedChild(node *x)
	{
		return (x->left != NULL and x->left->color == RED) or (x->right != NULL and x->right->color == RED);
	}
 
	void swapColors(node *x1, node *x2)
	{
		bool temp;
		temp = x1->color;
		x1->color = x2->color;
		x2->color = temp;
	}
 
	void swapValues(node *u, node *v)
	{
		int temp;
		temp = u->val;
		u->val = v->val;
		v->val = temp;
	}
 
	void fixRedRed(node *x)
	{
		// if x is root color it black and return
		if (x == _root)
		{
		  x->color = BLACK;
		  return;
		}
		// initialize parent, grandparent, uncle
		node *parent = x->parent, *grandparent = parent->parent,
			 *uncle = x->uncle();
		if (parent->color != BLACK)
		{
			if (uncle != NULL && uncle->color == RED)
			{
				// uncle red, perform recoloring and recurse
				parent->color = BLACK;
				uncle->color = BLACK;
				grandparent->color = RED;
				fixRedRed(grandparent);
			}
			else
			{
				// Else perform LR, LL, RL, RR
				if (parent->isOnLeft())
				{
					if (x->isOnLeft())
					{
						// for left right
						swapColors(parent, grandparent);
			  		}
					else
					{
						leftRotate(parent);
						swapColors(x, grandparent);
					}
			 		// for left left and left right
			  		rightRotate(grandparent);
				}
				else
				{
					if (x->isOnLeft())
					{
						// for right left
						rightRotate(parent);
						swapColors(x, grandparent);
					}
					else
						swapColors(parent, grandparent);
				// for right right and right left
				leftRotate(grandparent);
			}
		  }
		}
	} 

	// find node that do not have a left child
	// in the subtree of the given node
	node *successor(node *x)
	{
		node *temp = x;
		
		while (temp->left != NULL)
			temp = temp->left;
		return temp;
	}
 
  // find node that replaces a deleted node in BST
	node *replace_node(node *x)
	{
		// when node have 2 children
		if (x->left != NULL and x->right != NULL)
			return successor(x->right);
		// when leaf
		if (x->left == NULL and x->right == NULL)
			return NULL;
		// when single child
		if (x->left != NULL)
			return x->left;
		else
			return x->right;
  }

   // deletes the given node
	void deleteNode(node *v)
	{
		node *u = replace_node(v);

		// True when u and v are both black
		bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
		node *parent = v->parent;
		if (u == NULL)
		{
			// u is NULL therefore v is leaf
			if (v == _root)
				_root = NULL;// v is root, making root null
			else
			{
				if (uvBlack)
				{
					// u and v both black
					// v is leaf, fix double black at v
					fixDoubleBlack(v);
				}
				else
				{
					// u or v is red
					if (v->sibling() != NULL)
					// sibling is not null, make it red"
					v->sibling()->color = RED;
				}
				// delete v from the tree
				if (v->isOnLeft())
					parent->left = NULL;
				else
					parent->right = NULL;
			}
			delete v;
			return;
		}
	if (v->left == NULL or v->right == NULL)
	{
		// v has 1 child
		if (v == _root)
		{
			// v is root, assign the value of u to v, and delete u
			v->val = u->val;
			v->left = v->right = NULL;
			delete u;
		}
		else
		{
			// Detach v from tree and move u up
			if (v->isOnLeft())
				parent->left = u;
			else
				parent->right = u;
			delete v;
			u->parent = parent;
			if (uvBlack)
				fixDoubleBlack(u);// u and v both black, fix double black at u
			else
				u->color = BLACK;// u or v red, color u black
		}
		return;
	}
	// v has 2 children, swap values with successor and recurse
	swapValues(u, v);
	deleteNode(u);
  }

	//template<typename T_node>
	node *new_node(key_type key, mapped_type val)
	{
		node *ret;

		ret = _node_alloc.allocate(1);
		_node_alloc.construct(ret, node(key, val));

		//ret = _node_alloc::allocate(1);
		//_node_alloc::construct(ret, node(key, val));
		return (ret);
	}
	
}; //end of set class

//----------------------------------
//----------COMPARE CLASS-----------
//----------------------------------

template <class Key, class T, class Compare, class Alloc>
class set<Key,T,Compare,Alloc>::value_compare //man set::value_compare
{  // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
	friend class set;
	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}  // constructed with set's comparison object
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
};

}