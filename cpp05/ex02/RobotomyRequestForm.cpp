/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:06:45 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/15 20:54:07 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &obj) : Form(obj)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    target = obj.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &obj)
{
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    Form::operator=(obj);
    target = obj.target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat &obj)
{
    if (!getSignature())
    {
        throw FormIsNotSigned();
    }
    if (getExecute() > obj.getGrade())
    {
        throw GradeTooLowException();
    }
    srand(time(NULL));
    std::cout << getName() << ": * make some noize *" << std::endl;
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << target << ": robotomy failed" << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}