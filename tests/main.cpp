/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:04:37 by apommier          #+#    #+#             */
/*   Updated: 2022/11/16 22:18:48 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_containers.hpp"
#include <sys/time.h>

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void stack_tester()
{
	ft::stack<int> first;
	std::cout << "------empty------\n";
	std::cout << first.empty() << std::endl;
	std::cout << "------size------\n";
	std::cout << first.size() << std::endl;
}

void print_vector(ft::vector<int> x)
{
	std::cout << "-----print vector----\n";
	for (size_t i = 0; i < x.size(); i++)
		std::cout << x[i] << std::endl;
}

void vector_tester()
{
	ft::vector<int> first(5, 3);
	ft::vector<int> second;
	ft::vector<int>::iterator it = first.begin();
	std::cout << "------empty------\n";
	std::cout << first.empty() << std::endl;
	std::cout << second.empty() << std::endl;
	std::cout << "------size------\n";
	std::cout << first.size() << std::endl;
	std::cout << "------pushback then size------\n";
	first.push_back(5);
	std::cout << first.size() << std::endl;
	std::cout << "------for------\n";
	print_vector(first);
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