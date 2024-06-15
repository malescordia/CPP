/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:19:34 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/15 15:18:15 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
    {
		Bureaucrat	test("test", 151);
    }
	catch (std::exception & e)
    {
		std::cerr << e.what() << std::endl;
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
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/*
    NEW STUFF:
        what()  - function is a virtual function from std::exception class. It is used to return a string that describes the error.
        throw() - is used to specify that the function does not throw any exceptions.
        try     - is used to test a block of code for errors.
        catch   - is used to handle the error. 
*/
