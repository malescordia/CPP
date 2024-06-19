/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:36:03 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/19 18:57:09 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat	brotest("Brotest", 666);
		std::cout << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << std::endl;
	}

	try
	{
		Bureaucrat	bro("Bro", 3);

		bro.decrementGrade(4);
		std::cout << "Bureaucrat " << bro.getName() << " grade: "<< bro.getGrade() << std::endl;
		bro.incrementGrade(4);
		std::cout << "Bureaucrat " << bro.getName() << " grade: "<< bro.getGrade() << std::endl;
        bro.decrementGrade(8);
		std::cout << "Bureaucrat " << bro.getName() << " grade: "<< bro.getGrade() << std::endl;
		std::cout << std::endl;

		Form form1("form1", 3, 3);
		Form form2("form2", 40, 3);

		bro.signForm(form1);
		bro.signForm(form1);
		bro.signForm(form2);
		std::cout << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << std::endl;
	}
}
