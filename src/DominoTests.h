
#ifndef DOMINOTESTS_H
#define DOMINOTESTS_H

#include "Tests.h"

class DominoTests : protected Tests
{
public:
	DominoTests( void ) : Tests () {};
	void RunAllTests( void );
    void DominoCreation( void );
    void DominoPipTests( void );
    void DominoComparison( void );
    
};

#endif
