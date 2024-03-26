#include "Form.hpp"

Form::~Form()
{
}

Form::Form()
{
	const_cast<std::string&>(name) = "Form";
	status = false;
	const_cast<int&>(gradeSign) = 150;
	const_cast<int&>(gradeExec) = 150;
}
