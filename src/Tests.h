
#ifndef TESTS_H
#define TESTS_H

#pragma once

#include <iostream>
#include <cassert>

#include "Domino.h"
#include "DominoCollection.h"

class Tests
{

protected:
    int number;
    std::string name;
	void beginTest( void );
    void endTest( void );
    
public:
    Tests( void ) : number( 0 ) {}
    virtual ~Tests( void ) {}

    virtual void RunAllTests( void ) = 0;

    
};

#endif
