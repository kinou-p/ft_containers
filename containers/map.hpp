/* ************************************************************************** */
/*																			*/
/*														:::		::::::::	 */
/*	 map.hpp											:+:		:+:	:+:	 */
/*													+:+ +:+		 +:+	 */
/*	 By: apommier <apommier@student.42.fr>			+#+	+:+		 +#+		*/
/*												+#+#+#+#+#+	 +#+			 */
/*	 Created: 2022/11/28 01:40:12 by apommier			#+#	#+#			 */
/*	 Updated: 2022/11/28 03:29:41 by apommier		 ###	 ########.fr		 */
/*																			*/
/* ************************************************************************** */

#pragma once

#include "./iterators/bidirectionnal_iterator.hpp"
#include "./iterators/pair.hpp"
#include "./iterators/make_pair.hpp"
#include "vector.hpp"

#define RED 1
#define BLACK 0


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

	typedef	Key																key_type;
	typedef	node															Node;
	typedef Node*															NodePtr;
	typedef	T																mapped_type;
	typedef	ft::pair<const Key, T>											value_type;
	typedef	std::size_t														size_type;
	typedef	std::ptrdiff_t													difference_type;
	typedef	Compare															key_compare;
	typedef	Allocator														allocator_type;
	typedef typename Allocator::template rebind<node>::other				node_allocator_type;
	typedef	value_type&														reference;
	typedef	const value_type&												const_reference;
	typedef	typename Allocator::pointer										pointer;
	typedef	typename Allocator::const_pointer								const_pointer;
	typedef	ft::bidirectionnal_iterator<value_type, node>					iterator; 
	typedef	ft::bidirectionnal_iterator<value_type const, node const>		const_iterator;
	typedef	std::reverse_iterator<iterator>									reverse_iterator;
	typedef	std::reverse_iterator<const_iterator>							const_reverse_iterator;
	
	class value_compare;

	protected :

		key_compare			_comp;
		allocator_type		_alloc;
		node_allocator_type	_node_alloc;
		
		NodePtr				_root;
		NodePtr				_end;
		size_type			_size;

	public :
	
	
	struct node{
		value_type	data;
		NodePtr		parent;
		NodePtr		right;
		NodePtr		left;
		
		bool		color;

		node() : parent(0), right(0), left(0), color(0) {}
		node(key_type const &key, mapped_type const &val, NodePtr end) 
		: data(ft::make_pair(key, val)), parent(end), right(end), left(end), color(1)
		{}
	};
	//-----------------------------
	//-----PRIVATE MEMBER TYPE-----
	//-----------------------------

	
	public :

	//---------------------------------------
	//---------COPLIEN FORM FUNCTION---------
	//---------------------------------------
	
	explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc)
	{
		_end = _node_alloc.allocate(1);
		 _node_alloc.construct(_end, node());
		_size = 0;
		_root = _end;
	}
	
	template< class InputIt >
	map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc)
	{
		_end = _node_alloc.allocate(1);
		 _node_alloc.construct(_end, node());
		_size = 0;
		_root = _end;
		this->insert(first, last);	
	}
	
	map( const map& x) : _comp(x._comp), _alloc(x._alloc), _node_alloc(x._node_alloc)
	{
		
		_size = 0;
		_end = _node_alloc.allocate(1);
		_node_alloc.construct(_end, node());
		_root = _end;
		insert(x.begin(), x.end());
		//*this = x;
	}
	
	~map()
	{
		//this->clear();
	}

	map& operator=(const map& x)
	{
		this->clear();
		// _comp = x._comp;
		// _alloc = x._alloc;
		// _node_alloc = x._node_alloc;
		// _root = _end;
		// _size = 0;
		// insert(x.begin(), x.end());
		_comp = (x._comp);
		_alloc = (x._alloc);
		_node_alloc = (x._node_alloc);

		_size = 0;
		_end = _node_alloc.allocate(1);
		_node_alloc.construct(_end, node());
		_root = _end;
		insert(x.begin(), x.end());
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
		iterator it(_root, _end, _root);
		if (_root == _end)	
			return (it);
		iterator ret(_root, _end, it.minimum(_root));

		//std::cout << "root key: " << _root->data.first << " | value: " << _root->data.second << std::endl;
		//std::cout << "ret key: " << ret->first << " | value: " << ret->second << std::endl;
		//ret++;
		//std::cout << "ret key: " << ret->first << " | value: " << ret->second << std::endl;
		//return iterator(_root, it.minimum(_root));
		return ret;
	}
	
	const_iterator begin() const
	{
		const_iterator it(_root, _end, _root);
		if (_root == _end)	
			return (it);
		const_iterator ret(_root, _end, it.minimum(_root));

		//std::cout << "root key: " << _root->data.first << " | value: " << _root->data.second << std::endl;
		//std::cout << "ret key: " << ret->first << " | value: " << ret->second << std::endl;
		//ret++;
		//std::cout << "ret key: " << ret->first << " | value: " << ret->second << std::endl;
		//return iterator(_root, it.minimum(_root));
		return ret;
	}
	
	iterator end()
	{
		return iterator(_root, _end, _end);
	}
	
	const_iterator end() const
	{
		return const_iterator(_root, _end, _end);
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
		//std::cout << "here\n"; 
		iterator tmp = this->find(k);
		//std::cout << "here3\n"; 
		NodePtr pt;
		//ft::pair<> new_pair = ft::make_pair(k, mapped_type());
		//value_type	new_pair = ft::make_pair(k, mapped_type());
		//std::cout << "base== " << tmp.base() << std::endl;
		if (tmp.base() == _end)
		{
			pt = new_node(k, mapped_type());
			insert(pt);
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
		
		if (tmp.base() == _end)
			throw (std::out_of_range("ft::map::at"));
		else
			return (*tmp.pair.second);
	}
	
	const mapped_type& at (const key_type& k) const
	{
		iterator tmp = this->find(k);
		
		if (tmp.base() == _end)
			throw (std::out_of_range("ft::map::at"));
		else
			return (*tmp.pair.second);
	}
	
		//-------------------------
		//--------Modifiers--------
		//-------------------------
	ft::pair<iterator,bool> insert (const value_type& val)
	{
		NodePtr pt = new_node(val.first, val.second);
		insert(pt);
		//fixViolation(_root, pt);
		_size++;
	}	
	
	iterator insert (iterator position, const value_type& val)
	{
		(void)position;
		NodePtr pt = new_node(val.first, val.second);
		insert(pt);
		//fixViolation(_root, pt);
		_size++;
	}
	
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{

		while (first != last)
		{
			NodePtr pt = new_node(first->first, first->second);
			insert(pt);
			first++;
			_size++;
		}
	}
	
	void erase (iterator position)
	{
		//std::cout << "position"<< std::endl;
		deleteNode(_root, position->first);
		_size--;
	}
	
	size_type erase (const key_type& k)
	{
		//std::cout << "key== "<< k << std::endl;
		iterator test = find(k);
		//std::cout << "test-base= " << test.base() << std::endl;
		if (test.base() != _end)
		{
			deleteNode(_root, test->first);
			_size--;
			return(1);
		}
		return (0);
	}
	
	void erase (iterator first, iterator last)
	{
		// printHelper(_root, "", true);

		// std::cout << "range"<< std::endl;
		// std::cout << "_end==   "<< _end <<  std::endl;
		// std::cout << "first==   "<< first.base() <<  std::endl;
		// std::cout << "first-r==   "<< first.base()->right <<  std::endl;
		// std::cout << "first-f==   "<< first.base()->left <<  std::endl;

		//int i = 0;
		//std::cout << "==   "<< _end <<  std::endl;
		while (first != last)
		{
			//std::cout << "i = "<< i++ << std::endl;
			//last--;
			//NodePtr pt = new_node(first->first, first->second);
			deleteNode(_root, (first++)->first);//insert(pt);
			//std::cout << "fitsrbase before== "<< first.base() << std::endl;
			//first++;
			//std::cout << "fitsrbase== "<< first.base() << std::endl;
			//std::cout << "lastbase== "<< last.base() << std::endl;
			_size--;
		}


		// //last--;
		// while (first != last)
		// {
		// 	//_size--;
		// 	erase(first->first);
		// 	first++;
		// }
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

	void clear()
	{
		//int i = 0;
		//std::cout << "size	= " << _size << std::endl;
		//if(!_size)
		//	std::cout << "s	= "  << std::endl;
		///if(_size - 1 > 0)
		//	std::cout << "sizerdtgserg	= "  << std::endl;
		iterator it;
		while (_size && _size - 1 > 0)
		{
			//
			it = this->begin();
			//std::cout << "_root key	= " << _root->data.first << "_root value	 = " << _root->data.second << std::endl;
			//std::cout << "key	= " << it->first << "value	 = " << it->second << std::endl;
			deleteNode(_root, it->first/**/);
			_size--;
			//std::cout << "size ===	" << _size << std::endl;
			//printHelper(_root, "", true);
			//it++;
		}
		destruct_node(_root);
		_size = 0;
		_root = _end;
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
		NodePtr temp = _root;
		while (temp != _end)
		{
			if (k < temp->data.first)
			{
				if (temp->left == _end)
					return iterator(_root, _end, _end);
				else
					temp = temp->left;
			}
			else if (k == temp->data.first)
				break;
			else
			{
				if (temp->right == _end)
						return iterator(_root, _end, _end);
				else
					temp = temp->right;
			}
		}
 		return iterator(_root, _end, temp);

		// NodePtr temp = _root;
		// while (temp != NULL)
		// {
		// 	if (k < temp->data.first)
		// 	{
		// 		//if (temp->left == NULL)
		// 		//	break;
		// 		//else
		// 			temp = temp->left;
		// 	}
		// 	else if (k == temp->data.first)
		// 		break;
		// 	else
		// 	{
		// 		//if (temp->right == NULL)
		// 			//	break;
		// 		//else
		// 			temp = temp->right;
		// 	}
		// }
 		// return iterator(_root, _end, temp);
	}

	const_iterator find(const key_type& k) const
	{
		NodePtr temp = _root;
		while (temp != _end)
		{
			if (k < temp->data.first)
			{
				if (temp->left == _end)
					return iterator(_root, _end, _end);
				else
					temp = temp->left;
			}
			else if (k == temp->data.first)
				break;
			else
			{
				if (temp->right == _end)
						return iterator(_root, _end, _end);
				else
					temp = temp->right;
			}
		}
 		return const_iterator(_root, _end, temp);
	}

	size_type count (const key_type& k) const
	{
		if (find(k).base() == _end)
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

	void deleteFix(NodePtr x) {
	NodePtr s;
	while (x != _root && x->color == 0) {
		if (x == x->parent->left) {
		s = x->parent->right;
		if (s->color == 1) {
			s->color = 0;
			x->parent->color = 1;
			leftRotate(x->parent);
			s = x->parent->right;
		}

		if (s->left->color == 0 && s->right->color == 0) {
			s->color = 1;
			x = x->parent;
		} else {
			if (s->right->color == 0) {
			s->left->color = 0;
			s->color = 1;
			rightRotate(s);
			s = x->parent->right;
			}

			s->color = x->parent->color;
			x->parent->color = 0;
			s->right->color = 0;
			leftRotate(x->parent);
			x = _root;
		}
		} else {
		s = x->parent->left;
		if (s->color == 1) {
			s->color = 0;
			x->parent->color = 1;
			rightRotate(x->parent);
			s = x->parent->left;
		}

		if (s->right->color == 0 && s->right->color == 0) {
			s->color = 1;
			x = x->parent;
		} else {
			if (s->left->color == 0) {
			s->right->color = 0;
			s->color = 1;
			leftRotate(s);
			s = x->parent->left;
			}

			s->color = x->parent->color;
			x->parent->color = 0;
			s->left->color = 0;
			rightRotate(x->parent);
			x = _root;
		}
		}
	}
	x->color = 0;
	}
	
	void rbTransplant(NodePtr u, NodePtr v) {
	if (u->parent == NULL) {
		_root = v;
	} else if (u == u->parent->left) {
		u->parent->left = v;
	} else {
		u->parent->right = v;
	}
	v->parent = u->parent;
	}
	
	void deleteNode(NodePtr node, int key) {
	NodePtr z = _end;
	NodePtr x, y;
	while (node != _end) {
		if (node->data.first == key) {
		z = node;
		}

		if (node->data.first <= key) {
		node = node->right;
		} else {
		node = node->left;
		}
	}

	if (z == _end) {
		_size++;
		//std::cout << "Key not found in the tree" << std::endl;
		return;
	}

	y = z;
	int y_original_color = y->color;
	if (z->left == _end) {
		x = z->right;
		rbTransplant(z, z->right);
	} else if (z->right == _end) {
		x = z->left;
		rbTransplant(z, z->left);
	} else {
		y = minimum(z->right);
		y_original_color = y->color;
		x = y->right;
		if (y->parent == z) {
		x->parent = y;
		} else {
		rbTransplant(y, y->right);
		y->right = z->right;
		y->right->parent = y;
		}

		rbTransplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	delete z;
	if (y_original_color == 0) {
		deleteFix(x);
	}
	}
	
	void insertFix(NodePtr k) {
	NodePtr u;
	while (k->parent->color == 1) {
		if (k->parent == k->parent->parent->right) {
		u = k->parent->parent->left;
		if (u->color == 1) {
			u->color = 0;
			k->parent->color = 0;
			k->parent->parent->color = 1;
			k = k->parent->parent;
		} else {
			if (k == k->parent->left) {
			k = k->parent;
			rightRotate(k);
			}
			k->parent->color = 0;
			k->parent->parent->color = 1;
			leftRotate(k->parent->parent);
		}
		} else {
		u = k->parent->parent->right;

		if (u->color == 1) {
			u->color = 0;
			k->parent->color = 0;
			k->parent->parent->color = 1;
			k = k->parent->parent;
		} else {
			if (k == k->parent->right) {
			k = k->parent;
			leftRotate(k);
			}
			k->parent->color = 0;
			k->parent->parent->color = 1;
			rightRotate(k->parent->parent);
		}
		}
		if (k == _root) {
		break;
		}
	}
	_root->color = 0;
	}

	NodePtr minimum(NodePtr node) {
	while (node->left != _end) {
		node = node->left;
	}
	return node;
	}

	NodePtr maximum(NodePtr node) {
	while (node->right != _end) {
		node = node->right;
	}
	return node;
	}

	NodePtr successor(NodePtr x) {
	if (x->right != _end) {
		return minimum(x->right);
	}

	NodePtr y = x->parent;
	while (y != _end && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
	}

	NodePtr predecessor(NodePtr x) {
	if (x->left != _end) {
		return maximum(x->left);
	}

	NodePtr y = x->parent;
	while (y != _end && x == y->left) {
		x = y; 
		y = y->parent;
	}

	return y;
	}

	void leftRotate(NodePtr x) {
	NodePtr y = x->right;
	x->right = y->left;
	if (y->left != _end) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL) {
		_root = y;
	} else if (x == x->parent->left) {
		x->parent->left = y;
	} else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
	}

	void rightRotate(NodePtr x) {
	NodePtr y = x->left;
	x->left = y->right;
	if (y->right != _end) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL) {
		_root = y;
	} else if (x == x->parent->right) {
		x->parent->right = y;
	} else {
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
	}

	// Inserting a node
	void insert(NodePtr node) {
	// NodePtr node = new Node;
	// node->parent = NULL;
	// node->data = key;
	// node->left = _end;
	// node->right = _end;
	// node->color = 1;

	NodePtr y = NULL;
	NodePtr x = _root;
	
	//std::cout << "root key=	" << _root->data.first << "  root value=	" << _root->data.second << "end== " << _end << std::endl;
	while (x != _end)
	{
		y = x;
		if (node->data.first < x->data.first)
			x = x->left;
		else
			x = x->right;
	}

	node->parent = y;
	if (y == NULL) {
		_root = node;
	} else if (node->data.first < y->data.first) {
		y->left = node;
	} else {
		y->right = node;
	}

	if (node->parent == NULL) {
		node->color = 0;
		return;
	}

	if (node->parent->parent == NULL) {
		return;
	}

	insertFix(node);
	}

	NodePtr new_node(key_type key, mapped_type val)
	{
		NodePtr ret;

		ret = _node_alloc.allocate(1);
		_node_alloc.construct(ret, node(key, val, _end));
		return (ret);
	}

	void destruct_node(node *x)
	{
		_node_alloc.destroy(x);
		_node_alloc.deallocate(x, 1);
	}

	void printHelper(NodePtr _root, std::string indent, bool last)
	{
		if (_root != NULL)
		{
			std::cout << indent;
			if (last)
			{
				std::cout << "R----";
				indent += "	 ";
			}
			else
			{
				std::cout << "L----";
				indent += "|	";
			}
			std::string sColor = _root->color ? "RED" : "BLACK";
			std::cout << _root->data.first << "(" << sColor << ")" << std::endl;
			printHelper(_root->left, indent, false);
			printHelper(_root->right, indent, true);
		}
	}

};
//----------------------------------
//----------COMPARE CLASS-----------
//----------------------------------

template <class Key, class T, class Compare, class Alloc>
class map<Key,T,Compare,Alloc>::value_compare //man map::value_compare
{	// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
	friend class map;
	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}	// constructed with map's comparison object
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