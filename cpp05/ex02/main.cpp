/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:36:03 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/18 18:06:07 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat bob("Bob", 100);
	Bureaucrat marley("Marley", 50);
	Bureaucrat jones("Jones", 1); 

	RobotomyRequestForm form1("form 1");
	PresidentialPardonForm form2("form 2");
	ShrubberyCreationForm form3("form 3");
	
	std::cout << std::endl;

	try
	{
		bob.signForm(form1);
		marley.signForm(form1);
		jones.signForm(form1);
		bob.signForm(form2);
		marley.signForm(form2);
		jones.signForm(form2);
		bob.signForm(form3);
		marley.signForm(form3);
		jones.signForm(form3);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		bob.executeForm(form1);
		bob.executeForm(form2);
		bob.executeForm(form3);
		marley.executeForm(form1);
		marley.executeForm(form2);
		marley.executeForm(form3);
		jones.executeForm(form1);
		jones.executeForm(form2);
		jones.executeForm(form3);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
