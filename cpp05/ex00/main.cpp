/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:19:34 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/19 18:55:08 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{ 
	try
    {
		Bureaucrat	brotest("Brotest", 666);
        std::cout << "Bureaucrat " << brotest.getName() << " grade: "<< brotest.getGrade() << std::endl;
		std::cout << std::endl;
    }
	catch (std::exception & e)
    {
		std::cerr << e.what() << std::endl;
		std::cout << std::endl;
    }
    
	try
	{
		Bureaucrat bro("Bro", 6);

	 	bro.incrementGrade(2);
		std::cout << "Bureaucrat " << bro.getName() << " grade: "<< bro.getGrade() << std::endl;
	 	bro.incrementGrade(3);
		std::cout << "Bureaucrat " << bro.getName() << " grade: "<< bro.getGrade() << std::endl;
	 	bro.decrementGrade(149);
		std::cout << "Bureaucrat " << bro.getName() << " grade: "<< bro.getGrade() << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << std::endl;
	}
	
}
