#include "PlayerAI.h"
#include "Trick.h"

Bid PlayerAI::makeBid( Bid b ) 
{
	
	// Just return a bid based on the number of potential trumps
    int suits[7];
    int high = 0;
    int index = 0;

    // Build a data structure that shows how many of each potential trump I have
    for( int i = 0; i < 7; ++i )
    {
        suits[i] = hand.containsSuit( i );
        
    }

    // Find the suit that we would make trump
    for( int i = 0; i < 7; ++i )
    {
        if( std::max(suits[i], high ) > high )
        {
            index = i;
            high = suits[i];
        }

    }

    // Base the bid on the number of trumps I have
    switch( high )
    {
    case 6:
        return( Bid( 84, index ));
        break;
    case 5:
        return( Bid( 35, index ));
        break;
    case 4:
        return( Bid( 31, index ));
        break;
    default:
        return( Bid( 30, index ));
        break;
    }

}


Domino PlayerAI::playDomino( Bid bid, DominoCollection trick )
{
    // Find out if we're leading the trick
    /*if( trick.size() == 0 )
    {
    }
*/
    // If not, see if we can follow suit
    //if( trick.containsSuit( trick.getSuit() ) )
    //{
    //    // follow suit if possible
    //}

    // If we think we're winning this trick, let's play count

    // Otherwise, play some garbage

    // Figure out what we can't catch anything with

    // We have no good choices, so let's play something random
    return hand.drawDomino();
}
