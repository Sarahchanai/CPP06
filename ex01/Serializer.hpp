#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

#include <cstdint>


// = le centre de tri (ni livreur, ni client) juste le service qui sait faire 2 choses précises :
// -> traduire 1 adresse postale en chiffres et l'inverse)
class	Serializer
{
	public :

				static uintptr_t	serialize(Data* ptr);
       			 static Data*		deserialize(uintptr_t raw);

	private :

				Serializer();
				 ~Serializer();
				Serializer(const Serializer& original);
				Serializer& operator=(const Serializer& original);
};




#endif