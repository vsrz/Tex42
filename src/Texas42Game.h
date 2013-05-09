
#ifndef TEXAS42GAME_H
#define TEXAS42GAME_H
#pragma once

#include "DominoCollection.h"
#include "PlayerCollection.h"

class Texas42Game 
{

private:
    DominoCollection dominoSet;
    PlayerCollection table;
    int firstBidder;
    int setsPlayed;

public:
    Texas42Game( void ) { firstBidder = -1; }
    Texas42Game( DominoCollection dominoSet, PlayerCollection players ) : dominoSet( dominoSet ), table ( players) {}

    void createPlayers();
    void begin( void );
};

#endif
