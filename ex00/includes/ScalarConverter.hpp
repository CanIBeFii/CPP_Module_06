#ifndef STATUCCONVERTER_HPP
# define STATUCCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

enum e_literal {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
};

class ScalarConverter {
	public:
		// Methods
		static void			convert( std::string& str );

		static e_literal 	setLiteral( std::string& str );
		static bool		 	isChar( std::string& str );
		static bool		 	isInt( std::string& str );
		static bool 		isFloat( std::string& str );
		static bool 		isDouble( std::string& str );

		static void			printChar( char c );
		static void			printInt( int i );
		static void			printFloat( float f );
		static void			printDouble( double d );

		static void			print( char c );
		static void			print( int i );
		static void			print( float f );
		static void			print( double d );
	
	private:
		// Constructors
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& copy );

		// Destructor
		~ScalarConverter( void );

		// Operators
		ScalarConverter&	operator=( const ScalarConverter& copy );
};

// Colors
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */

#endif