#include "Form.hpp"

Form::Form(void) : _grade_sign(0), _grade_exec(0) {}

Form::~Form(void) {}

Form::Form(const std::string& name, const int& grade_sign, const int& grade_exec)
	: _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec), _signed(false)
{
	if (_grade_sign < GRADE_MAX || _grade_exec < GRADE_MAX)
		throw GradeTooHighException();
	if (_grade_sign > GRADE_MIN || _grade_exec > GRADE_MIN)
		throw GradeTooLowException();
}

Form::Form(const Form& f)
	: _name(f.getName()), _grade_sign(f.getGradeSign()), _grade_exec(f.getGradeExec()), _signed(false)
{
	if (_grade_sign < GRADE_MAX || _grade_exec < GRADE_MAX)
		throw GradeTooHighException();
	if (_grade_sign > GRADE_MIN || _grade_exec > GRADE_MIN)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& f)
{
	if (this != &f)
	{
		*const_cast<std::string*>(&_name) = f.getName();
		*const_cast<int*>(&_grade_exec) = f.getGradeExec();
		*const_cast<int*>(&_grade_sign) = f.getGradeSign();
		_signed = f.getSigned();
	}
	return *this;
}

void Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() > _grade_sign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const std::string Form::getName(void) const
{
	return _name;
}

const bool Form::getSigned(void) const
{
	return _signed;
}

const int Form::getGradeSign(void) const
{
	return _grade_sign;
}

const int Form::getGradeExec(void) const
{
	return _grade_exec;
}

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
