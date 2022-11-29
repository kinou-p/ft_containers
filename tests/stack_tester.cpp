/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tester.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:55:21 by apommier          #+#    #+#             */
/*   Updated: 2022/11/29 13:50:26 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_containers.hpp"


template <typename T_STACK>
void	printSize(T_STACK &cntr)
{
	std::cout << "empty: " << cntr.empty() << std::endl;
	std::cout << "size: " << cntr.size() << std::endl;
	std::cout << std::endl << "Content :" << std::endl;
	while (cntr.size() != 0) {
		std::cout << cntr.top() << std::endl;
		cntr.pop();
	}
}

template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
{
	std::cout << "== : " << (lhs == rhs) << " | != : " << (lhs != rhs) << std::endl;
	std::cout << "< : " << (lhs <  rhs) << " | <= : " << (lhs <= rhs) << std::endl;
	std::cout << "> : " << (lhs >  rhs) << " | >= : " << (lhs >= rhs) << std::endl;
}

void stack_tester()
{
	ft::vector<int>	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	std::cout << "----container copy constructor----\n";
	ft::stack<int>	stack_ctnr(ctnr);
	
	stack_ctnr.push(1);
	stack_ctnr.push(2);
	stack_ctnr.push(3);
	stack_ctnr.push(4);
	stack_ctnr.push(5);
	stack_ctnr.push(6);

	printSize(stack_ctnr);
	
	std::cout << "----default constructor----\n";
	ft::stack<int> stack_ctnr2;
	
	stack_ctnr2.push(11);
	stack_ctnr2.push(21);
	stack_ctnr2.push(31);
	stack_ctnr2.push(41);
	stack_ctnr2.push(51);
	stack_ctnr2.push(61);
	
	printSize(stack_ctnr2);

	std::cout << "----stack copy constructor----\n";
	
	stack_ctnr2.push(11);
	stack_ctnr2.push(21);
	stack_ctnr2.push(31);
	stack_ctnr2.push(41);
	stack_ctnr2.push(51);
	stack_ctnr2.push(61);

	ft::stack<int> stack_ctnr3(stack_ctnr2);
	printSize(stack_ctnr3);

	std::cout << "----relationnal ope----\n";
	stack_ctnr3 = stack_ctnr2;
	cmp(stack_ctnr2, stack_ctnr2);
}

















void real_stack_tester()
{
	std::deque<int>	ctnr2;

	ctnr2.push_back(21);
	ctnr2.push_back(42);
	ctnr2.push_back(1337);
	ctnr2.push_back(19);
	ctnr2.push_back(0);
	ctnr2.push_back(183792);

	std::cout << "----container copy constructor----\n";
	std::stack<int>	stack_ctnr(ctnr2);
	
	stack_ctnr.push(1);
	stack_ctnr.push(2);
	stack_ctnr.push(3);
	stack_ctnr.push(4);
	stack_ctnr.push(5);
	stack_ctnr.push(6);

	printSize(stack_ctnr);
	
	std::cout << "----default constructor----\n";
	std::stack<int> stack_ctnr2;
	
	stack_ctnr2.push(11);
	stack_ctnr2.push(21);
	stack_ctnr2.push(31);
	stack_ctnr2.push(41);
	stack_ctnr2.push(51);
	stack_ctnr2.push(61);
	
	printSize(stack_ctnr2);

	std::cout << "----stack copy constructor----\n";
	
	stack_ctnr2.push(11);
	stack_ctnr2.push(21);
	stack_ctnr2.push(31);
	stack_ctnr2.push(41);
	stack_ctnr2.push(51);
	stack_ctnr2.push(61);

	std::stack<int> stack_ctnr3(stack_ctnr2);
	printSize(stack_ctnr3);

	std::cout << "----relationnal ope----\n";
	stack_ctnr3 = stack_ctnr2;
	cmp(stack_ctnr2, stack_ctnr2);
}