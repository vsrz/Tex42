
#ifndef PLAYERTESTS_H
#define PLAYERTESTS_H

#pragma once

#include "Domino.h"
#include "DominoCollection.h"
#include "Tests.h"
#include "PlayerAI.h"

class PlayerTests : public Tests
{
public:
    PlayerTests(void);
    ~PlayerTests(void);

    void RunAllTests( void );
    void DrawDominoes( void );
};

#endif
