/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectionnal_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:50:53 by apommier          #+#    #+#             */
/*   Updated: 2022/11/25 18:27:27 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
		
		node_type *_node;

	public :

		bidirectionnal_iterator() : _node(NULL) {}
		bidirectionnal_iterator(node_type *cpy) { _node = cpy; }
		bidirectionnal_iterator(bidirectionnal_iterator const &rhs) { this->_node = rhs._node; }

		~bidirectionnal_iterator() {}

		bidirectionnal_iterator &operator=(bidirectionnal_iterator const &rhs)
		{
			if (this != &rhs) 
			{
				this->_node = rhs._node;
			}
			return (*this);
		}
		
		operator bidirectionnal_iterator<const T, const Node>() const
		{
		 	return (bidirectionnal_iterator<const T, const Node>(_node));
		}

		bool		operator==(bidirectionnal_iterator &rhs) { return (_node == rhs._node); }
		bool		operator!=(bidirectionnal_iterator &rhs) { return (_node != rhs._node); }
		
		reference operator*() { return (_node->pair); }
		const_reference	operator*() const { return (_node->pair); }
		pointer operator->() { return (&(_node->pair)); }
		const_pointer operator->() const { return (&(_node->pair)); }
		
		bidirectionnal_iterator &operator ++()
		{
			//_node = ;
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
			//_node = ;
			return (*this);
		}
		
		bidirectionnal_iterator operator --(int)
		{
			bidirectionnal_iterator tmp(*this);
			++(*this);
			return (tmp);
		}
		
};

}