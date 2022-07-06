#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private :
	const std::string _name;
	bool _signed;
	const int _grade_sign;
	const int _grade_exec;

public :
	Form(void);
	Form(const std::string& name, const int& grade_sign, const int& grade_exec);
	Form(const Form& f);
	~Form(void);
	Form& operator=(const Form& f);

	const std::string getName(void) const;
	const bool getSigned(void) const;
	const int getGradeSign(void) const;
	const int getGradeExec(void) const;

	void beSigned(Bureaucrat b);

	virtual void execute(const Bureaucrat& b) const = 0;
	
	class GradeTooHighException : public std::exception
	{
	public :
		const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public :
		const char* what(void) const throw();
	};

	class NotSignedException : public std::exception
	{
	public :
		const char* what(void) const throw();
	};

	class FileErrorException : public std::exception
	{
	public :
		const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
