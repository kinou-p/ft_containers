/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:55:17 by apommier          #+#    #+#             */
/*   Updated: 2022/11/29 19:09:23 by apommier         ###   ########.fr       */
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

template <typename T>
std::string	printPair(const T &iterator)
{
	std::cout << "key: " << iterator->first << " | value: " << iterator->second;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp)
{
	std::cout << "empty: " << mp.empty() << std::endl;
	std::cout << "size: " << mp.size() << std::endl;
	typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
	std::cout << std::endl << "Content is:" << std::endl;
	for (; it != ite; ++it)
		std::cout << "- " << printPair(it) << std::endl;
	std::cout << "-----------------\n";
}

void map_tester()
{
	std::cout << "----default constructor----" << std::endl;
	ft::map<int, int> ctnr;
	printSize(ctnr);
	for(int i = 0; i < 5; i++)
		ctnr.insert(ctnr.begin(), ft::make_pair(i, 5 - i));
	printSize(ctnr);
	std::cout << "max_size: " << ctnr.max_size() << std::endl;
	
	std::cout << "----copy constructor----" << std::endl;
	ft::map<int, int> ctnr2(ctnr);
	printSize(ctnr2);

	std::cout << "----range constructor----" << std::endl;
	ft::map<int, int> ctnr3(ctnr.begin()++, ((ctnr.end()--)--)--);
	printSize(ctnr3);
	
// ////////////////////////////////////
	
	std::cout << "----insert----\n";
	ctnr3.insert(ctnr3.begin(), ft::make_pair(10, 10));
	ctnr3.insert(ft::make_pair(10, 10));
	ctnr3.insert(ft::make_pair(11, 10));
	printSize(ctnr3);

	std::cout << "----insert with already in key ----\n";
	ctnr3.insert(ctnr3.begin(), ctnr3.end());
	printSize(ctnr3);
	
	std::cout << "----operator equal----\n";
	ft::map<int, int> ctnr4 = ctnr3;
	printSize(ctnr4);
	
	std::cout << "----insert range----\n";
	for(int i = 0; i < 5; i++)
		ctnr3.insert(ft::make_pair(i + 11, i + 20));
	printSize(ctnr3);
	
	std::cout << "---result (ctrn4)---\n";
	ctnr4.insert(ctnr3.begin(), ctnr3.end());
	printSize(ctnr4);
	
	std::cout << "----erase position----\n";
	ctnr4.erase(ctnr4.begin());
	printSize(ctnr4);
	
	std::cout << "----erase key (12)----\n";
	ctnr4.erase(12);
	printSize(ctnr4);
	
	std::cout << "----erase range----\n";
	ctnr4.erase(ctnr4.begin(), (ctnr4.end()--)--);
	printSize(ctnr4);

	std::cout << "----swap----\n";
	printSize(ctnr4);
	printSize(ctnr3);
	std::cout << "----after swap----\n";
	ctnr4.swap(ctnr3);
	printSize(ctnr4);
	printSize(ctnr3);

	std::cout << "---clear---\n";
	ctnr3.clear();
	printSize(ctnr3);

	std::cout << "---lower_bound---\n";
	printSize(ctnr2);
	std::cout << (ctnr2.lower_bound(2))->first << std::endl;
	
	std::cout << "---upper_bound---\n";
	printSize(ctnr2);
	std::cout << (ctnr2.upper_bound(2))->first << std::endl;

	std::cout << "---equal_range---\n";
	printSize(ctnr2);
	std::cout << "first= " << ctnr2.equal_range(2).first->first << " second= " << ctnr2.equal_range(2).second->second << std::endl;

	std::cout << "----iterator----\n";
	ft::map<int, int>::iterator ite = ctnr2.begin();
	printSize(ctnr2);

	ite = ctnr2.begin();

	std::cout << (++ite)->first << std::endl;
	std::cout << (ite++)->first << std::endl;
	std::cout << (ite++)->first << std::endl;
	std::cout << (++ite)->first << std::endl;
	
	std::cout << (--ite)->first << std::endl;
	std::cout << (ite--)->first << std::endl;
	std::cout << (--ite)->first << std::endl;
	std::cout << (ite--)->first << std::endl;

	std::cout << "----reverese iterator----\n";
	ft::map<int, int>::reverse_iterator it2 = ctnr2.rbegin();
	ft::map<int, int>::reverse_iterator ite2 = ctnr2.rend();
	printSize(ctnr2);

	it2 = ctnr2.rbegin();
	ite2 = ctnr2.rend();

	std::cout << "----rend---" << std::endl;
	std::cout << (--ite2)->first << std::endl;
	std::cout << (--ite2)->first << std::endl;	
	std::cout << (--ite2)->first << std::endl;
	std::cout << (ite2--)->first << std::endl;
	std::cout << (ite2--)->first << std::endl;
	std::cout << (ite2--)->first << std::endl;
	
	std::cout << "----rbegin---" << std::endl;
	std::cout << (++it2)->first << std::endl;
	std::cout << (++it2)->first << std::endl;
	std::cout << (++it2)->first << std::endl;
	std::cout << (it2++)->first << std::endl;
	std::cout << (it2++)->first << std::endl;

	std::cout << "----relationnal operator---" << std::endl;
	cmp(ctnr, ctnr2);

}

