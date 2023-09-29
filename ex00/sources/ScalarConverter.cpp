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
void	ScalarConverter::convert( std::string& str ) {
	e_literal literal = setLiteral( str );

	char c;
	int i;
	float f;
	double d;

	switch ( literal ) {
		case CHAR:
			c = str[0];
			print( c );
			break;
		
		case INT:
			i = strtol( str.c_str(), NULL, 10 );
			print( i );
			break;

		case FLOAT:
			f = strtof( str.c_str(), NULL );
			print( f );
			break;

		case DOUBLE:
			d = strtod( str.c_str(), NULL );
			print( d );
			break;
		
		case NONE:
			std::cout << "That's not a literal you silly cutie pattotie :3" << std::endl;
			break;
	}
}

e_literal	ScalarConverter::setLiteral( std::string& str ) {
	if ( isChar( str ) ) {
		return ( CHAR );
	} else if ( isInt( str ) ) {
		return ( INT );
	} else if ( isFloat( str ) ) {
		return ( FLOAT );
	} else if ( isDouble( str ) ) {
		return ( DOUBLE );
	} else {
		return ( NONE );
	}
}

bool	ScalarConverter::isChar( std::string& str ) {
	if ( str.length() != 1 ) {
		return ( false );
	}
	char c = str[0];

	return ( isdigit( c ) == 0 && isprint( c ) );
}

bool	ScalarConverter::isInt( std::string& str ) {
	if ( str == "0" ) {
		return ( true );
	}

	char*	endptr;
	long	num = strtol( str.c_str(), &endptr, 10 );

	return ( num != 0 && *endptr == '\0' && num >= INT_MIN && num <= INT_MAX );
}

bool	ScalarConverter::isFloat( std::string& str ) {
	if ( str == "0.0f" ) {
		return ( true );
	}

	size_t pos = str.length() - 1;
	std::string newStr = str.substr( 0, pos );

	char*	endptr;
	float	num = strtof( newStr.c_str(), &endptr );

	return ( str.at(pos) == 'f'&& str.find('.') != std::string::npos
			 && endptr != newStr.c_str() && *endptr == '\0' && num );
}

bool	ScalarConverter::isDouble( std::string& str ) {
	if ( str == "0.0" ) {
		return ( true );
	}

	char*	endptr;
	double	num = strtod( str.c_str(), &endptr );

	return ( str.find('.') != std::string::npos && 
			endptr != str.c_str() && *endptr == '\0' && num );
}

void	ScalarConverter::printChar( char c ) {
	if ( std::isprint( c ) ) {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void	ScalarConverter::printInt( int i ) {
	std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::printFloat( float f ) {
	std::cout << "float: " << std::fixed << std::setprecision( 1 );
	std::cout <<  f << "f" << std::endl;
}

void	ScalarConverter::printDouble( double d ) {
	std::cout << "double: " << std::fixed << std::setprecision( 1 );
	std::cout << d << std::endl;
}

void 	ScalarConverter::print( char c ) {
	printChar( c );
	printInt( static_cast<int>( c ) );
	printFloat( static_cast<float>( c ) );
	printDouble( static_cast<double>( c ) );
}

void 	ScalarConverter::print( int i ) {
	if ( i <= std::numeric_limits<char>::min() || i >= std::numeric_limits<char>::max() ) {
		std::cout << "char: impossible" << std::endl;
	} else {
		printChar( static_cast<char>( i ) );
	}

	printInt( i );
	printFloat( static_cast<float>( i ) );
	printDouble( static_cast<double>( i ) );
}

void	ScalarConverter::print( float f ) {
	if ( f <= std::numeric_limits<char>::min() || f >= std::numeric_limits<char>::max() || f != f ) {
		std::cout << "char: impossible" << std::endl;
	} else {
		printChar( static_cast<char>( f ) );
	}

	if ( f <= std::numeric_limits<int>::min() || f >= std::numeric_limits<int>::max()|| f != f ) {
		std::cout << "int: impossible" << std::endl;
	} else {
		printInt( static_cast<int>( f ) );
	}

	printFloat( f );
	printDouble( static_cast<double>( f ) );
}

void	ScalarConverter::print( double d ) {
	if ( d <= std::numeric_limits<char>::min() || d >= std::numeric_limits<char>::max() || d != d ) {
		std::cout << "char: impossible" << std::endl;
	} else {
		printChar( static_cast<char>( d ) );
	}

	if ( d <= std::numeric_limits<int>::min() || d >= std::numeric_limits<int>::max() || d != d ) {
		std::cout << "int: impossible" << std::endl;
	} else {
		printInt( static_cast<int>( d ) );
	}

	if ( (d <= std::numeric_limits<float>::min() || d >= std::numeric_limits<float>::max()) && d != 0.0 ) {
		std::cout << "float: impossible" << std::endl;
	} else {
		printFloat( static_cast<float>( d ) );
	}

	printDouble( d );
}