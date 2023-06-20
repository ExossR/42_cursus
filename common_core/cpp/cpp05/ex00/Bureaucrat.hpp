/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:07:20 by asahonet          #+#    #+#             */
/*   Updated: 2023/05/02 19:02:13 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& b);
		virtual		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat &b);
		
		const std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int grade);
		
		void		incrGrade();
		void		decrGrade();

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
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat const &b);