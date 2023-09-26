#ifndef STATUCCONVERTER_HPP
# define STATUCCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	public:
		// Constructors
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& copy );

		// Destructor
		~ScalarConverter( void );

		// Operators
		ScalarConverter&	operator=( const ScalarConverter& copy );

		// Methods
		static void		converter( std::string& str );

		static void		convertChar( char c );
		static void		convertInt( int i );
		static void		convertFloat( float f );
		static void		convertDouble( double d );


	private:
};

// Colors
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */

#endif