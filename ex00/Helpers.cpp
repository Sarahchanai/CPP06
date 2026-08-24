#include "Helpers.hpp"

bool	isChar(const std::string& input)
{
	if (input.length() != 1)
		return (false);

	if (!std::isdigit(input[0]) && std::isprint(input[0]))
		return (true);

	return (false);
}


bool	isPseudoLiteral(const std::string& input)
{
	return ( input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff");
}

bool	isNumber(const std::string& input)
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


void	printAllFours(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}