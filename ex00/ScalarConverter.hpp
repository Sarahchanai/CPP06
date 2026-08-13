#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class	ScalarConverter
{
	public :

				static void convert(const std::string& input);


	private :

				ScalarConverter();
				~ScalarConverter();
				ScalarConverter(const ScalarConverter& original);
				ScalarConverter& operator=(const ScalarConverter& original);


};

#endif