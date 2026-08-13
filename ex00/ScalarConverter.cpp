#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& original)
{
	(void)original;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& original)
{
	(void)original;
	return (*this);
}

static bool	isChar(const std::string& input)
{
	if (input.length() != 1)
		return (false);

	if (!std::isdigit(input[0]) && std::isprint(input[0]))
		return (true);

	return (false);
}

static bool isPseudoLiteral(const std::string& input)
{
	return ( input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff");
}
static void printChar(double value)
{
	std::cout << "char: ";

	// NB : nan et inf ne peuvent ps etre convertis en char
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	// Verif que la valeur rentre ds 1 char
	if (value < CHAR_MIN || value > CHAR_MAX)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	char c = static_cast<char>(value);

	// NB : un char existe b1, ms peut ne ps etre affichable !
	if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}
static void printInt(double value)
{
	std::cout << "int: ";

	// NB : nan et inf ne peuvent ps devenir des int
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	if (value < INT_MIN || value > INT_MAX) // Verif protec°
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	std::cout << static_cast<int>(value) << std::endl;
}
static bool isNumber(const std::string& input)
{
	size_t	i;
	bool	point;
	bool	digit;

	i = 0;
	point = false;
	digit = false;

	if (input[i] == '+' || input[i] == '-')
		i++;

	while (i < input.length())
	{
		if (std::isdigit(input[i]))
			digit = true;
		else if (input[i] == '.' && !point)
			point = true;
		else
			return (false);
		i++;
	}

	return (digit);
}

static void printFloat(double value)
{
	float	f;

	std::cout << "float : ";

	if (std::isnan(value))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}

	if (std::isinf(value))
	{
		if (value < 0)
			std::cout << "-inff" << std::endl;
		else
			std::cout << "+inff" << std::endl;
		return ;
	}

	if (value < -FLT_MAX || value > FLT_MAX)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	f = static_cast<float>(value);

	if (f == static_cast<int>(f))
		std::cout << f << ".0f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

static void printDouble(double value)
{
	std::cout << "double : ";

	if (std::isnan(value))
	{
		std::cout << "nan" << std::endl;
		return ;
	}

	if (std::isinf(value))
	{
		if (value < 0)
			std::cout << "-inf" << std::endl;
		else
			std::cout << "+inf" << std::endl;
		return ;
	}

	if (value == static_cast<int>(value))
		std::cout << value << ".0" << std::endl;
	else
		std::cout << value << std::endl;
}

static void printAllFours(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

void ScalarConverter::convert(const std::string& input)
{
	double	value;

	if (isChar(input))
	{
		value = static_cast<double>(input[0]);
		printAllFours(value);
		return ;
	}

	if (isPseudoLiteral(input))
	{
		value = std::atof(input.c_str());
		printAllFours(value);
		return ;
	}

	if (!isNumber(input))
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}

	value = std::atof(input.c_str());
	printAllFours(value);
}