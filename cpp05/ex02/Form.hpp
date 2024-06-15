/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:36:06 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/15 20:24:21 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

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
        
    	void            beSigned(Bureaucrat &obj);
        virtual void    execute(Bureaucrat &obj) = 0;
        
    	class GradeTooHighException: public std::exception
        {
    		public:
    			const char * what() const throw()
                {
                    return ("The grade is too high!");
                }
    	};
    	class GradeTooLowException: public std::exception
        {
    		public:
    			const char * what() const throw()
                {
                    return ("The grade is too low!");
                }
    	};
        class FormIsAlreadySigned: public std::exception
        {
    		public:
    			const char * what() const throw()
                {
                    return ("The form is already signed!");
                }
    	};
        class FormIsNotSigned: public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return ("The form is not signed!");
                }
        };
};

std::ostream &operator<<(std::ostream &out, Form &obj);

#endif