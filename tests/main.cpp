/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:04:37 by apommier          #+#    #+#             */
/*   Updated: 2022/10/28 17:12:41 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_containers.hpp"

void stack_tester()
{
	ft::stack<int> first;
	std::cout << "------empty------\n";
	std::cout << first.empty() << std::endl;
	std::cout << "------size------\n";
	std::cout << first.size() << std::endl;
}

void vector_tester()
{
	ft::vector<int> first;
	std::cout << "------empty------\n";
	std::cout << first.empty() << std::endl;
	std::cout << "------size------\n";
	std::cout << first.size() << std::endl;
	std::cout << "------pushback then size------\n";
	 first.push_back(5);
	std::cout << first.size() << std::endl;
}

int main()
{
	std::cout << "------TESTER START-------\n";
	std::cout << "------STACK-------\n";
	stack_tester();
	std::cout << "------VECTOR-------\n";
	vector_tester();
	// std::cout << "------MAP-------\n";
	// map_tester();
	// std::cout << "------SET-------\n";
	// set_tester();
	std::cout << "------End-------\n";
	return (0);
}