/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:54:25 by asahonet          #+#    #+#             */
/*   Updated: 2023/05/03 12:36:28 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_exec;
	public:
		Form();
		Form(std::string const name, int const grade_sign, int const grade_exec);
		Form(const Form &f);
		virtual	~Form();
		Form&	operator=(const Form &f);

		std::string	getName();
		bool		getIsSigned();
		int			getGradeSign();
		int			getGradeExec();
		
		class		GradeTooHighException: public std::exception
		{
			public:
				virtual const char 	*what() const _NOEXCEPT;
		};
		class		GradeTooLowException: public std::exception
		{
			public:
				virtual const char 	*what() const _NOEXCEPT;
		};

		void		beSigned(const Bureaucrat &b);
};

std::ostream&	operator<<(std::ostream& os, const Form &f);