void real_map_tester()
{
	std::cout << "----default constructor----" << std::endl;
	std::map<int, int> ctnr;
	printSize(ctnr);
	for(int i = 0; i < 5; i++)
		ctnr.insert(ctnr.begin(), std::make_pair(i, 5 - i));
	printSize(ctnr);
	std::cout << "max_size: " << ctnr.max_size() << std::endl;
	
	std::cout << "----copy constructor----" << std::endl;
	std::map<int, int> ctnr2(ctnr);
	printSize(ctnr2);

	std::cout << "----range constructor----" << std::endl;
	std::map<int, int> ctnr3(ctnr.begin()++, ((ctnr.end()--)--)--);
	printSize(ctnr3);
	
// ////////////////////////////////////
	
	std::cout << "----insert----\n";
	ctnr3.insert(ctnr3.begin(), std::make_pair(10, 10));
	ctnr3.insert(std::make_pair(10, 10));
	ctnr3.insert(std::make_pair(11, 10));
	printSize(ctnr3);

	std::cout << "----insert with already in key ----\n";
	ctnr3.insert(ctnr3.begin(), ctnr3.end());
	printSize(ctnr3);
	
	std::cout << "----operator equal----\n";
	std::map<int, int> ctnr4 = ctnr3;
	printSize(ctnr4);
	
	std::cout << "----insert range----\n";
	for(int i = 0; i < 5; i++)
		ctnr3.insert(std::make_pair(i + 11, i + 20));
	printSize(ctnr3);
	
	std::cout << "---result (ctrn4)---\n";
	ctnr4.insert(ctnr3.begin(), ctnr3.end());
	printSize(ctnr4);
	
	std::cout << "----erase position----\n";
	ctnr4.erase(ctnr4.begin());
	printSize(ctnr4);
	
	std::cout << "----erase key (12)----\n";
	ctnr4.erase(12);
	printSize(ctnr4);
	
	std::cout << "----erase range----\n";
	ctnr4.erase(ctnr4.begin(), (ctnr4.end()--)--);
	printSize(ctnr4);

	std::cout << "----swap----\n";
	printSize(ctnr4);
	printSize(ctnr3);
	std::cout << "----after swap----\n";
	ctnr4.swap(ctnr3);
	printSize(ctnr4);
	printSize(ctnr3);

	std::cout << "---clear---\n";
	ctnr3.clear();
	printSize(ctnr3);

	std::cout << "---lower_bound---\n";
	printSize(ctnr2);
	std::cout << (ctnr2.lower_bound(2))->first << std::endl;
	
	std::cout << "---upper_bound---\n";
	printSize(ctnr2);
	std::cout << (ctnr2.upper_bound(2))->first << std::endl;

	std::cout << "---equal_range---\n";
	printSize(ctnr2);
	std::cout << "first= " << ctnr2.equal_range(2).first->first << " second= " << ctnr2.equal_range(2).second->second << std::endl;

	std::cout << "----iterator----\n";
	std::map<int, int>::iterator ite = ctnr2.begin();
	printSize(ctnr2);

	ite = ctnr2.begin();

	std::cout << (++ite)->first << std::endl;
	std::cout << (ite++)->first << std::endl;
	std::cout << (ite++)->first << std::endl;
	std::cout << (++ite)->first << std::endl;
	
	std::cout << (--ite)->first << std::endl;
	std::cout << (ite--)->first << std::endl;
	std::cout << (--ite)->first << std::endl;
	std::cout << (ite--)->first << std::endl;

	std::cout << "----reverese iterator----\n";
	std::map<int, int>::reverse_iterator it2 = ctnr2.rbegin();
	std::map<int, int>::reverse_iterator ite2 = ctnr2.rend();
	printSize(ctnr2);

	it2 = ctnr2.rbegin();
	ite2 = ctnr2.rend();

	std::cout << "----rend---" << std::endl;
	std::cout << (--ite2)->first << std::endl;
	std::cout << (--ite2)->first << std::endl;	
	std::cout << (--ite2)->first << std::endl;
	std::cout << (ite2--)->first << std::endl;
	std::cout << (ite2--)->first << std::endl;
	std::cout << (ite2--)->first << std::endl;
	
	std::cout << "----rbegin---" << std::endl;
	std::cout << (++it2)->first << std::endl;
	std::cout << (++it2)->first << std::endl;
	std::cout << (++it2)->first << std::endl;
	std::cout << (it2++)->first << std::endl;
	std::cout << (it2++)->first << std::endl;

	std::cout << "----relationnal operator---" << std::endl;
	cmp(ctnr, ctnr2);
}