/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:39:29 by apommier          #+#    #+#             */
/*   Updated: 2022/11/24 17:38:32 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<class T1, class T2>
	struct pair{
		typedef T1	first_type;
		typedef T2	second_type;
		
		T1 first;
		T2 second;

		pair(): first(), second() {}
		pair( const T1& x, const T2& y ) : first(x), second(y) {}
		
		template<class U1, class U2>
		pair(const pair<U1, U2>& p): first(p.first), second(p.second) { }

		pair& operator=(pair& other)
		{
			first = other.first;
			second = other.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(rhs<lhs));
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs<lhs);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs<rhs));
	}

}