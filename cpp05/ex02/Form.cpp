/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:36:09 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/15 18:45:43 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name) : name(name), signature(false), to_sign(100), to_execute(100)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int sign, int execute) : name(name), signature(false), to_sign(sign), to_execute(execute)
{
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form &obj) : name(obj.getName()), signature(obj.getSignature()), to_sign(obj.getSign()), to_execute(obj.getExecute())
{
    std::cout << "Form copy constructor called" << std::endl;
    this->signature = obj.signature;
}

Form &Form::operator=(Form &obj)
{
    this->signature = obj.signature;
    return(*this);
}

void Form::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() > to_sign)
        throw GradeTooLowException();
    if (getSignature() == true)
        throw FormIsAlreadySigned();
    signature = true;
}

std::string Form::getName()
{
    return name;
}

int         Form::getSign()
{
    return to_sign;
}

int         Form::getExecute()
{
    return to_execute;
}

bool        Form::getSignature()
{
    return signature;
}

std::ostream &operator<<(std::ostream &out, Form &obj)
{
    out << "Form \"" << obj.getName() << "\" ";
    if (obj.getSignature())
        out << "is signed\n";
    else
        out << "is not signed";
    return out;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}