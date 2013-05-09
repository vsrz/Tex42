
#ifndef RANDOMNUMBERGENERATORTESTS_H
#define RANDOMNUMBERGENERATORTESTS_H

#pragma once
#include "Tests.h"
class RandomNumberGeneratorTests :
	protected Tests
{
public:
	RandomNumberGeneratorTests(void);
	~RandomNumberGeneratorTests(void);

	void RunAllTests( void );
	void test( int iter );


};

#endif
