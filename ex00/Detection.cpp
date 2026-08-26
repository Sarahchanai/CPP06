#include "Detection.hpp"
#include "string"


bool	isOnlyOneChar(const std::string& input)
{
	unsigned char letter;
	if (input.length() != 1)
		return (false);

	letter = static_cast<unsigned char>(input[0]);
	if (!std::isdigit(letter) && std::isprint(letter))
		return (true);

	return (false);
}


bool	isSpecialWord(const std::string& input)
{
	return ( input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff");
}

bool	isSimilarToANumber(const std::string& input)
{
	size_t	i;
	bool	pointDejaVu;
	bool	chiffreTrouve;

	i = 0;
	pointDejaVu = false;
	chiffreTrouve = false;

	if (input[i] == '+' || input[i] == '-')
		i++; //signe ok ms only en 1ere pos°

	while (i < input.length())
	{
		if (std::isdigit(static_cast<unsigned char>(input[i])))
			chiffreTrouve = true;
		else if (input[i] == '.' && !pointDejaVu)
			pointDejaVu = true; //éviter 2.2.2
		else
			return (false);
		i++;
	}

	return (chiffreTrouve);
}


