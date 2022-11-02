/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:14:35 by apommier          #+#    #+#             */
/*   Updated: 2022/10/30 16:36:23 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace ft 
{
	template<typename T>
	class random_access_iterator
	{
		public:
		
		//---------------------------------------
		//--------CONSTRUCTOR DESTRUCTOR---------
		//---------------------------------------
		random_access_iterator()
		{
					
		}
		
		random_access_iterator()
		{

		}
		
		random_access_iterator(random_access_iterator &cpy)
		{

		}
		
		~random_access_iterator()
		{

		}
		
		vectorIterator &operator=()
		{
			
		}
		
		//---------------------------------------
		//-------------COMPARAISON---------------
		//---------------------------------------
		bool operator ==() {}
		bool operator !=() {}
		bool operator <() {}
		bool operator >() {}
		bool operator <=() {}
		bool operator >=() {}

		//---------------------------------------
		//-------------INCREMENTERS--------------
		//---------------------------------------
		
		random_access_iterator operator ++() {}
		random_access_iterator operator ++(int) {}
		random_access_iterator operator --() {}
		random_access_iterator operator --(int) {}

		//---------------------------------------
		//-------------INCREMENTERS--------------
		//---------------------------------------
		
		private:
	};
}
#endif