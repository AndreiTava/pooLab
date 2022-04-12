#include "GameExceptions.h"

const char* InputException::what() const noexcept
{
	return "Invalid User Input";
}
const char* TargetException::what() const noexcept
{
	return "Invalid Target";
}
const char* MechanicException::what() const noexcept
{
	return "Action Impossible";
}
const char* EnemyException::what() const noexcept
{
	return "Nonexistent enemy type";
}


