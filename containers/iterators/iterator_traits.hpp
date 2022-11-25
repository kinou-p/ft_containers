/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:07:29 by apommier          #+#    #+#             */
/*   Updated: 2022/11/25 08:51:46 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<typename Iterator>
	struct iterator_traits {
		
		typedef typename 		Iterator::iterator_category iterator_category;
		typedef typename 		Iterator::value_type		value_type;
		typedef typename 		Iterator::difference_type	difference_type;
		//typedef typename		difference_type				distance_type;
		typedef typename 		Iterator::pointer			pointer;
		typedef typename 		Iterator::reference			reference;
   };
}