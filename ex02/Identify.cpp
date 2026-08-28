#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

/*
** VERSION POINTEUR : on POINTE vers la carte a distance. Pointer
** "dans le vide" a un sens (NULL existe pour un pointeur), donc
** dynamic_cast peut repondre "non, ce n'est pas cette famille" en
** renvoyant NULL, sans aucun probleme.
*/
void identify(Base* carte)
{
    if (dynamic_cast<A*>(carte) != NULL)          // "est-ce un coeur ?"
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(carte) != NULL)     // sinon, "est-ce un pique ?"
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(carte) != NULL)     // sinon, "est-ce un trefle ?"
        std::cout << "C" << std::endl;
}

/*
** VERSION REFERENCE : on TIENT la carte en main. Tenir "rien" en
** main n'a pas de sens (une reference ne peut jamais etre vide),
** donc dynamic_cast ne peut pas repondre NULL ici. A la place, s'il
** se trompe de famille, il declenche une exception (std::bad_cast)
** -- l'alerte qu'on attrape avec try/catch pour passer a la
** famille suivante sans planter.
*/
void identify(Base& carte)
{
    try
    {
        (void)dynamic_cast<A&>(carte);            // "est-ce un coeur ?"
        std::cout << "A" << std::endl;
        return ;
    }
    catch (std::bad_cast&) {}                     // non -> on tente la suite

    try
    {
        (void)dynamic_cast<B&>(carte);            // "est-ce un pique ?"
        std::cout << "B" << std::endl;
        return ;
    }
    catch (std::bad_cast&) {}

    try
    {
        (void)dynamic_cast<C&>(carte);            // "est-ce un trefle ?"
        std::cout << "C" << std::endl;
        return ;
    }
    catch (std::bad_cast&) {}
}