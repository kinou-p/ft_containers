/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:04:37 by apommier          #+#    #+#             */
/*   Updated: 2022/11/14 06:48:31 by apommier         ###   ########.fr       */
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
	//ft::vector<int> first;
	ft::vector<int> first(5, 3);
	std::cout << "------empty------\n";
	std::cout << first.empty() << std::endl;
	std::cout << "------size------\n";
	std::cout << first.size() << std::endl;
	std::cout << "------pushback then size------\n";
	 first.push_back(5);
	std::cout << first.size() << std::endl;
	std::cout << "------------\n";
	
	// std::cout << first[1] << std::endl;
	// std::cout << "------1------\n";
	// std::cout << first.at(1) << std::endl;
	// std::cout << "-------2-----\n";
	// std::cout << first.at(2) << std::endl;
	// std::cout << "-------3-----\n";
	// std::cout << first.at(3) << std::endl;
	// std::cout << "-------4-----\n";
	// std::cout << first.at(4) << std::endl;
	// std::cout << "-------5-----\n";
	
	// std::cout << first.at(0) << std::endl;
	// std::cout << "--------6----\n";
	// std::cout << first.at(6) << std::endl;
	// std::cout << "------------\n";

	std::cout << "------for------\n";
	for (size_t i = 0; i < first.size(); i++)
	{
		std::cout << first[1] << std::endl;
	 	// std::cout << "------------\n";
	}
	std::cout << "-------0-----\n";
	std::cout << first.at(5) << std::endl;
	 
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