/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:46:32 by apommier          #+#    #+#             */
/*   Updated: 2022/10/19 17:30:38 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{

template< class T, class Allocator = std::allocator<T> > class vector;	
class vector
{
	public:
	
	//---------MEMBER TYPE---------
	typedef value_type;
	typedef allocator_type;
	typedef reference;
	typedef const_reference;
	typedef pointer;
	typedef const_pointer;
	typedef iterator;
	typedef const_iterator;
	typedef reverse_iterator;
	typedef const_reverse_iterator;
	typedef difference_type;
	typedef size_type;
	
	//---------COPLIEN FORM FUNCTION---------
	explicit vector (const allocator_type& alloc = allocator_type());//default constructor
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());//fill constructor
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());//range constructor
	vector (const vector& x);//copy constructor
	~vector();
	vector& operator= (const vector& x);//assignation operator
	//---------MEMBER FUNCTION----------
	private:
};
	
}
#endif