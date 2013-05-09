
#include "Texas42Game.h"
#include "Texas42Set.h"



void Texas42Game::begin( void )
{    
    // Enter set loop
    //while( 1 )
    {
        // Shuffle the dominoes
        dominoSet.shuffle();
        // continue to play sets until one team makes their mark
//        Texas42Set set( &table, dominoSet, firstBidder++ % 4 );
//        set.play();

    }

    //if( table.getMarks( 0 ) >= 7 ) 
    {
        std::cout << *table[0] << " and " << *table[2];
    }
    //else
    {
        std::cout << *table[1] << " and " << *table[3];
    }

    std::cout << " have won the game!" << std::endl;

}
