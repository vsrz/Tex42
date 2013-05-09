
#include <iostream>
#include "RandomNumberGeneratorTests.h"
#include "RandomNumberGenerator.h"


RandomNumberGeneratorTests::RandomNumberGeneratorTests(void)
{
	name = "Random Number Generator Testing";
}


RandomNumberGeneratorTests::~RandomNumberGeneratorTests(void)
{
}

void RandomNumberGeneratorTests::RunAllTests( void )
{
	test( 500 );
	test( 500 );
	test( 500 );
}

/**
 * Just test it here, I'm lazy
 */
void RandomNumberGeneratorTests::test( int iter )
{
	beginTest();

	RandomNumberGenerator r;

	int i = 0;
	int cnt[7] = { 0,0,0,0,0,0,0 };
	std::cout << iter << " Random Number Generation 0-6:" << std::endl;

	while(++i != iter) 
	{
		cnt[r.nextNumber(6)]++;
	}
		
	for( i = 0; i < 7; ++i )
	{
		std::cout << i << ": " << cnt[i] << " (" << ((float) cnt[i] / (float) iter) * 100 << "%)" << std::endl; 
	}

	endTest();
}

