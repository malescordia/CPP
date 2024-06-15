/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:19:19 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/15 15:18:32 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}
