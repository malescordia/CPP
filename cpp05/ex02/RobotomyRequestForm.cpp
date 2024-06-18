/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:06:45 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/18 18:21:02 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &obj) : AForm(obj)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    target = obj.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &obj)
{
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    AForm::operator=(obj);
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
        std::cout << YELLOW << target << " has been robotomized successfully" R << std::endl;
    else
        std::cout << YELLOW << target << ": robotomy failed" R << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}