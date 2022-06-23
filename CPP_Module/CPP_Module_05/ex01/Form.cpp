#include "Form.hpp"

Form::Form(void) : _grade_sign(0), _grade_exec() {}

Form::~Form(void) {}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Form grade too high!!";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Form grade too low!!";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << std::endl
	<< "Sign grade : " << f.getGradeSign() << std::endl
	<< "Execute grade : " << f.getGradeExec() << std::endl
	<<  "Signed : " << std::boolalpha << f.getSigned();
	return os;
}