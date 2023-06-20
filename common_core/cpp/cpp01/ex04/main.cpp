/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:40:48 by asahonet          #+#    #+#             */
/*   Updated: 2023/04/12 13:46:58 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	replace_str(std::string buf, std::string str1, std::string str2)
{
	std::string	tmp;
	std::string	tmp1;
	int			pos = 0;
	int			sizeS1 = str1.size();
	
	while ((pos = buf.find(str1)) != -1)
	{
		tmp = buf.substr(0, pos);
		tmp1 = buf.substr(pos + sizeS1, buf.size());
		buf.clear();
		buf.reserve(sizeS1 + tmp.size() + tmp1.size());
		buf.append(tmp);
		buf.append(str2);
		buf.append(tmp1);
	}
	return (buf);
}

bool	already_existing(std::string name)
{
	std::ifstream	tmp(name.c_str());
	return (tmp.good());
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Please enter 3 parameters (filename + 2 strings)." << std::endl;
		return (1);
	}
	else if (!argv[2][0] || !argv[3][0])
	{
		std::cout << "Parameters need to be not empty. Please retry." << std::endl;
		return (1);
	}
	
	std::fstream	file;
	std::string		buf;
	std::string		tmp;
	
	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Failed to open the file." << std::endl;
		return (1);
	}
	std::getline(file, buf);
	while (!file.eof())
	{
		buf = replace_str(buf, argv[2], argv[3]);
		tmp.append(buf);
		tmp += "\n";
		std::getline(file, buf);
	}
	buf = replace_str(buf, argv[2], argv[3]);
	tmp.append(buf);
	file.close();

	buf.clear();
	buf.append(argv[1]);
	buf.append(".replace");
	if (already_existing(buf))
	{
		std::cout << "The file '.replace' is already existing. Please delete it." << std::endl;
		return (1);
	}
	
	std::ofstream	write_file(buf);

	if (!write_file.is_open())
	{
		std::cout << "Failed to create the file." << std::endl;
		return (1);
	}
	write_file << tmp;
	write_file.close();
	return (0);
}