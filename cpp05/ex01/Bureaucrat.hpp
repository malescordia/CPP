/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:36:11 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/19 18:52:42 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREACRAT_HPP
#define BUREACRAT_HPP

#include <iostream>
#include "Form.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define R "\033[0m"

class Form;

class Bureaucrat
{

    private:
    	std::string  		name;
    	int					grade;
    
    public:
    	Bureaucrat();
    	Bureaucrat(std::string name, int grade);
    	Bureaucrat(Bureaucrat &obj);
    	Bureaucrat &operator=(Bureaucrat &obj);
    	~Bureaucrat();
    
    	std::string	        getName();
    	int					getGrade();
    	void				incrementGrade(int value);
    	void				decrementGrade(int value);
        
        bool                signForm(Form &form);
        
    	class GradeTooHighException: public std::exception
        {
    		public:
    			const char * what() const throw()
                {
                    return (RED "the grade is too high!" R);
                }
    	};
    	class GradeTooLowException: public std::exception
        {
    		public:
    			const char * what() const throw()
                {
                    return (RED "the grade is too low!" R);
                }
    	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj);

#endif