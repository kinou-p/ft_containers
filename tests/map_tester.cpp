/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:55:17 by apommier          #+#    #+#             */
/*   Updated: 2022/11/29 15:12:31 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_containers.hpp"

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

void map_tester()
{
// 	std::cout << "----default constructor----" << std::endl;
// 	ft::map<int, int> ctnr;
// 	printSize(ctnr);

// 	std::cout << "----copy constructor----" << std::endl;
// 	ft::map<int, int> ctnr_copy(ctnr);
// 	printSize(ctnr_copy);
	
// 	std::cout << "----range constructor----" << std::endl;
// 	ft::map<int, int> ctnr2(ctnr.begin(), ctnr.end());
// 	printSize(ctnr2);

// ////////////////////////////////////
// 	std::cout << "----insert at position + assign constrcutor----" << std::endl;
// 	ft::map<int, int> ctnr4(5, 5);
// 	printSize(ctnr4);
	
// 	std::cout << "----insert----\n";
// 	ctnr4.insert(ctnr4.begin() + 3, 100);
// 	printSize(ctnr4);

// 	std::cout << "----insert fill----\n";
// 	ctnr4.insert(ctnr4.begin() + 3, 5, 100);
// 	printSize(ctnr4);
	
// 	std::cout << "----operator equal----\n";
// 	ft::map<int, int> ctnr5;
// 	ctnr5 = ctnr4;
// 	printSize(ctnr5);
	
// 	std::cout << "----insert range----\n";
// 	ctnr5.insert(ctnr5.begin() + 2, ctnr.begin()++, ctnr.end()--);
// 	printSize(ctnr5);

// 	std::cout << "----erase----\n";
// 	ctnr5.erase(ctnr5.end() - 5);
// 	printSize(ctnr5);
	
// 	std::cout << "----erase range----\n";
// 	ctnr5.erase(ctnr5.begin(), ctnr5.end() - 5);
// 	printSize(ctnr5);

// 	std::cout << "----swap----\n";
// 	ctnr5.swap(ctnr);
// 	std::cout << "----ctnr----\n";
// 	printSize(ctnr);
// 	std::cout << "----ctnr5----\n";
// 	printSize(ctnr5);

// 	std::cout << "----clear----\n";
// 	ctnr.clear();
// 	printSize(ctnr);
// ///////////////

// 	std::cout << "----relationnal ope----\n";
// 	cmp(ctnr, ctnr4);
}

void real_map_tester()
{
	
}