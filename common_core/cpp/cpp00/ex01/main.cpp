/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:27:43 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/30 19:43:41 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <sstream> 

int	contact_empty(Contact c)
{
	if (c.get_fn().empty() == true || c.get_ln().empty() == true
		|| c.get_nn().empty() == true || c.get_pn().empty() == true
		|| c.get_ds().empty() == true)
		return (0);
	return (1);
}

void	print_inf(std::string str)
{
	int	i = -1;
	
	if (str.size() > 10)
	{
		while (++i < 9)
			std::cout << str[i];
		std::cout << ".|";
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << str << '|';
	}
}

int	main()
{
	int			i;
	PhoneBook	ph;
	Contact		c_tmp;
	std::string	tmp;
	std::string	c_fn;
	std::string	c_ln;
	std::string	c_nn;
	std::string	c_pn;
	std::string	c_ds;

	std::cout << "Bonjour !" << std::endl;
	tmp = "oui";
	while (1)
	{
		if (std::cin.eof())
			break ;
		std::cout << "Entrez une commande (ADD, SEARCH ou EXIT): " << std::endl;
		std::getline(std::cin, tmp);
		if (tmp == "EXIT")
			break ;
		else if (tmp == "ADD")
		{
			std::cout << "Veuillez remplir les details du nouveau contact :\nPrenom : ";
			std::getline(std::cin, c_fn);
			std::cout << "Nom : ";
			std::getline(std::cin, c_ln);
			std::cout << "Surnom : ";
			std::getline(std::cin, c_nn);
			std::cout << "Numero de telephone : ";
			std::getline(std::cin, c_pn);
			std::cout << "Secret sombre : ";
			std::getline(std::cin, c_ds);
			ph.add_contact(c_fn, c_ln, c_nn, c_pn, c_ds);
		}
		else if (tmp == "SEARCH")
		{
			i = 0;
			if (contact_empty(ph.get_tab(i)) == 1)
			{
				while (i < 8)
				{
					if (contact_empty(ph.get_tab(i)) == 0)
						break ;
					std::cout << i << "|"; 
					print_inf(ph.get_tab(i).get_fn());
					print_inf(ph.get_tab(i).get_ln());
					print_inf(ph.get_tab(i).get_nn());
					std::cout << std::endl;
					i++;
				}
				std::cout << "Quel contact voulez-vous choisir ? (Choisissez un index)" << std::endl;
				std::getline(std::cin, tmp);
				std::istringstream(tmp) >> i;
				ph.search_contact(i);
			}
			else
				std::cout << "Il n'y a pas de contact a afficher." << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << "Merci et au revoir." << std::endl;
}