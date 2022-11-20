/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:14:31 by apommier          #+#    #+#             */
/*   Updated: 2022/11/19 05:49:52 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <cstddef>

namespace ft 
{
	template<typename Iter>
	class reverse_iterator
	{
		public:

		typedef	Iter													iterator_type;
		typedef	typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef	typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef	typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef	typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef	typename ft::iterator_traits<Iter>::reference			reference;
		
		private:	
			
			Iter	_Ite;

		public:
		
		//---------------------------------------
		//--------CONSTRUCTOR DESTRUCTOR---------
		//---------------------------------------
		
		reverse_iterator(){}
		reverse_iterator(pointer Ite){}
		reverse_iterator(reverse_iterator const &cpy) {}

		~reverse_iterator(){}
		
		reverse_iterator &operator=(reverse_iterator const &cpy)
		{
			_Ite = cpy._Ite;
			return (*this);
		}
		
		//---------------------------------------
		//-------------COMPARAISON---------------
		//---------------------------------------

		//---------------------------------------
		//-------------INCREMENTERS--------------
		//---------------------------------------

		//---------------------------------------
		//----------------ADRESS-----------------
		//---------------------------------------

		reference operator *() { return (*_Ite); }
		const reference operator *() const { return (*_Ite); }
		pointer operator ->() { return (_Ite); }
		const pointer operator ->() const { return (_Ite); }
		reference operator [](difference_type nbr) const { return (*(_Ite + nbr)); }

		//---------------------------------------
		//--------------OPERATION----------------
		//---------------------------------------

		//---------------------------------
		//--------------GET----------------
		//---------------------------------

	};

	
}