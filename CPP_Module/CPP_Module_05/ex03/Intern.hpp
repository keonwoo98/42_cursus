#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public :
    Intern(void);
    Intern(const Intern& i);
    ~Intern(void);
    Intern& operator=(const Intern& i);

    Form* CreateShrubberyCreationForm(const std::string& target);
    Form* CreateRobotomyForm(const std::string& target);
    Form* CreatePresidentialPardonForm(const std::string& target);

    Form* makeForm(const std::string& type, const std::string& name);
};

#endif
