/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:55:23 by apommier          #+#    #+#             */
/*   Updated: 2022/11/29 15:06:00 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_containers.hpp"

template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
{
	std::cout << "== : " << (lhs == rhs) << " | != : " << (lhs != rhs) << std::endl;
	std::cout << "< : " << (lhs <  rhs) << " | <= : " << (lhs <= rhs) << std::endl;
	std::cout << "> : " << (lhs >  rhs) << " | >= : " << (lhs >= rhs) << std::endl;
}

void	printSize(ft::vector<int> const &vct)
{
	std::cout << "size: " << vct.size() << std::endl;
	std::cout << "capacity: " << vct.capacity() << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	ft::vector<int>::const_iterator it = vct.begin();
	ft::vector<int>::const_iterator ite = vct.end();
	std::cout << std::endl << "Content is:" << std::endl;
	for (; it != ite; ++it)
		std::cout << "- " << *it << std::endl;
}

void	printSize_real(std::vector<int> const &vct)
{
	std::cout << "size: " << vct.size() << std::endl;
	std::cout << "capacity: " << vct.capacity() << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	std::vector<int>::const_iterator it = vct.begin();
	std::vector<int>::const_iterator ite = vct.end();
	std::cout << std::endl << "Content is:" << std::endl;
	for (; it != ite; ++it)
		std::cout << "- " << *it << std::endl;
}

void vector_tester()
{
	std::cout << "----default constructor----" << std::endl;
	ft::vector<int> ctnr;
	printSize(ctnr);
	
	std::cout << "----assign val----" << std::endl;
	ctnr.assign(10, 1);
	printSize(ctnr);

	std::cout << "----copy constructor----" << std::endl;
	ft::vector<int> ctnr_copy(ctnr);
	printSize(ctnr_copy);
	
	std::cout << "----range constructor----" << std::endl;
	ft::vector<int> ctnr2(ctnr.begin(), ctnr.end());
	printSize(ctnr2);
	
	std::cout << "----range assign----" << std::endl;
	ft::vector<int> ctnr3;
	ctnr3.assign(ctnr.begin(), ctnr.end());
	printSize(ctnr3);
////////////////////////////////////
	std::cout << "----insert at position + assign constrcutor----" << std::endl;
	ft::vector<int> ctnr4(5, 5);
	printSize(ctnr4);
	
	std::cout << "----insert----\n";
	ctnr4.insert(ctnr4.begin() + 3, 100);
	printSize(ctnr4);

	std::cout << "----insert fill----\n";
	ctnr4.insert(ctnr4.begin() + 3, 5, 100);
	printSize(ctnr4);
	
	std::cout << "----operator equal----\n";
	ft::vector<int> ctnr5;
	ctnr5 = ctnr4;
	printSize(ctnr5);
	
	std::cout << "----insert range----\n";
	ctnr5.insert(ctnr5.begin() + 2, ctnr.begin()++, ctnr.end()--);
	printSize(ctnr5);

	std::cout << "----erase----\n";
	ctnr5.erase(ctnr5.end() - 5);
	printSize(ctnr5);
	
	std::cout << "----erase range----\n";
	ctnr5.erase(ctnr5.begin(), ctnr5.end() - 5);
	printSize(ctnr5);

	std::cout << "----swap----\n";
	ctnr5.swap(ctnr);
	std::cout << "----ctnr----\n";
	printSize(ctnr);
	std::cout << "----ctnr5----\n";
	printSize(ctnr5);

	std::cout << "----clear----\n";
	ctnr.clear();
	printSize(ctnr);
///////////////
	std::cout << "----iterator----\n";
	ft::vector<int>::iterator it = ctnr4.begin();
	ft::vector<int>::iterator ite = ctnr4.end();

	for (int i = 1; it != ite; ++i)
		*it++ = i;
	printSize(ctnr4);

	it = ctnr4.begin();
	ite = ctnr4.begin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;

	std::cout << "----relationnal ope----\n";
	cmp(ctnr, ctnr4);
}

void real_vector_tester()
{
	std::cout << "----default constructor----" << std::endl;
	std::vector<int> ctnr;
	printSize_real(ctnr);
	
	std::cout << "----assign val----" << std::endl;
	ctnr.assign(10, 1);
	printSize_real(ctnr);
	
	std::cout << "----range constructor----" << std::endl;
	std::vector<int> ctnr2(ctnr.begin(), ctnr.end());
	printSize_real(ctnr2);
	
	std::cout << "----range assign----" << std::endl;
	std::vector<int> ctnr3;
	ctnr3.assign(ctnr.begin(), ctnr.end());
	printSize_real(ctnr3);

	std::cout << "----insert at position + assign constrcutor----" << std::endl;
	std::vector<int> ctnr4(5, 5);
	printSize_real(ctnr4);
	
	std::cout << "----insert----\n";
	ctnr4.insert(ctnr4.begin() + 3, 100);
	printSize_real(ctnr4);

	std::cout << "----insert fill----\n";
	ctnr4.insert(ctnr4.begin() + 3, 5, 100);
	printSize_real(ctnr4);
	
	std::cout << "----operator equal----\n";
	std::vector<int> ctnr5;
	ctnr5 = ctnr4;
	printSize_real(ctnr5);
	
	std::cout << "----insert range----\n";
	ctnr5.insert(ctnr5.begin() + 2, ctnr.begin()++, ctnr.end()--);
	printSize_real(ctnr5);

	std::cout << "----erase----\n";
	ctnr5.erase((ctnr5.end()) - 5);
	printSize_real(ctnr5);
	
	std::cout << "----erase range----\n";
	ctnr5.erase(ctnr5.begin(), ctnr5.end() - 5);
	printSize_real(ctnr5);

	std::cout << "----swap----\n";
	ctnr5.swap(ctnr);
	std::cout << "----ctnr----\n";
	printSize_real(ctnr);
	std::cout << "----ctnr5----\n";
	printSize_real(ctnr5);

	std::cout << "----clear----\n";
	ctnr.clear();
	printSize_real(ctnr);

	std::cout << "----iterator----\n";
	std::vector<int>::iterator it = ctnr4.begin();
	std::vector<int>::iterator ite = ctnr4.end();

	for (int i = 1; it != ite; ++i)
		*it++ = i;
	printSize_real(ctnr4);

	it = ctnr4.begin();
	ite = ctnr4.begin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;

	std::cout << "----relationnal ope----\n";
	cmp(ctnr, ctnr4);

	 
}