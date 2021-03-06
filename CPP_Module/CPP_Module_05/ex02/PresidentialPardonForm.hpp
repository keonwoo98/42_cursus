#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private :
	PresidentialPardonForm(void);

public :
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& s);
	~PresidentialPardonForm(void);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& s);

	void execute(const Bureaucrat& b) const;
};

#endif
