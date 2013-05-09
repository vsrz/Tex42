
#ifndef TRICKTESTS_H
#define TRICKTESTS_H
#pragma once

#include "Tests.h"
#include "Trick.h"

class TrickTests : public Tests
{
public:
    TrickTests(void) { name = "Trick tests"; }
    ~TrickTests(void) {} ;

    void RunAllTests( void );
    void TrickWinner( void );
    void TrickCount( void );
};


#endif

