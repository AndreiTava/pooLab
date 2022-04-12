#include "GameExceptions.h"

const char* InputException::what() const noexcept
{
	return "(E)\nInvalid command, try again\n";
}
const char* TargetException::what() const noexcept
{
	return "(E)\nSelected enemy is invalid\n";
}
const char* MechanicException::what() const noexcept
{
	return "(E)\nInsufficient resources to do action\n";
}
const char* EnemyException::what() const noexcept
{
	return "(E)\nInvalid Enemy Type... This should appear..ever\n";
}


