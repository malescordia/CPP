
#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        Bureaucrat() throw(Bureaucrat::GradeTooHighException);

        const std::string   name;
        unsigned int        grade;
    
    public:
        class GradeTooHighException : public std::exception
        {
            private:
                std::string message;
            public:
                GradeTooHighException(const std::string &message = "")  throw();
                ~GradeTooHighException()                                throw();
                const char *what() const                                throw();
        };

        class GradeTooLowException : public std::exception
        {
            private:
                std::string message;
            public:
                GradeTooLowException(const std::string &message = "")   throw();
                ~GradeTooLowException()                                 throw();
                const char *what() const                                throw();
        };

        Bureaucrat(const std::string &name, unsigned int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &obj);
        
        Bureuacrat &operator++()    throw(Bureaucrat::GradeTooHighException);
        Bureaucrat operator++(int)  throw(Bureaucrat::GradeTooHighException);
        Bureaucrat &operator--()    throw(Bureaucrat::GradeTooLowException);
        Bureaucrat operator--(int)  throw(Bureaucrat::GradeTooLowException);

        const std::string   &getName() const;
        unsigned int        getGrade() const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);