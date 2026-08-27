#include "Serializer.hpp"


// qd le client fait l'achat, il va mettre son adresse postale sauf que les machines du centre de tri ne commprenne ps l'adresse ss sa forme postale, donc ils vont la tradure sous forme de suite numérique : le seul format qu'elle sait faire circuler pour pouvoir l'assigner à un livreur

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// mtn que la machine a bien compris ou envoyer le livreur il faut que lui aussi puisse lire l'adresse sous forme postale parce qu'il ne comorend pas la suite de chiffre
//-> retraduction
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}