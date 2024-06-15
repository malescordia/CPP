/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:06:39 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/15 20:33:04 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &obj) : Form(obj)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    target = obj.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &obj)
{
    std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
    Form::operator=(obj);
    target = obj.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat &obj)
{
    if (!getSignature())
    {
        throw FormIsNotSigned();
    }
    if (getExecute() > obj.getGrade())
    {
        throw GradeTooLowException();
    }
    std::cout << target << " has been pardoned by Zaphod BeebleBrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}