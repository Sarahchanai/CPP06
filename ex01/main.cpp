#include "Serializer.hpp"

#include <iostream>
#include <cassert>

int	main()
{
	std::cout << "étape 1 : le client fait un achat\n" << std::endl; //NB : le colis existe déjà en memR

	Data	original; //NB : colis
	original.name = "livre"; //NB : contenu du colis
	original.id = 42;  //NB : numéro de suivi du colis

	std::cout << "Contenu du colis : " << original.name << "\nNum de suivi du colis : " << original.id << std::endl;
	std::cout << "étape 2 : adresse postale du client (=pointeur)\n" << std::endl;
	std::cout << "Adresse postale d'origine : \n" << &original << std::endl;

	std::cout << "étape 3 : le centre de tri tradut l'adresse en chiffres bruts\n" << std::endl;
	uintptr_t brut = Serializer::serialize(&original);
    std::cout << "Chiffres bruts transmis   : " << brut << std::endl;

	std::cout << "étape 4 : le livreur reçoit les chiffres et reconstitue/retraduit l'adresse postale\n" << std::endl;
	Data* retrouve = Serializer::deserialize(brut);
    std::cout << "Adresse postale reconstituée : " << retrouve << std::endl;

	std::cout << "étape 5 : Vérif si le livreur est bien arrivé à la bonne adresse du client\n" << std::endl;
	if (retrouve == &original)
		std::cout << "Même adresse : le livreur est bien chez le bon client" << std::endl;
	assert(retrouve == &original);

	std::cout << "étape 6 : remise en main propre livreur/client" << std::endl;
	//NB : cf sujet "Then, ensure the return value of deserialize() compares equal to the original pointer."
	std::cout << "Nom lu chez le client			: " << retrouve->name << std::endl;
    std::cout << "Identifiant lu chez le client	: " << retrouve->id << std::endl;

	return (0);

}