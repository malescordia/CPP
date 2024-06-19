/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:36:09 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/18 17:43:24 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name) : name(name), signature(false), to_sign(100), to_execute(100)
{
    std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign, int execute) : name(name), signature(false), to_sign(sign), to_execute(execute)
{
    std::cout << "Form constructor called" << std::endl;
}

AForm::AForm(AForm &obj) : name(obj.getName()), signature(obj.getSignature()), to_sign(obj.getSign()), to_execute(obj.getExecute())
{
    std::cout << "Form copy constructor called" << std::endl;
    this->signature = obj.signature;
}

AForm &AForm::operator=(AForm &obj)
{
    this->signature = obj.signature;
    return(*this);
}

void AForm::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() > to_sign)
        throw GradeTooLowException();
    if (getSignature() == true)
        throw FormIsAlreadySigned();
    signature = true;
}

std::string AForm::getName()
{
    return name;
}

int         AForm::getSign()
{
    return to_sign;
}

int         AForm::getExecute()
{
    return to_execute;
}

bool        AForm::getSignature()
{
    return signature;
}

std::ostream &operator<<(std::ostream &out, AForm &obj)
{
    out << "Form \"" << obj.getName() << "\" ";
    if (obj.getSignature())
        out << "is signed\n";
    else
        out << "is not signed";
    return out;
}

AForm::~AForm()
{
    std::cout << "Form destructor called" << std::endl;
}