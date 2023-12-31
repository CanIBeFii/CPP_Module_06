#include "../includes/ScalarConverter.hpp"

int main( int argc, char** argv ) {
	if ( argc != 2 ) {
		std::cout << "Usage: ./convert [string]" << std::endl;
		return ( 1 );
	}
	std::string str( argv[1] );
	ScalarConverter::convert( str );
	return ( 0 );
}