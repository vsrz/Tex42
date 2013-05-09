
#ifndef TEXAS42SET_H
#define TEXAS42SET_H

#pragma once

#include "PlayerCollection.h"
#include "DominoCollection.h"
#include "Trick.h"
#include "Team.h"

class Texas42Set
{
private:
    PlayerCollection *players;
    DominoCollection dominoSet;
    Trick tricks[7];

    Player *openingBidder;
    Player *winningBidder;

    Bid highBid;
    Team *team1, *team2;
    
public:
    Texas42Set( PlayerCollection *players, DominoCollection dominoSet, Player *openingBidder, Team *team1, Team *team2 ) : 
        players( players ), dominoSet( dominoSet ), openingBidder( openingBidder ), team1( team1 ), team2( team2 )  {  } 
    ~Texas42Set(void) {  }

    void drawHands( Player *firstDraw );
    Player* playTrick( Trick *trick, Player *lead );
    Player* solicitBids( void );
    void resolveSet( void );
    void setWinningBid( Bid bid );
    void giveTrick( Player *winner, Trick trick );
	Bid getBid( void );

    void play( void );
};

#endif
