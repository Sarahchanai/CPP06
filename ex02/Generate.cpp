
#include "Generate.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

/*
** On fabrique VRAIMENT un coeur, un pique ou un trefle (new A(),
** new B() ou new C()) -- la vraie famille existe bel et bien en
** memoire. Mais la fonction la renvoie typee "Base*" : c'est
** exactement tendre la carte face cachee. Celui qui recoit le
** resultat ne connait plus la vraie famille tant qu'il n'a pas
** appele identify().
*/
Base* generate(void)
{
    int familleTiree = std::rand() % 3;

    if (familleTiree == 0)
        return (new A());
    if (familleTiree == 1)
        return (new B());
    return (new C());
}