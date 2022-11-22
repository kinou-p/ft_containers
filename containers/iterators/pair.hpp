/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:39:29 by apommier          #+#    #+#             */
/*   Updated: 2022/11/22 14:11:41 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<class _T1, class _T2>
	struct pair{
		typedef _T1	first_type;
		typedef _T2	second_type;
		
		_T1 _first;
		_T2 _second;

		pair(): _first(), _second() {}
		pair( const T1& x, const T2& y ); : _first(x), _second(y) {}
		
		template<class _U1, class _U2>
		pair(const pair<_U1, _U2>& p): _first(p._first), _second(p._second) { }

		pair& operator=(pair& other)
		{
			_first = other.first;
			_second = other.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first==rhs.first && lhs.second==rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs==rhs));
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
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