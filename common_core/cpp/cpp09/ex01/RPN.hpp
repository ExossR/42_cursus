/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:09:25 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/06 14:30:39 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stack>
#include <iostream>
#include <exception>
#include <sstream>

class RPN
{
	private:
		std::stack<double>	_stack;

	public:
		RPN();
		RPN(const RPN& r);
		~RPN();
		RPN&	operator=(const RPN& r);

		bool	isOperator(std::string c);
		double	doOpe(std::string op, double x1, double x2);
		double	calcRPN(std::string s);
};