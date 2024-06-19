/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:36:03 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/18 18:48:30 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) 
{
	Intern	intern;
	AForm	*forms[4];
	std::string formTypes[4] = {"shrubbery creation", "robotomy request", "dfggrf", "presidential pardon"};

	Bureaucrat bro("Bro", 1);
	
	int i = 0;
	{
		try
		{
			forms[i] = intern.makeForm(formTypes[i], "TARGET");
			bro.signForm(*forms[i]);
			bro.executeForm(*forms[i]);
			delete forms[i];
		}
		catch(std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	i++;
	{
		try
		{
			forms[i] = intern.makeForm(formTypes[i], "TARGET");
			bro.signForm(*forms[i]);
			bro.executeForm(*forms[i]);
			delete forms[i];
		}
		catch(std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	i++;
	{
		try
		{
			forms[i] = intern.makeForm(formTypes[i], "TARGET");
			bro.signForm(*forms[i]);
			bro.executeForm(*forms[i]);
			delete forms[i];
		}
		catch(std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	i++;
	{
		try
		{
			forms[i] = intern.makeForm(formTypes[i], "TARGET");
			bro.signForm(*forms[i]);
			bro.executeForm(*forms[i]);
			delete forms[i];
		}
		catch(std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
