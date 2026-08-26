#include "ScalarConverter.hpp"
#include "Detection.hpp"
#include "Converters.hpp"

//NB : Forme Orthodoxe Canonique obligatoire, cf sujet
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



void ScalarConverter::convert(const std::string& input)
{
	double	value;

	if (isOnlyOneChar(input))
	{
		value = static_cast<double>(input[0]); //on récup le code ASCII du char (ex: c = 99) puis on le loge ds un double
		printAllFours(value);
		return;
	}

	if (isSpecialWord(input))
	{
		value = std::atof(input.c_str());
		printAllFours(value);
		return;
	}

	if (!isSimilarToANumber(input))
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}

	value = std::atof(input.c_str());
	printAllFours(value);
}