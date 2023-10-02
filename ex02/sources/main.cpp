#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base*	generate( void ) {
	Base*		base;

	switch( rand() % 3 ) {
		case 0:
			base = new A();
			break;
		case 1:
			base = new B();
			break;
		case 2:
			base = new C();
			break;
	}

	return ( base );
}

void	identify( Base* p ) {
	if ( p == NULL ) {
		std::cout << "Given pointer is NULL, you silly goofy" << std::endl;
	}
	else if ( dynamic_cast<A*>( p ) != NULL ) {
		std::cout << "A" << std::endl;
	}
	else if ( dynamic_cast<B*>( p ) != NULL ) {
		std::cout << "B" << std::endl; 
	}
	else if ( dynamic_cast<C*>( p ) != NULL ) {
		std::cout << "C" << std::endl;
	}
}

void	identify( Base& p ) {
	try {
		A& a = dynamic_cast<A&>( p );
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	} catch ( std::exception e ) {}

	try {
		B& b = dynamic_cast<B&>( p );
		(void)b;
		std::cout << "B" << std::endl;
		return ; 
	} catch ( std::exception e ) {}

	try {
		C& c = dynamic_cast<C&>( p );
		(void)c;
		std::cout << "C" << std::endl;
		return ; 
	} catch ( std::exception e ) {}

	std::cout << "It's not A, B or C!" << std::endl;
}


int	main( void ) {
	Base*	ptr;
	srand( time( NULL ) );

	ptr = generate();
	identify( ptr );
	delete ptr;

	ptr = generate();
	identify( ptr );
	delete ptr;

	ptr = generate();
	identify( ptr );
	delete ptr;

	ptr = generate();
	identify( ptr );
	delete ptr;

	identify( NULL );

	A	a;
	B	b;
	C	c;

	identify( a );
	identify( c );
	identify( b );

	return ( 0 );
}
