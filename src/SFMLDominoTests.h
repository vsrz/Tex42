
#ifndef SFMLDOMINOTESTS_H
#define SFMLDOMINOTESTS_H
#pragma once

#include "Tests.h"
class SFMLDominoTests :	public Tests
{
public:
	SFMLDominoTests(void);
	~SFMLDominoTests(void);
	void RunAllTests( void );
	void DominoCreationTests( void );
};

#endif
