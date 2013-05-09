
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator( void )
{
	seed = (unsigned long) time( NULL );
	srand( (unsigned int) seed );
}

/**
 *  Gets a random number between 0 and maxint 
 */
int RandomNumberGenerator::nextNumber( int maxint )
{
    if( maxint == -1 ) return 0;
	return (rand() % (maxint+1));

}
