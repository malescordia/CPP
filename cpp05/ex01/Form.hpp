/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:36:06 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/19 18:52:12 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define R "\033[0m"

class Bureaucrat;

class Form
{
     private:
    	std::string	        name;
    	bool                signature;
        int                 to_sign;
        int                 to_execute;
    
    public:
    	Form();
    	Form(std::string name);
        Form(std::string name, int sign, int execute);
    	Form(Form &obj);
    	Form &operator=(Form &obj);
    	~Form();
    
        std::string getName();
        bool        getSignature();
        int         getSign();
        int         getExecute();
        
    	void        beSigned(Bureaucrat &obj);
        
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
        class FormIsAlreadySigned: public std::exception
        {
    		public:
    			const char * what() const throw()
                {
                    return (RED "the form is already signed!" R);
                }
    	};
};

std::ostream &operator<<(std::ostream &out, Form &obj);

#endif