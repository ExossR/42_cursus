/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:37:12 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/05 13:43:18 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <exception>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_date_val;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& b);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& b);
		
		std::map<std::string, double>	getMapDateVal();
		
		std::map<std::string, double>	readBitcoinPrices();
		double							findClosestDate(const std::string date);
		bool							isDateGood(const std::string date);
		void							printResults(const std::string filename);
};