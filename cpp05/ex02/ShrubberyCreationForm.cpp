/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:06:48 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/15 21:02:39 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 37), target(target)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &obj) : Form(obj)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    target = obj.target;
}

void ShrubberyCreationForm::execute(Bureaucrat &obj)
{
    if (!getSignature())
    {
        throw FormIsNotSigned();
    }
    if (getExecute() > obj.getGrade())
    {
        throw GradeTooLowException();
    }
    
    std::ofstream out(target + "_shrubbery");
    
    if (out.is_open())
    {
        out << "       _-_" << std::endl;
        out << "    /~~   ~~\\" << std::endl;
        out << " /~~         ~~\\" << std::endl;
        out << "{               }" << std::endl;
        out << " \\  _-     -_  /" << std::endl;
        out << "   ~  \\\\ //  ~" << std::endl;
        out << "_- -   | | _- _" << std::endl;
        out << "  _ -  | |   -_" << std::endl;
        out << "      // \\\\" << std::endl;
    }
    out.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}