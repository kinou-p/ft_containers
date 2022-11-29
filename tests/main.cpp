/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:04:37 by apommier          #+#    #+#             */
/*   Updated: 2022/11/29 13:25:14 by apommier         ###   ########.fr       */
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
// void print_vector(ft::vector<int> x)
// {
	
// 	std::cout << "-----print vector----\n";
// 	for (size_t i = 0; i < x.size(); i++)
// 		std::cout << x[i] << std::endl;
// }

// void stack_tester()
// {
// 	ft::stack<int> first;
// 	std::cout << "------empty------\n";
// 	std::cout << first.empty() << std::endl;
// 	std::cout << "------size------\n";
// 	std::cout << first.size() << std::endl;
// }

// void vector_tester()
// {
// 	ft::vector<int> first(5, 3);
// 	ft::vector<int> second;
// 	ft::vector<int>::iterator it = first.begin();
// 	std::cout << "------empty------\n";
// 	std::cout << first.empty() << std::endl;
// 	std::cout << second.empty() << std::endl;
// 	std::cout << "------size------\n";
// 	std::cout << first.size() << std::endl;
// 	std::cout << "------pushback then size------\n";
// 	first.push_back(5);
// 	std::cout << first.size() << std::endl;
// 	std::cout << "------for------\n";
// 	print_vector(first);
// 	std::cout << "-------0-----\n";
// 	std::cout << first.at(5) << std::endl;
	 
// }


int main()
{
	long real_time;
	long my_time;
	std::cout << "/* ************************************************************************** */\n";
	std::cout << "/* ************************************************************************** */\n";
	std::cout << "/* ************************************************************************** */\n";
	std::cout << "/* *****************************FT_CONTAINERS TESTER************************* */\n";
	std::cout << "/* ************************************************************************** */\n";
	std::cout << "/* ************************************************************************** */\n";
	std::cout << "/* ************************************************************************** */\n";
	
	std::cout << "	------------------------------------------------------------\n";
	std::cout << "	---------------------------STACK----------------------------\n";
	std::cout << "	------------------------------------------------------------\n";
	my_time = get_time();
	stack_tester();
	my_time = get_time() - my_time;
	std::cout << "	--------------------------REAL STACK------------------------\n";
	real_time = get_time();
	real_stack_tester();
	real_time = get_time() - real_time;
	std::cout << "	--------------------------TIME DIFF-------------------------\n";
	std::cout << "			homemade ft containers = " << my_time << "ms\n";
	std::cout << "			real std containers = " << real_time << "ms\n";
	
	std::cout << "	------------------------------------------------------------\n";
	std::cout << "	---------------------------VECTOR---------------------------\n";
	std::cout << "	------------------------------------------------------------\n";
	my_time = get_time();
	vector_tester();
	my_time = get_time() - my_time;
	std::cout << "	--------------------------REAL VECTOR------------------------\n";
	real_time = get_time();
	real_vector_tester();
	real_time = get_time() - real_time;
	std::cout << "	--------------------------TIME DIFF-------------------------\n";
	std::cout << "			homemade ft containers = " << my_time << "ms\n";
	std::cout << "			real std containers = " << real_time << "ms\n";
	
	std::cout << "	------------------------------------------------------------\n";
	std::cout << "	-----------------------------MAP----------------------------\n";
	std::cout << "	------------------------------------------------------------\n";
	my_time = get_time();
	map_tester();
	my_time = get_time() - my_time;
	std::cout << "	---------------------------REAL MAP-------------------------\n";
	real_time = get_time();
	real_map_tester();
	real_time = get_time() - real_time;
	std::cout << "	--------------------------TIME DIFF-------------------------\n";
	std::cout << "			homemade ft containers = " << my_time << "ms\n";
	std::cout << "			real std containers = " << real_time << "ms\n";

	std::cout << "/* ************************************************************************** */\n";
	std::cout << "/* ******************************END OF TESTER******************************* */\n";
	std::cout << "/* ************************************************************************** */\n";
	return (0);
}