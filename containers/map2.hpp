/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map.hpp											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: apommier <apommier@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/26 15:23:32 by apommier		  #+#	#+#			 */
/*   Updated: 2022/11/27 11:46:38 by apommier		 ###   ########.fr	   */
/*																			*/
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

		node(key_type const &key, mapped_type const &val) 
		: data(ft::make_pair(key, val)), parent(0), right(_end), left(_end), color(0)
		{}
	};
	//-----------------------------
	//-----PRIVATE MEMBER TYPE-----
	//-----------------------------

	
	public :

	//---------------------------------------
	//---------COPLIEN FORM FUNCTION---------
	//---------------------------------------
	
	explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc), _root(_end)
	{
		_size = 0;
	}
	
	template< class InputIt >
	map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc), _root(_end) 
	{
		_size = 0;
		this->insert(first, last);	
	}
	
	map( const map& x) : _comp(x._comp), _alloc(x._alloc), _node_alloc(x._node_alloc)
	{
		_root = 0;
		_size = 0;
		insert(x.begin(), x.end());
		//*this = x;
	}
	
	~map()
	{
		
	}

	map& operator=(const map& x)
	{
		_comp = x._comp;
		_alloc = x._alloc;
		_node_alloc = x._node_alloc;
		_root = 0;
		_size = 0;
		insert(x.begin(), x.end());
		// _comp = x._comp;
		// _alloc = x._alloc;
		// _node_alloc = x._node_alloc;
		// _root = x._root;
		// _size = x._size;
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
		iterator it(_root, _root);
		iterator ret(_root, it.minimum(_root));

		//std::cout << "ret key: " << ret->first << " | value: " << ret->second << std::endl;
		//ret++;
		//std::cout << "ret key: " << ret->first << " | value: " << ret->second << std::endl;
		//return iterator(_root, it.minimum(_root));
		return ret;
	}
	
	const_iterator begin() const
	{
		const_iterator it(_root, _root);
		return const_iterator(_root, it.minimum(_root));
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
		node *pt;
		//ft::pair<> new_pair = ft::make_pair(k, mapped_type());
		//value_type	new_pair = ft::make_pair(k, mapped_type());
		//std::cout << "base== " << tmp.base() << std::endl;
		if (tmp.base() == _end)
		{
			pt = new_node(k, mapped_type());
			_root = insert_node(_root, pt);
			_size++;
			return (pt->data.second);
			//return (this->insert_node(_root, new_node(k, mapped_type()))->data.second); //??????
		}
		else
			return ((*tmp).second);
	}
	
	mapped_type& at (const key_type& k)
	{
		iterator tmp = this->find(k);
		
		if (tmp->m == _end)
			throw (std::out_of_range("ft::map::at"));
		else
			return (*tmp.pair.second);
	}
	
	const mapped_type& at (const key_type& k) const
	{
		iterator tmp = this->find(k);
		
		if (tmp->m == _end)
			throw (std::out_of_range("ft::map::at"));
		else
			return (*tmp.pair.second);
	}
	
		//-------------------------
		//--------Modifiers--------
		//-------------------------
	ft::pair<iterator,bool> insert (const value_type& val)
	{
		node *pt = new_node(val.first, val.second);
		_root = insert_node(_root, pt);
		fixViolation(_root, pt);
		_size++;
	}	
	
	iterator insert (iterator position, const value_type& val)
	{
		(void)position;
		node *pt = new_node(val.first, val.second);
		_root = insert_node(_root, pt);
		fixViolation(_root, pt);
		_size++;
	}
	
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			node *pt = new_node((*first).first, (*first).second);
			_root = insert_node(_root, pt);
			fixViolation(_root, pt);
			first++;
			_size++;
		}
	}
	
	void erase (iterator position)
	{
		std::cout << "position"<< std::endl;
		//std::cout << "key: " << position->first << " | value: " << position->second << std::endl;
		//std::cout << "rrrrrkey: " << _root->data.first << " | rrrrvalue: " << _root->data.second << std::endl;
		deleteNode(position.base());
		_size--;
	}
	
	size_type erase (const key_type& k)
	{
		std::cout << "key== "<< k << std::endl;
		iterator test = find(k);
		//std::cout << "test-base= " << test.base() << std::endl;
		if (test.base())
		{
			deleteNode(test.base());
			_size--;
			return(1);
		}
		return (0);
	}
	
	void erase (iterator first, iterator last)
	{
		std::cout << "range"<< std::endl;
		while (last != first)
		{
			last--;
			_size--;
			deleteNode(last.base());
		}
	}
	
	void swap (map& x)
	{
		map tmp;

		tmp->_comp = _comp;
		tmp->_alloc = _alloc;
		tmp->_node_alloc = _node_alloc;
		tmp->_root = _root;
		tmp->_size = _size;

		_comp = x->_comp;
		_alloc = x->_alloc;
		_node_alloc = x->_node_alloc;
		_root = x->_root;
		_size = x->_size;

		x->_comp = tmp-> _comp;
		x->_alloc = tmp->_alloc;
		x->_node_alloc = tmp->_node_alloc;
		x->_root = tmp->_root;
		//x->_end = tmp->_end;
		x->_size = tmp->_size;
	}
	
