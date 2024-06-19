/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:29:05 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/19 18:49:49 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern &obj)
{
	(void)obj;
}

Intern &Intern::operator=(Intern &obj)
{
	(void)obj;
	return *this;
};

AForm* Intern::makePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string formType, std::string target)
{
	AForm *(Intern::*func[4])(std::string target) = {
			&Intern::makePresidentialPardonForm,
			&Intern::makeShrubberyCreationForm,
			&Intern::makeRobotomyRequestForm};
	std::string types[3] = {
			"presidential pardon",
			"shrubbery creation",
			"robotomy request"};
	for (int i = 0; i < 4; i++)
	{
		if (formType == types[i]){
			std::cout << GREEN << "Intern creates " << formType << " form." R << std::endl;
		return (this->*func[i])(target);
		}
	}
	throw ErrorMakingForm();
	return (NULL);
}

Intern::~Intern()
{
    std::cout << "Intern default destructor called" << std::endl;
}