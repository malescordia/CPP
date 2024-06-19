/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:36:14 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/18 18:19:02 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &obj)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->grade = obj.grade;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &obj)
{
    std::cout << "Bureaucrat assignation operator called" << std::endl;
	this->grade = obj.grade;
	return(*this);
}

void	Bureaucrat::incrementGrade(int value)
{
	if (grade - value < 1)
		throw GradeTooHighException();
	grade -= value;
}

void	Bureaucrat::decrementGrade(int value)
{
	if (grade + value > 150)
		throw GradeTooLowException();
	grade += value;
}

std::string Bureaucrat::getName()
{
	return name;
}

int	Bureaucrat::getGrade()
{
	return grade;
}

bool Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << GREEN << getName() << " signed " << form.getName() << R << std::endl;
		std::cout << std::endl;
        return true;
    }
    catch(std::exception & e)
    {
        std::cerr << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		std::cout << std::endl;
        return false;
    }
}

void Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
		std::cout << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << getName() << " did not execute " << form.getName() << " because " << e.what() << std::endl;
		std::cout << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	std::cout << std::endl;
	return out;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}