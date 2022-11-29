/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:46:30 by apommier          #+#    #+#             */
/*   Updated: 2022/11/29 13:15:44 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{

template <class T, class Container = ft::vector<T> >
class stack
{
	public:

		//-----------------------------
		//---------MEMBER TYPE---------
		//-----------------------------
		typedef std::size_t		size_type;
		typedef T				value_type;
		typedef Container		container_type;

	protected:
		container_type	c;
		
	public:
	
		//---------------------------------------
		//---------COPLIEN FORM FUNCTION---------
		//---------------------------------------
		explicit stack (const container_type& ctnr = container_type()) : c(ctnr){}//default constructor
		
		stack<T, Container>(const stack &other )//copy constructor
		{
			*this = other;
		}
		
		~stack<T, Container>(void) {}//destructor
		
		stack	&operator=( const stack &other )//assigment operator
		{
			if (this != &other)
				this->c = other.c;
			return *this;
		}
		
		//----------------------------------
		//---------MEMBER FUNCTION----------
		//----------------------------------
		bool empty() const
		{
			return (c.empty());
		}
		
		size_type size() const
		{
			return (c.size());
		}
		
		value_type& top()
		{
			return (c.back());
		}
		
		const value_type& top() const
		{
			return (c.back());
		}
		
		void push (const value_type& val)
		{
			return (c.push_back(val));
		}
		
		void pop()
		{
			return (c.pop_back());
		}

		template <class type, class C>
		friend bool operator==(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
		template <class type, class C>
		friend bool operator!=(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
		template <class type, class C>
		friend bool operator<(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
		template <class type, class C>
		friend bool operator<=(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
		template <class type, class C>
		friend bool operator>(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
		template <class type, class C>
		friend bool operator>=(const ft::stack<type,C>& lhs, const ft::stack<type,C>& rhs );
};
	//---------------------------------------------
	//---------OPERATOR OVERLOAD FUNCTION----------
	//---------------------------------------------
	
	template< class T, class Container >
	bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs.c == rhs.c);
	}

	template< class T, class Container >
	bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (!(lhs.c == rhs.c));
	}

	template< class T, class Container >
	bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs.c < rhs.c);
	}

	template< class T, class Container >
	bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (!(rhs.c < lhs.c));
	}

	template< class T, class Container >
	bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (rhs.c < lhs.c);
	}

	template< class T, class Container >
	bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (!(lhs.c < rhs.c));
	}

}
#endif 