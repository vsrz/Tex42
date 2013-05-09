
#ifndef PLAYERCOLLECTIONTESTS_H
#define PLAYERCOLLECTIONTESTS_H
#pragma once

#include "Tests.h"
#include "PlayerCollection.h"

class PlayerCollectionTests : public Tests
{

public:
    PlayerCollectionTests(void) { name = "PlayerCollectionTests"; } 
    ~PlayerCollectionTests(void) {}

    void RunAllTests( void );
    void TurnTaking( void );
    void MarksTest( void );

};


#endif
