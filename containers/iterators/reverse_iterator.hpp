/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:14:31 by apommier          #+#    #+#             */
/*   Updated: 2022/11/22 11:41:22 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstddef>
# include "./iterator_traits.hpp"

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
			
			iterator_type	_Ite;

		public:
		
		//---------------------------------------
		//--------CONSTRUCTOR DESTRUCTOR---------
		//---------------------------------------
		
		reverse_iterator() : _Ite() {}
		explicit reverse_iterator (iterator_type it) { _Ite = it; }

		template<typename It>
		reverse_iterator(const reverse_iterator<It> &rev_it)
		{
			_Ite = rev_it.base();
		}

		virtual ~reverse_iterator(){}

		template<typename It>
		reverse_iterator operator=(reverse_iterator<It> const &cpy)
		{
			_Ite = cpy.base(); 
			return (*this);
		}

		//---------------------------------------
		//-------------INCREMENTERS--------------
		//---------------------------------------

		reverse_iterator& operator++()
		{
			//std::cout << "ope0 ++\n";
			--_Ite;
			return (*this);
		}
		
		reverse_iterator  operator++(int) 
		{
			//std::cout << "ope ++\n";
			reverse_iterator<Iter> tmp = *this;
			_Ite--;
			return (tmp);
		}
		
		reverse_iterator& operator--() 
		{
			//std::cout << "ope0 --\n";
			++_Ite;
			return (*this);
		}
		
		reverse_iterator  operator--(int)
		{
			//std::cout << "ope --\n";
			reverse_iterator<Iter> tmp = *this;
			_Ite++;
			return (tmp);
		}

		// reverse_iterator& operator++() {
		// 	--_Ite;
		// 	return (*this);
		// }
		
		// reverse_iterator  operator++(int) {
		// 	reverse_iterator<Iter> tmp = *this;
		// 	_Ite--;
		// 	return (tmp);
		// }

		// reverse_iterator& operator--() {
		// 	++_Ite;
		// 	return (*this);
		// }
		
		// reverse_iterator  operator--(int) {
		// 	reverse_iterator<Iter> tmp = *this;
		// 	_Ite++;
		// 	return (tmp);
		// }

		//---------------------------------------
		//----------------ADRESS-----------------
		//---------------------------------------

		reference operator *()
		{
			iterator_type tmp(_Ite);
			tmp--;
			return (*tmp);
		}
		
		const reference operator *() const
		{
			iterator_type tmp(_Ite);
			tmp--;
			return (*tmp);
		}
		
		pointer operator ->() { return (_Ite.getPointer()); }
		const pointer operator ->() const { return (_Ite.getPointer()); }
		reference operator [](difference_type nbr) const { return (*(_Ite - nbr - 1)); }

		//---------------------------------------
		//--------------OPERATION----------------
		//---------------------------------------

		reverse_iterator operator+ (difference_type n) const { return reverse_iterator(_Ite - n); }
		
		friend reverse_iterator operator +(difference_type lhs, reverse_iterator const& rhs) { return (rhs + lhs); } // n + a

		reverse_iterator& operator+= (difference_type n)
		{
			_Ite -= n;
			return (*this);
		}
		
		reverse_iterator operator- (difference_type n) const { return reverse_iterator(_Ite + n); }
		
		difference_type operator- (reverse_iterator const &lhs) const { return (lhs._Ite - _Ite); }

		reverse_iterator& operator-= (difference_type n)
		{
			_Ite += n;
			return (*this);
		}

		//---------------------------------
		//--------------GET----------------
		//---------------------------------

		iterator_type base() const { return /*iterator_type*/(_Ite); }
	};

		template<class Ite1, class Ite2>
		bool operator== (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{ return (lhs.base() == rhs.base()); }
		
		template<class Ite1, class Ite2>
		bool operator!= (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{ return (lhs.base() != rhs.base()); }
		
		template<class Ite1, class Ite2>
		bool operator<  (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{ return (lhs.base() > rhs.base()); }
		
		template<class Ite1, class Ite2>
		bool operator<= (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{ return (lhs.base() >= rhs.base()); }
		
		template<class Ite1, class Ite2>
		bool operator>  (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{ return (lhs.base() < rhs.base()); }
		
		template<class Ite1, class Ite2>
		bool operator>= (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{ return (lhs.base() <= rhs.base()); }


}