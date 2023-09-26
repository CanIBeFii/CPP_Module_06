#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter( void ) {
	std::cout << BOLDCYAN << "ScalarConverter: " << RESET;
	std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& copy ) {
	std::cout << BOLDCYAN << "ScalarConverter: " << RESET;
	std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
	
	*this = copy;
}

// Destructors
ScalarConverter::~ScalarConverter( void ) {
	std::cout << BOLDCYAN << "ScalarConverter: " << RESET;
	std::cout << BOLDRED << "Destructor " << RESET;
	std::cout << "called" << std::endl;
}

// Operators
ScalarConverter&	ScalarConverter::operator=( const ScalarConverter& copy ) {
	std::cout << BOLDCYAN << "ScalarConverter: " << RESET;
	std::cout << BOLDYELLOW << "Assignation " << RESET;
	std::cout << "operator called" << std::endl;
	
	if ( this != &copy ) {
		(void)copy;
	}
	return *this;
}

// Methods
void	ScalarConverter::converter( std::string& str ) {

}

void	ScalarConverter::convertChar( char c ) {
	std::cout << "char: ";
}