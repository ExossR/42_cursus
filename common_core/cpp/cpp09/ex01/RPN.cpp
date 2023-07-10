/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:13:54 by asahonet          #+#    #+#             */
/*   Updated: 2023/07/06 14:30:26 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(): _stack()
{
}

RPN::RPN(const RPN& r)
{
	this->_stack = r._stack;
}

RPN::~RPN()
{
}

RPN&	RPN::operator=(const RPN& r)
{
	if (this != &r)
		this->_stack = r._stack;
	return (*this);
}

bool	RPN::isOperator(std::string c)
{
	if (c == "+" || c == "-" || c == "/" || c == "*")
		return (true);
	return (false);
}

double	RPN::doOpe(std::string op, double x1, double x2)
{
	if (op == "+")
		return (x1 + x2);
	else if (op == "-")
		return (x1 - x2);
	else if (op == "*")
		return (x1 * x2);
	else if (op == "/")
	{
		if (x2 == 0)
			throw std::invalid_argument("Error: Division by zero");
		return (x1 / x2);
	}
	else
		throw std::invalid_argument("Error: Invalid operator");
}

double	RPN::calcRPN(std::string s)
{
	std::stringstream	ss(s);
	std::string			op;

	while (ss >> op)
	{
		if (isOperator(op))
		{
			if (this->_stack.size() < 2)
				throw std::invalid_argument("Error: Not enough numbers for operator");
			double	x2 = this->_stack.top();
			this->_stack.pop();
			double	x1 = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(doOpe(op, x1, x2));
		}
		else
		{
			if (op.size() > 1 || op.c_str()[0] < 48 || op.c_str()[0] > 57)
				throw std::invalid_argument("Error: Invalid operand");			
			double	x = static_cast<double>(std::atof(op.c_str()));
			this->_stack.push(x);
		}
	}
	if (this->_stack.size() != 1)
		throw std::invalid_argument("Error: Invalid expression");
	return (this->_stack.top());
}
