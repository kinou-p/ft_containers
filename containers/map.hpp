/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:46:25 by apommier          #+#    #+#             */
/*   Updated: 2022/11/17 07:41:22 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

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

	typedef	Key							key_type;
	typedef	T							mapped_type;
	typedef	std::pair<const Key, T>		value_type;
	typedef	std::size_t					size_type;
	typedef	std::ptrdiff_t				difference_type;
	typedef	Compare						key_compare;
	typedef	Allocator					allocator_type;
	typedef	value_type&					reference;
	typedef	const value_type&			const_reference;
	typedef	Allocator::pointer			pointer;
	typedef	Allocator::const_pointer	const_pointer;
	typedef	LegacyBidirectionalIterator	iterator;
	typedef	LegacyBidirectionalIterator	const_iterator;
	typedef	std::reverse_iterator<iterator>			reverse_iterator;
	typedef	std::reverse_iterator<const_iterator>	const_reverse_iterator;

	//-----------------------------
	//-----PRIVATE MEMBER TYPE-----
	//-----------------------------
	private :

		pointer _start;

	public :
	
	//---------------------------------------
	//---------COPLIEN FORM FUNCTION---------
	//---------------------------------------
	map();
	explicit map( const Compare& comp, const Allocator& alloc = Allocator() )
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
		
	}
	
	size_type size() const
	{
		
	}
	
	size_type max_size() const
	{
		
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
	pair<iterator,bool> insert (const value_type& val)
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
	
	pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		
	}
	
	pair<iterator,iterator>             equal_range (const key_type& k)
	{
		
	}
	

};

}

#endif