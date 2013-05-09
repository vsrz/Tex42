
#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

class RandomNumberGenerator
{
private:
	unsigned long seed;

public:
	RandomNumberGenerator( void );
	int nextNumber( int maxint );

};

#endif
