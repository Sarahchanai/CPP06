#include "Generate.hpp"
#include "Identify.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// On pioche une carte au hasard, face cachee (Base*)
	// NB : cree reellement un obj (A, B ou C) quelque part em memr mais rend le result en type generique : Base*
	Base*	carteMystere = generate();
	std::cout << "Adresse de la carte piochee : " << carteMystere << std::endl;

	
	std::cout << "ID du type via pointeur  : ";
	identify(carteMystere); //va test 1par1 si l'obj reel a cette adresse memr correspond a celle d'un A, B ou C



	std::cout << "ID du type via reference : ";
	identify(*carteMystere); //NB : obj reel 

	delete carteMystere; //leak
	return (0);
}