#include "../includes/Serializer.hpp"

// Constructors
Serializer::Serializer( void ) {
	std::cout << BOLDCYAN << "Serializer: " << RESET;
	std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

Serializer::Serializer( const Serializer& copy ) {
	std::cout << BOLDCYAN << "Serializer: " << RESET;
	std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
	
	*this = copy;
}

// Destructors
Serializer::~Serializer( void ) {
	std::cout << BOLDCYAN << "Serializer: " << RESET;
	std::cout << BOLDRED << "Destructor " << RESET;
	std::cout << "called" << std::endl;
}

// Operators
Serializer&	Serializer::operator=( const Serializer& copy ) {
	std::cout << BOLDCYAN << "Serializer: " << RESET;
	std::cout << BOLDYELLOW << "Assignation " << RESET;
	std::cout << "operator called" << std::endl;
	
	if ( this != &copy ) {
		(void)copy;
	}
	return *this;
}

// Methods
uintptr_t	Serializer::serialize( Data* ptr ) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize( uintptr_t raw ) {
	return reinterpret_cast<Data*>(raw);
}