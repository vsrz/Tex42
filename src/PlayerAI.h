
#ifndef PLAYERAI_H
#define PLAYERAI_H

#include <algorithm>
#include "Player.h"
#include "Trick.h"

class PlayerAI : public Player 
{

public:
    PlayerAI( void ) {  }
    PlayerAI( std::string p, int s ) : Player ( p, s ) { }
	PlayerAI( std::string p ) : Player ( p ) {}

    Bid makeBid( Bid b );

    Domino playDomino( Bid bid, DominoCollection trick );


};

#endif
