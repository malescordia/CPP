/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:19:11 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/15 15:06:44 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Bureaucrat
{

    private:
    	std::string	        name;
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
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj);