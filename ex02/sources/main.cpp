#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate( void ) {
	static int	i = 0;
	Base*		base;

	switch( i % 3 ) {
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

	i++;
	return ( base );
}

void	identify( Base* p ) {
	if ( dynamic_cast<A*>( p ) != NULL ) {
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
	if ( dynamic_cast<A*>( &p ) != NULL ) {
		std::cout << "A" << std::endl;
	}
	else if ( dynamic_cast<B*>( &p ) != NULL ) {
		std::cout << "B" << std::endl; 
	}
	else if ( dynamic_cast<C*>( &p ) != NULL ) {
		std::cout << "C" << std::endl;
	}
}


int	main( void ) {
	Base*	ptr;

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

	return ( 0 );
}
