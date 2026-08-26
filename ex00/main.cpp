#include "ScalarConverter.hpp"
#include "Converters.hpp"
#include "Detection.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage : ./convert <literal> " << std::endl;
		return (1);
	}

	ScalarConverter::convert(av[1]);
	return (0);
}


// static void runTest(int n, const char* input)
// {
// 	std::cout << "Test " << n << " : \"" << input << "\"" << std::endl;
// 	ScalarConverter::convert(input);
// 	std::cout << std::endl;
// }

// int main(void)
// {
// 	runTest(1, "citron");
// 	runTest(2, "mb");
// 	runTest(3, "21");
// 	runTest(4, "2,7");
// 	runTest(5, "nan");
// 	runTest(6, "inf");
// 	runTest(7, "0");
// 	runTest(8, "-21");
// 	runTest(9, "42.0f");
// 	runTest(10, "'");
// 	runTest(11, "+inf");
// 	runTest(12, "3.14.15");
// 	runTest(13, "2147483648");
// 	runTest(14, "-2147483648");
// 	runTest(15, "-2147483649");
// 	runTest(16, "127");
// 	runTest(17, "128");
// 	runTest(18, "-128");
// 	runTest(19, "-129");
// 	runTest(20, "400000000000000000000000000000000000000");
// 	runTest(21, "0.1234567891234");
// 	runTest(22, "-nan");
// 	return (0);
// }