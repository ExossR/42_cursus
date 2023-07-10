/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:12:23 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/06 12:41:17 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _date_val(readBitcoinPrices())
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& b)
{
	this->_date_val = b._date_val;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& b)
{
	if (this != &b)
		this->_date_val = b._date_val;
	return (*this);
}

std::map<std::string, double>	BitcoinExchange::getMapDateVal()
{
	return (this->_date_val);
}

std::map<std::string, double>	BitcoinExchange::readBitcoinPrices()
{
	std::map<std::string, double>	map;
	std::ifstream					file("data.csv");

	if (!file.is_open())
	{
		std::cerr << "Error: failed to open file" << std::endl;
		return (map);
	}

	std::string	line;
	std::getline(file, line);
	if (line.find("date") == std::string::npos || line.find("exchange_rate") == std::string::npos)
	{
		std::cerr << "Error: wrong header" << std::endl;
		return (map);
	}
	while (std::getline(file, line))
	{
		std::string			date = line.substr(0, line.find(','));
		std::string			valstr = line.substr(line.find(',') + 1);
		double				val = static_cast<double>(std::atof(valstr.c_str()));

		map.insert(std::pair<std::string, double>(date, val));
	}
	file.close();
	return (map);
}

double							BitcoinExchange::findClosestDate(const std::string date)
{
	std::map<std::string, double>::iterator	it = this->_date_val.begin();
	std::map<std::string, double>::iterator	ite = this->_date_val.end();

	while (it != ite)
	{
		if (it->first == date)
			return (it->second);
		if (it->first > date)
		{
			if (it != this->_date_val.begin())
			{
				it--;
				return (it->second);
			}
			return (0);
		}
		it++;
	}
	it--;
	return (it->second);
}

bool							BitcoinExchange::isDateGood(std::string date)
{
	int	year = static_cast<int>(std::atoi(date.substr(0, date.find('-')).c_str()));
	date = date.substr(date.find('-') + 1);
	int	month = static_cast<int>(std::atoi(date.substr(0, date.find('-')).c_str()));
	int	day	= static_cast<int>(std::atoi(date.substr(date.find('-') + 1).c_str()));

	if (year < 0)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		&& (day < 1 || day > 31))
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11)
		&& (day < 1 || day > 30))
		return (false);
	if (month == 2)
	{
		if (year % 4 == 0 && (day < 1 || day > 29))
			return (false);
		if (day < 1 || day > 28)
			return (false);
	}
	return (true);
}

void							BitcoinExchange::printResults(const std::string filename)
{
	std::ifstream	file(filename);
	
	if (!file.is_open())
		throw std::invalid_argument("Error: failed to open");

	std::string	line;
	std::getline(file, line);
	if (line.find("date") == std::string::npos || line.find("value") == std::string::npos)
		throw std::invalid_argument("Error: wrong header");

	while (std::getline(file, line))
	{
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		
		std::string	date = line.substr(0, (line.find('|') != std::string::npos ? line.find('|') : line.size()));
		if (isDateGood(date))
		{
			std::string	valstr = "";
			if (line.find('|') == std::string::npos || line.find('|') + 1 == line.size())
				std::cerr << "Error: no number found." << std::endl;
			else
			{
				valstr = line.substr(line.find('|') + 1);
				double	n = static_cast<double>(std::atof(valstr.c_str()));
				if (n < 0)
					std::cerr << "Error: not a positive number." << std::endl;
				else if (n > 1000)
					std::cerr << "Error: too large a number." << std::endl;
				else
				{
					std::cout << date << " => " << n << " = ";
					n *= findClosestDate(date);
					std::cout << n << std::endl;
				}
			}
		}
		else
			std::cerr << "Error: bad input => " << date << std::endl;
	}
}
