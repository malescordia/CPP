/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:36:06 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/18 18:32:25 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define R "\033[0m"

class AForm
{
     private:
    	std::string	        name;
    	bool                signature;
        int                 to_sign;
        int                 to_execute;
    
    public:
    	AForm();
    	AForm(std::string name);
        AForm(std::string name, int sign, int execute);
    	AForm(AForm &obj);
    	AForm &operator=(AForm &obj);
    	~AForm();
    
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
        class FormIsNotSigned: public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return (RED "the form is not signed!" R);
                }
        };
};

std::ostream &operator<<(std::ostream &out, AForm &obj);

#endif