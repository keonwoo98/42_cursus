#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private :
	ShrubberyCreationForm(void);

public :
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& s);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s);

	void execute(const Bureaucrat& b) const;
};

#endif