void printPair(iterator iterator)
{
	std::cout << "key: " << iterator->first << " | value: " << iterator->second << std::endl;
}

void	printReverse()
{
	std::cout << "_________________________in map print______________________" << std::endl;
	iterator it = this->end(), ite = this->begin();
	while (it != ite)
	{
		it--;
		printPair(it);
	}
	std::cout << "_______________________________________________" << std::endl;
}

	void clear()
	{
		//iterator it = this->begin();
		//iterator ite = this->end();

		//erase(this->begin(), this->end());
		// printReverse();
		// while (it != ite)
		// {
		// 	std::cout << "saesfawf= " << std::endl;
		// 	deleteNode(it.base());
		// 	printReverse();
		// 	it++;
		// 	std::cout << "size= " << _size << std::endl;
		// 	_size--;
		// }
		// // _size = 0;
		// _root = 0;
		while (_size)
		{
			//printReverse();
			deleteNode(_root);
			_size--;
		}
		_root = 0;
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

	iterator find(const key_type& k)
	{
		node *temp = _root;
		while (temp != NULL)
		{
    		if (k < temp->data.first)
			{
				//if (temp->left == NULL)
        		//	break;
    			//else
        			temp = temp->left;
    		}
			else if (k == temp->data.first)
        		break;
			else
			{
        		//if (temp->right == NULL)
          		//	break;
        		//else
        			temp = temp->right;
    		}
    	}
 		return iterator(_root, temp);
	}

	const_iterator find(const key_type& k) const
	{
		node *temp = _root;
		while (temp != NULL)
		{
    		if (k < temp->data.first)
			{
				if (temp->left == NULL)
        			break;
    			else
        			temp = temp->left;
    		}
			else if (k == temp->data.first)
        		break;
			else
			{
        		if (temp->right == NULL)
          			break;
        		else
        			temp = temp->right;
    		}
    	}
 		return const_iterator(_root, temp);
	}

	// iterator find (const key_type& k)
	// {
	// 	node *x = _root;
		
	// 	std::cout << "=============k=========== " << k << std::endl;
	// 	while (x != _end && x->data.first != k)
	// 	{
	// 		std::cout << "x data first " << x->data.first << std::endl;
	// 		std::cout << "x data right " << x->right->data.first << std::endl;
	// 		std::cout << "x data left " << x->left->data.first << std::endl;
	// 		if (k > x->data.first)
	// 			x = x->left;
	// 		else
	// 			x = x->right;
	// 	}
	// 	std::cout << "============x============= " << x << std::endl;
	// 	if (x != 0)
	// 		std::cout << "x data first " << x->data.first << std::endl;
	// 	return (iterator(_root, x));
	// }
	
	// const_iterator find (const key_type& k) const
	// {
	// 	node *x = _root;
		
	// 	std::cout << "=============k=========== " << k << std::endl;
	// 	while (x != _end && x->data.first != k)
	// 	{
	// 		if (k > x->data.first)
	// 			x = x->left;
	// 		else
	// 			x = x->right;
	// 	}
	// 	std::cout << "============x============= " << x << std::endl;
	// 	return (iterator(_root, x));
	// }
	
	size_type count (const key_type& k) const
	{
		if (find(k)->m == _end)
			return (0);
		return (1);
	}
	
	iterator lower_bound (const key_type& k)
	{
		iterator it = begin(), ite = end();

		while (it != ite)
		{
			if (_comp((*it).first, k) == false)
				return (it);
			it++;
		}
		return (it);
	}
	
	const_iterator lower_bound (const key_type& k) const
	{
		const_iterator it = begin(), ite = end();

		while (it != ite)
		{
			if (_comp((*it).first, k) == false)
				return (it);
			it++;
		}
		return (it);
	}
	
	iterator upper_bound (const key_type& k)
	{
		iterator it = begin(), ite = end();

		while (it != ite)
		{
			if (_comp(k, (*it).first))
				return (it);
			it++;
		}
		return (it);
	}
	
	const_iterator upper_bound (const key_type& k) const
	{
		const_iterator it = begin(), ite = end();

		while (it != ite)
		{
			if (_comp(k, (*it).first))
				return (it);
			it++;
		}
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

	void rotateLeft(node *&pt)
	{
		node *pt_right = pt->right;
		pt->right = pt_right->left;
		if (pt->right != NULL)
			pt->right->parent = pt;
		pt_right->parent = pt->parent;
		if (pt->parent == NULL)
			_root = pt_right;
		else if (pt == pt->parent->left)
			pt->parent->left = pt_right;
		else
			pt->parent->right = pt_right;
		pt_right->left = pt;
		pt->parent = pt_right;
	}
	
	
	void rotateRight(node *&pt)
	{
	
		node *pt_left = pt->left;
		pt->left = pt_left->right;
		if (pt->left != NULL)
			pt->left->parent = pt;
		pt_left->parent = pt->parent;
		if (pt->parent == NULL)
			_root = pt_left;
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
		else if (pt->data.first == root->data.first)
		{
			_size--;
			return root;
		}
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
						rotateLeft(parent_pt);
						pt = parent_pt;
						parent_pt = pt->parent;
					}
	 				/* Case : 3 pt is left child of its parent Right-rotation required */
					rotateRight(grand_parent_pt);
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
						rotateRight(parent_pt);
						pt = parent_pt;
						parent_pt = pt->parent;
					}
					/* Case : 3 pt is right child of its parent Left-rotation required */
					rotateLeft(grand_parent_pt);
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
		if (x->parent == NULL || x->parent->parent == NULL)
			return NULL;
		if (isOnLeft(x->parent))
			return x->parent->parent->right;
		else
			return x->parent->parent->left;
	}

	bool isOnLeft(node *x)
	{
		if (!x->parent)
			return(false);
		return x == x->parent->left;
	}
 
	// returns pointer to sibling
	node *sibling(node *x)
	{
		// sibling null if no parent
		if (!x)
			return NULL;
		if (x->parent == NULL)
			return NULL;
		if (isOnLeft(x))
			return x->parent->right;
		return x->parent->left;
	}
 
  // moves node down and moves given node in its place
	void moveDown(node *nParent, node *x)
	{
		if (x->parent != NULL)
		{
			if (isOnLeft(x))
				x->parent->left = nParent;
		else
			x->parent->right = nParent;
		}
		nParent->parent = x->parent;
		x->parent = nParent;
	}

	bool hasRedChild(node *x)
	{
		return (x->left != NULL && x->left->color == RED) || (x->right != NULL && x->right->color == RED);
	}
 
	void swapColors(node *x1, node *x2)
	{
		bool temp;
		temp = x1->color;
		x1->color = x2->color;
		x2->color = temp;
	}
 
	void swapValues(node **u, node **v)
	{
		//std::cout << "-------------------swap value-------------------\n";
		
		//node *test = (*u)->parent;
		//node *test2 = (*v)->parent;

		node *tmp = new_node((*u)->data.first, (*u)->data.second);
		node *tmp2 = new_node((*v)->data.first, (*v)->data.second);

		tmp->parent = (*v)->parent;
		tmp->right = (*v)->right;
		tmp->left = (*v)->left;
		tmp2->parent = (*u)->parent;
		tmp2->right = (*u)->right;
		tmp2->left = (*u)->left;

		if (isOnLeft(*u))
			(*u)->parent->left = tmp2;
		else if ((*u)->parent)
			(*u)->parent->right = tmp2;

		if (isOnLeft(*v))
			(*v)->parent->left = tmp;
		else if ((*v)->parent)
			(*v)->parent->right = tmp;

		if ((*v)->right)
			(*v)->right->parent = tmp;
		if ((*v)->left)
			(*v)->left->parent = tmp;

		if ((*u)->right)
			(*u)->right->parent = tmp2;
		if ((*u)->left)
			(*u)->left->parent = tmp2;

		//destruct_node(*u);
		//destruct_node(*v);
		*v = tmp;
		*u = tmp2;
		//destruct_node(v);
		//return (tmp);

		//std::cout << "test= " << test->right << std::endl;
		//std::cout << "test= " << test2->right << std::endl;
	}
 
	void fixDoubleBlack(node *x)
	{
		//std::cout << "x= " << x << std::endl;
		if (x == _root)
			return;
		// Reached root

		node *sibling = this->sibling(x), *parent = x->parent;
		if (sibling == NULL)
		{
			// No sibling, double black pushed up
			fixDoubleBlack(parent);
		}
		else
		{
			if (sibling->color == RED)
			{
				// Sibling red
				parent->color = RED;
				sibling->color = BLACK;
				if (isOnLeft(sibling))
				{
					// left case
					this->rotateRight(parent);
				}
				else
				{
					// right case
					rotateLeft(parent);
				}
				fixDoubleBlack(x);
	  		}
			else
			{
				// Sibling black
				if (hasRedChild(sibling))
				{
					// at least 1 red children
					if (sibling->left != NULL && sibling->left->color == RED)
					{
						if (isOnLeft(sibling))
						{
							// left left
							sibling->left->color = sibling->color;
							sibling->color = parent->color;
							rotateRight(parent);
						}
						else
						{
							// right left
							sibling->left->color = parent->color;
							rotateRight(sibling);
							rotateLeft(parent);
						}
					}
					else
					{
						if (isOnLeft(sibling))
						{
							// left right
							sibling->right->color = parent->color;
							rotateLeft(sibling);
							rotateRight(parent);
						}
						else
						{
							// right right
							sibling->right->color = sibling->color;
							sibling->color = parent->color;
							rotateLeft(parent);
						}
					}
					parent->color = BLACK;
				}
				else
				{
					// 2 black children
					sibling->color = RED;
					if (parent->color == BLACK)
						fixDoubleBlack(parent);
					else
						parent->color = BLACK;
				}
			}
		}
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
						rotateLeft(parent);
						swapColors(x, grandparent);
					}
			 		// for left left and left right
			  		rotateRight(grandparent);
				}
				else
				{
					if (x->isOnLeft())
					{
						// for right left
						rotateRight(parent);
						swapColors(x, grandparent);
					}
					else
						swapColors(parent, grandparent);
				// for right right and right left
				rotateLeft(grandparent);
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
		if (x->left != NULL && x->right != NULL)
			return successor(x->right);
		// when leaf
		if (x->left == NULL && x->right == NULL)
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

		//std::cout << "root key=  " << _root->data.first << std::endl;
		// True when u and v are both black
		bool uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK));
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
					if (sibling(v) != NULL)
					// sibling is not null, make it red"
					sibling(v)->color = RED;
				}
				// delete v from the tree
				if (isOnLeft(v))
					parent->left = NULL;
				else
					parent->right = NULL;
			}
			destruct_node(v);
			return;
		}
		if (v->left == NULL || v->right == NULL)
		{
			// v has 1 child
			if (v == _root)
			{
				// v is root, assign the value of u to v, and delete u

				//swapValues(&u, &v);
    			//deleteNode(u);
				std::cout << "root left " << _root->left << "  right " << _root->right << std::endl;
				//if (u->parent && isOnLeft(u))
				// 	u->parent->left = 0;
				//else if (u->parent && u->parent->right == u)
				// 	u->parent->right = 0;
				node *tmp4 = new_node(u->data.first, u->data.second);
				tmp4->parent = 0;
				tmp4->right = v->right;
				tmp4->left = v->left->left;
				_root = tmp4;

				if (v->right)
					v->right->parent = _root;
				if (v->left)
					v->left->parent = _root;
				std::cout << "root left " << _root->left << "  right " << _root->right << std::endl;

				destruct_node(v);
				//destruct_node(u);

				// deleteNode(u);
				// node *tmp5 = new_node(v->data.first, v->data.second);
				// tmp5->parent = u->parent;
				// tmp5->right = u->right;
				// tmp5->left = u->left;
				// if (isOnLeft(u))
				// 	u->parent->left = tmp5;
				// else if (u->parent)
				// 	u->parent->right = tmp5;

				// destruct_node(u);
				// destruct_node(v);
				//deleteNode(tmp5);


				// u->parent->left = 0;
				// u->parent = 0;
				// u = _root;

				// v->data = u->data;
				// v->left = v->right = NULL;
				// destruct_node(u);
				
				//node *tmp = new_node((u)->data.first, (u)->data.second);





				//swapValues(&u, &v);
	
				// if (isOnLeft(u))
				// 	u->parent->left = 0;
				// else
				// 	u->parent->right = 0;

				// std::cout << "root key: " << _root->data.first << " | root value: " << _root->data.second << std::endl;	
				// std::cout << "key: " << u->data.first << " | value: " << u->data.second << std::endl;	
				// // node *tmp = new_node((u)->data.first, (u)->data.second);
				// // tmp->right = v->right;
				// // tmp->left = v->left;
				// u->parent = 0;
				// //u->right = v->right;
				// u->left = v->left;

				// //if (u->right)
				// //	u->right->parent = u;
				// //if (u->right)
				// //	u->left->parent = u;

				// _root = u;
				// _root->color = BLACK;
				// destruct_node(v);

				// std::cout << "root key: " << _root->data.first << " | root value: " << _root->data.second << std::endl;	
				// std::cout << "here2\n";
				// std::cout << "here2\n";
				// std::cout << "here2\n";
				// std::cout << "here2\n";
				//_root = u;
				//u->right = v->right;
				//u->left = v->left;
				//v->left = v->right = NULL;
				
				//destruct_node(u);
			}
			else
			{
				// Detach v from tree and move u up
				if (isOnLeft(v))
					parent->left = u;
				else
					parent->right = u;
				destruct_node(v);
				u->parent = parent;
				if (uvBlack)
					fixDoubleBlack(u);// u and v both black, fix double black at u
				else
					u->color = BLACK;// u or v red, color u black
			}
			return;
		}
		// v has 2 children, swap values with successor and recurse
		//swapValues(&u, &v);
    	//deleteNode(u);

			 std::cout << "here\n";
			 std::cout << "here\n";
			 std::cout << "here\n";

			node *tmp5 = new_node(u->data.first, u->data.second);
			tmp5->parent = v->parent;
			tmp5->right = v->right;
			tmp5->left = v->left;
			_root = tmp5;

			if (v->right)
				v->right->parent = tmp5;
			if (v->left)
				v->left->parent = tmp5;

			node *tmp6 = new_node(v->data.first, v->data.second);
			tmp6->parent = u->parent;
			tmp6->right = u->right;
			tmp6->left = u->left;
			//_root = tmp4;

			if (u->right)
				u->right->parent = tmp6;
			if (u->left)
				u->left->parent = tmp6;
			deleteNode(tmp6);













			// node *tmp8 = new_node(u->data.first, u->data.second);
			// tmp8->parent = v->parent;
			// tmp8->right = v->right;
			// tmp8->left = v->left;
			// //_root = tmp8;

			// if (v->right)
			// 	v->right->parent = tmp8;
			// if (v->left)
			// 	v->left->parent = tmp8;



			// deleteNode(u);

		// std::cout << "here\n";
		// std::cout << "here\n";
		// std::cout << "here\n";
		// std::cout << "here\n";
		// std::cout << "here\n";
		// std::cout << "here\n";
		// std::cout << "here\n";

		// node *tmp2 = new_node(u->data.first, u->data.second);
		// tmp2->parent = v->parent;
		// tmp2->right = v->right;
		// tmp2->left = v->left;
		// if (isOnLeft(v))
		// 	v->parent->left = tmp2;
		// else if (v->parent)
		// 	v->parent->right = tmp2;
		// else
		// 	_root = tmp2; 
		
		// node *tmp3 = new_node(v->data.first, v->data.second);
		// tmp3->parent = u->parent;
		// tmp3->right = u->right;
		// tmp3->left = u->left;
		// if (isOnLeft(u))
		// 	u->parent->left = tmp3;
		// else if (u->parent)
		// 	u->parent->right = tmp3;
		
		// destruct_node(u);
		// destruct_node(v);
		// deleteNode(tmp3);
		
		
		//deleteNode(u);
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

	void destruct_node(node *x)
	{
		// if (isOnLeft(x))
		// 	x->parent->left = _end;
		// else if (x->parent)
		// 	x->parent->right = _end;
		_node_alloc.destroy(x);
		_node_alloc.deallocate(x, 1);
	}
	
}; //end of map class

//----------------------------------
//----------COMPARE CLASS-----------
//----------------------------------

template <class Key, class T, class Compare, class Alloc>
class map<Key,T,Compare,Alloc>::value_compare //man map::value_compare
{  // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
	friend class map;
	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object
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