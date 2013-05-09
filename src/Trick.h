
#ifndef TRICK_H
#define TRICK_H
#pragma once

#include "PlayerCollection.h"
#include "DominoCollection.h"
#include "Domino.h"

class Trick : public DominoCollection
{
private:
    Bid bid;
    
public:
    Trick( void ) {}
    Trick( Bid bid ) : bid ( bid ) {}
    Trick( int trump ) : bid( 30, trump ) {}
    ~Trick(void) {}  

    int getWinner( void );
    
    int getTrump( void );
    void setTrump( int t );
    int getValue( void );

    void emptyTrick( void );
    Trick & operator = ( const Trick trick );
    int getSuit( void );
    
};

#endif
