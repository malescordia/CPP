
#include "Bureaucrat.hpp"

/* default constructor */
Bureaucrat::Bureaucrat() throw(Bureaucrat::GradeTooHighException) : name("Michael"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl << "No grade given" << std::endl;
    throw Bureaucrat::GradeTooHighException("Cannot create a Bureaucrat without a grade!");
}

/* parametric constructor */
Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) throw(Bureaucrat::GradeTooHighException, GradeTooLowException) : name(name), grade(grade)
{
    std::cout << "Bureaucrat parametric constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException("Grade must be positive!");
    else if (grade > 150)
        throw GradeTooLowException("Grade cannot be higher than 150");
}

/* copy constructor */
Bureaucrat::Bureaucrawt(const Bureaucrat &obj) : name(obj.name), grade(obj.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

/* destructor */
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

/* assignment operator */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &obj)
        grade = obj.grade;
    return *this;
}

/* PREFIX increment operator */
Bureaucrat &Bureaucrat::operator++() throw(Bureaucrat::GradeTooHighException)
{
    std::cout << "Bureaucrat PREFIX increment operator called" << std::endl;
    if (grade > 1)
        grade--;
    else
        throw GradeTooHighException("Cannot increment bureaucrats grade");
    return *this;
}

/* POSTFIX increment operator */
Bureaucrat Bureaucrat::operator++(int) throw(Bureaucrat::GradeTooHighException)
{
    std::cout << "Bureaucrat POSTFIX increment operator called" << std::endl;
    Bureaucrat tmp(*this);
    if (grade > 1)
        grade--;
    else
        throw GradeTooHighException("Cannot increment bureaucrats grade");
    return tmp;
}

/* PREFIX decrement operator */
Bureaucrat &Bureaucrat::operator--() throw(Bureaucrat::GradeTooLowException)
{
    std::cout << "Bureaucrat PREFIX decrement operator called" << std::endl;
    if (grade > 150)
        grade++;
    else
        throw GradeTooLowException("Cannot decrement bureaucrats grade");
    return *this;
}

/* POSTFIX decrement operator */
Bureaucrat Bureaucrat::operator--(int) throw(Bureaucrat::GradeTooLowException)
{
    std::cout << "Bureaucrat POSTFIX decrement operator called" << std::endl;
    Bureaucrat tmp(*this);
    if (grade > 150)
        grade++;
    else
        throw GradeTooLowException("Cannot decrement bureaucrats grade");
    return tmp;
}
 /* getters */
const std::string &Bureaucrat::getName() const
{
    return name;
}

unsigned int Bureaucrat::getGrade() const
{
    return grade;
}

/* exceptions */
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message) throw()
{
    if (message.empty())
        message = "Grade is too high!";
    else
        message = "Grade is too high: " + message;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return message.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
    /* nothing to do here */
}