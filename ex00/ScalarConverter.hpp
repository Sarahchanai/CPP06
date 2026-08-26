#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include <string>

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