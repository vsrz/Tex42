
#ifndef TEXAS42GAMETESTS_H
#define TEXAS42GAMETESTS_H

#pragma once
#include "Tests.h"
#include "Texas42Game.h"


class Texas42GameTests : public Tests
{
public:
    Texas42GameTests(void) { name = "Texas 42 Game Tests"; }
    ~Texas42GameTests(void) {} 

    void RunAllTests( void );
    void RunAIGame( void );
};

#endif
