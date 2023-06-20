/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:59:42 by asahonet          #+#    #+#             */
/*   Updated: 2023/05/03 12:33:49 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("The bureaucrat's grade is too high. OH PTN DiabloX9!");
}

const char	*Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("The bureaucrat's grade is too low. Damn Daniel stop it.");
}

/*-------------------------------------------------------*/

Bureaucrat::Bureaucrat(): _name("Jean"), _grade(150)
{
	//std::cout << "Default constructor Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int const grade): _name(name)
{
	if (grade >= 151)
		throw GradeTooLowException();
	else if (grade <= 0)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &b): _name(b._name), _grade(b._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &b)
{
	if (this != &b)
		_grade = b._grade;
	return (*this);
}

/*-------------------------------------------------------*/

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void		Bureaucrat::setGrade(int grade)
{
	if (grade <= 0)
		throw GradeTooHighException();
	else if (grade >= 151)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

/*-------------------------------------------------------*/

void		Bureaucrat::incrGrade()
{
	if (this->_grade - 1 <= 0)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void		Bureaucrat::decrGrade()
{
	if (this->_grade + 1 >= 151)
		throw GradeTooLowException();
	else
		this->_grade++;
}

/*-------------------------------------------------------*/

std::ostream&	operator<<(std::ostream& os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}