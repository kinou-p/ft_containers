/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:59:46 by apommier          #+#    #+#             */
/*   Updated: 2022/11/22 14:09:44 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template < bool B, class T = void >
	struct enable_if {};

	template < class T >
	struct enable_if< true, T > {
	  typedef T type;
	};	
}