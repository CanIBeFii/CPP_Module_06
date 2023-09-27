#include "Serializer.hpp"

int main( void ) {
	Data data = { 'f', 42, 42.42f, 42.56 };

	std::cout << "Data: " << std::endl;
	std::cout << "char: " << data.c << std::endl;
	std::cout << "int: " << data.i << std::endl;
	std::cout << "float: " << data.f << std::endl;
	std::cout << "double: " << data.d << std::endl;

	uintptr_t raw = Serializer::serialize( &data );
	Data* ptr = Serializer::deserialize( raw );

	std::cout << "Data: " << std::endl;
	std::cout << "char: " << ptr->c << std::endl;
	std::cout << "int: " << ptr->i << std::endl;
	std::cout << "float: " << ptr->f << std::endl;
	std::cout << "double: " << ptr->d << std::endl;

	return ( 0 );
}