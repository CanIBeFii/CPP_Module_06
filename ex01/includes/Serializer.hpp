#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
	char c;
	int i;
	float f;
	double d;
};

class Serializer {
	public:
		// Methods
		static uintptr_t	serialize( Data* ptr );
		static Data*		deserialize( uintptr_t raw );

	private:
		// Constructors
		Serializer( void );
		Serializer( const Serializer& copy );

		// Destructor
		~Serializer( void );

		// Operators
		Serializer&	operator=( const Serializer& copy );
};

// Colors
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */

#endif