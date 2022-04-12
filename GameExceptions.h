#pragma once
#include <exception>

class InputException : public std::exception
{
public:
	const char* what() const noexcept override;
};
class TargetException : public std::exception
{
public:
	const char* what() const noexcept override;
};
class MechanicException : public std::exception
{
public:
	const char* what() const noexcept override;
};
class EnemyException : public std::exception
{
public:
	const char* what() const noexcept override;
};