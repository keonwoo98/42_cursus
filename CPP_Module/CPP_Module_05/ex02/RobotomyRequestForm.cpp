#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form() {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r) : Form(r) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& r)
{
	return *dynamic_cast<RobotomyRequestForm *>(&(Form::operator=(r)));
}

void RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	if (!getSigned())
		throw NotSignedException();
	if (b.getGrade() > getGradeExec())
		throw GradeTooLowException();
	srand(time(NULL));
	std::cout << "Drrrrrrrrrrrr..." << std::endl;
	if (rand() % 2)
		std::cout << getName() << " has been robotomized successfully 50% of the time." << std::endl;
	else
		std::cout << getName() << " has been failed robotomize." << std::endl;
}
