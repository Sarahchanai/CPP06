
#include "Generate.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>



// fonction qui pioche au hasard une carte
//


Base*   generate(void)
//type de retour = Base* -> renvoie la carte retournee pour qu'elle ne puisse ps etre identifiable -> solution -> call fonction identify 
{
    int familleTiree = std::rand() % 3;

    if (familleTiree == 0)
        return (new A());
    if (familleTiree == 1)
        return (new B());
    return (new C());
}