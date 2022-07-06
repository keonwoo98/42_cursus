#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form() {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) : Form(s) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
	return *dynamic_cast<ShrubberyCreationForm *>(&(Form::operator=(s)));
	// Form::operator=(s);
	// return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	std::ofstream out;
	std::string ascii_trees = "               ,@@@@@@@,\n"
							  "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
							  "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
							  "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
							  "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
							  "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
							  "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
							  "       |o|        | |         | |\n"
							  "       |.|        | |         | |\n"
							  "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";

	if (!getSigned())
		throw NotSignedException();
	if (b.getGrade() > getGradeExec())
		throw GradeTooLowException();
	out.open(getName() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	if (!out)
		throw FileErrorException();
	out << ascii_trees;
	out.close();
}
