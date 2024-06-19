/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:28:58 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/19 18:42:32 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class AForm;

class Intern 
{
	private:
	 	AForm* makePresidentialPardonForm(std::string target);
		AForm* makeShrubberyCreationForm(std::string target);
		AForm* makeRobotomyRequestForm(std::string target);

	public:
		Intern();
		Intern (Intern &obj);
		Intern &operator=(Intern &obj);
		~Intern();

		AForm *makeForm(std::string formType, std::string target);

		class ErrorMakingForm : public std::exception 
        {
			public:
				virtual const char *what() const throw() 
                {
                    return (RED "Intern can't make an unknown form" R); 
                }
		};
};

#endif