/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:37:16 by asahonet          #+#    #+#             */
/*   Updated: 2023/05/03 13:05:35 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Form"), _is_signed(false), _grade_to_sign(150), _grade_to_exec(150)
{	
}

Form::Form(std::string const name, int const grade_sign, int const grade_exec): _name(name), _is_signed(false), _grade_to_sign(grade_sign), _grade_to_exec(grade_exec)
{
	if (grade_sign >= 151 || grade_exec >= 151)
		throw GradeTooLowException();
	else if (grade_sign <= 0 || grade_exec <= 0)
		throw GradeTooHighException();
}

Form::Form(const Form &f): _name(f._name), _is_signed(f._is_signed), _grade_to_sign(f._grade_to_sign), _grade_to_exec(f._grade_to_exec)
{
	if (f._grade_to_sign >= 151 || f._grade_to_exec >= 151)
		throw GradeTooLowException();
	else if (f._grade_to_sign <= 0 || f._grade_to_exec <= 0)
		throw GradeTooHighException();
}

Form::~Form()
{
}

Form&	Form::operator=(const Form &f)
{
	this->_is_signed = f._is_signed;
	return (*this);
}

/*--------------------------------------------------------*/

std::string	Form::getName()
{
	return (this->_name);
}

bool		Form::getIsSigned()
{
	return (this->_is_signed);
}

int			Form::getGradeSign()
{
	return (this->_grade_to_sign);
}

int			Form::getGradeExec()
{
	return (this->_grade_to_exec);
}

/*--------------------------------------------------------*/

std::ostream&	operator<<(std::ostream& os, const Form &f)
{
	os << f.getName() << ", form signed : " << f.getIsSigned() << ", form grade to sign : " 
		<< f.getGradeSign() << ", for grade to exec : " << f.getGradeExec();
	return (os);
}

/*--------------------------------------------------------*/

void		Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() >= this->_grade_to_sign)
		this->_is_signed = true;
	else
		throw GradeTooLowException();
}

/*--------------------------------------------------------*/

const char	*Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("The Form's grade is too high. The paper is wrong.");
}

const char	*Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("The Form's grade is too low. This paper is shit.");
}