
#ifndef SFMLBASICTESTS_H
#define SFMLBASICTESTS_H

#pragma once

#include "Tests.h"

class SFMLBasicTests : public Tests
{
public:
	SFMLBasicTests(void);
	~SFMLBasicTests(void);

	void RunAllTests( void );
	void SFMLDrawingTest( void );
	void SFMLBasicTest( void );
	void SFMLTestRun( void );

};

#endif
