#include "Converters.hpp"

void printChar(double value)
{
	std::cout << "char: ";

	// NB : nan et inf ne peuvent ps etre convertis en char
	if (std::isnan(value) || std::isinf(value)) // 1e question
	{
		std::cout << "impossible" << std::endl;
		return ;
	}


	if (value < CHAR_MIN || value > CHAR_MAX) // 2e question (verif limite char)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	char c = static_cast<char>(value); // 3e question

	// NB : un char existe b1, ms peut ne ps etre affichable !
	if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "Non displayable" << std::endl; //le char existe b1 ms cert1 char (0 à 31 & +127) ne se print ps
	else
		std::cout << "'" << c << "'" << std::endl;
}
void printInt(double value)
{
	std::cout << "int: ";

	// NB : nan et inf ne peuvent ps devenir des int
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}

	if (value < INT_MIN || value > INT_MAX) // Verif protec°
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	std::cout << static_cast<int>(value) << std::endl;
}


void printFloat(double value)
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

	// if (f == std::floor(f))
	// 	std::cout << f << ".0f" << std::endl;
	// else
	// 	std::cout << f << "f" << std::endl;

	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void printDouble(double value) // b1 que value déjà double -> règles de formatage propres au double obligé
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

	// if (value == std::floor(value))
	// 	std::cout << value << ".0" << std::endl;
	// else
	// 	std::cout << value << std::endl;

	std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void printAllFours(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

