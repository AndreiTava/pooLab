#include "GameExceptions.h"

const char* InputException::what() const noexcept
{
	return "Invalid User Input";
}
const char* TargetException::what() const noexcept
{
	return "Invalid Target";
}

