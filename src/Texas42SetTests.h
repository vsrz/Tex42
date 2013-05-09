
#ifndef TEXAS42SETTESTS_H
#define TEXAS42SETTESTS_H

#pragma once
#include "Tests.h"
#include "Texas42Set.h"

class Texas42SetTests : public Tests
{
protected:
    PlayerAI p1;
    PlayerAI p2;
    PlayerAI p3;
    PlayerAI p4;

	Team team1;
	Team team2;
    
	DominoCollection doubleSixSet;
    PlayerCollection players;

public:
    Texas42SetTests(void);
    ~Texas42SetTests(void) {} 

    void RunAllTests( void );
    void PlayTrick( void );
	void GetBids( void );
    void TrickWinnerTests( void );
	void RunSet( void );
    

};

#endif
