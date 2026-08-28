#include "Generate.hpp"
#include "Identify.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // On pioche une carte au hasard, face cachee (Base*).
    Base* carteMystere = generate();

    // On la retourne en la POINTANT (a distance).
    std::cout << "Via pointeur  : ";
    identify(carteMystere);

    // On la retourne en la TENANT en main (*carteMystere transforme
    // le pointeur en reference -- on "prend la carte en main").
    std::cout << "Via reference : ";
    identify(*carteMystere);

    delete carteMystere;
    return (0);
}