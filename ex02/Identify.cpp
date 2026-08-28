#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// NB : je viens precedemment de piocher ma carte aleatoirement -> generate()
// je tire un trefle mais y'a que la memR de l'ordi qui sait que j'ai un trefle (l'info est cachee ds l'obj)
// moi je ne suis ps en capacite de lire l'info il faut que je l'identifie
// 
void	identify(Base* carte) // cf sujet, produit soit une adresse valide qui va matcher, soit NULL -> comparaison easy
{
	// if (carte == A) -> impossible pcq carte = variable (valeur) ≠ type (un type apporte des precisions s/ la variable) -> ps le bon outil
	if (dynamic_cast<A*>(carte) != NULL) // verif -> A ? (coeur)
	// = essaye de reformuler la carte generique en une carte faisant partie de la famille des coeurs	
	// NB : si ma reformulation = NULL -> aucune adresse valide trouvee donc obj pas un A pca l'ordi sait deja et a deja stocke la valeur (cf destructeur virtuel)
		std::cout << "A" << std::endl; // cf sujet : t prints the actual type of the object pointed to by p: "A", "B", or "C"
	else if (dynamic_cast<B*>(carte) != NULL) // verif -> B ? (pique)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(carte) != NULL) // verif -> C ? (trefle)
		std::cout << "C" << std::endl;
}


void	identify(Base& carte) // cf sujet
{
	try
	{
		(void)dynamic_cast<A&>(carte); // verif -> A ? (coeur)
		std::cout << "A" << std::endl; // cf sujet
		return;
	}
	catch (std::exception&)
	{

	}

	try
	{
		(void)dynamic_cast<B&>(carte); //verif -> B? (pique)
		std::cout << "B" << std::endl;
		return;
    }
	catch (std::exception&)
	{

	}

	try
	{
		(void)dynamic_cast<C&>(carte); //verif -> C? (trefle)
		std::cout << "C" << std::endl;
		return;
    }
	catch (std::exception&)
	{

	}
}