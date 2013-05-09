#include "Texas42Set.h"

void Texas42Set::drawHands( Player *firstDraw )
{
    players->setNextPlayer( firstDraw );
	do
	{
		players->getNextPlayer()->drawDominoes( dominoSet );
    } while( players->nextPlayer() != firstDraw );

}

/**
 * Determines the set winner and awards marks to the winning team
 */
void Texas42Set::resolveSet( void )
{
    int marks = 1;

    // If the bid is higher than 42, 84 = 2 marks, 126 = 3 marks, 168 = 4 marks
	if( highBid.getBid() > 42 ) 
	{
		marks = highBid.getBid() / 42;
	}

	/** 
	 *  If the seat of the winning bidder did not make their bid, increment 
	 *  the seat of the game winner by 1 so the opposing team will be assigned
	 *  winning marks
	 */
    if( team1->contains( winningBidder ) )
    {
        if( team1->dominoes.getTotalScore() >= highBid.getBid() )
        {
            team1->addMarks( marks );
        }
        else
        {
            team2->addMarks( marks );
        }
    }
    else
    {
        if( team2->dominoes.getTotalScore() >= highBid.getBid() )
        {
            team2->addMarks( marks );
        }
        else
        {
            team1->addMarks( marks );
        }
    }
}

/**
 *  Play a trick and return the index of the player that won the trick
 * starting with the lead Player.
 */
Player* Texas42Set::playTrick( Trick *trick, Player *lead)
{    
    int winner = 0;
    players->setNextPlayer( lead );


    // Have each player play a domino
    do
    {
        trick->addDomino( players->getNextPlayer()->playDomino( highBid, *trick ) );
    } while( lead != players->nextPlayer() );
    
    // Set the winner of the trick as the first player for the next trick
    winner = trick->getWinner();
    if( winner < 1 ) return lead;
    
    // adjust the trick winner relative to the lead player
    do
    {
        players->getNextPlayer();
    } while( winner-- != 0 );

    return players->getCurrentPlayer();
}

/**
 * solicit bids and trumps from the players
 */ 
Player* Texas42Set::solicitBids( void )
{           
    // Set the opening bidder 
    players->setNextPlayer( openingBidder );

    // Go around the table and get the bids
	do
	{
		Bid bid = players->getNextPlayer()->makeBid( highBid );
		if( bid > highBid )
		{
			highBid = bid;
			winningBidder = players->getCurrentPlayer();
		}

	} while( players->nextPlayer() != openingBidder );
    
	return winningBidder;
}

/**
 * Set the winning bid for this set, used for debugging
 */
void Texas42Set::setWinningBid( Bid bid )
{
    highBid = bid;
}

/**
 * Gives the trick to the winning team
 */
void Texas42Set::giveTrick( Player *winner, Trick trick )
{
    if( team1->contains( winner ) ) 
    {
        team1->dominoes.addDominoes( trick );
    }
    else
    {
        team2->dominoes.addDominoes( trick );
    }
}

/** 
 * returns the bid for this set
 */
Bid Texas42Set::getBid( void )
{
	return highBid;
}

/**
 * Play this set and give marks to the winning team
 */
void Texas42Set::play( void )
{
    // Draw hands
    drawHands( openingBidder );

    // Get the bids and set the winning bid as the starting player
    Player* lead = solicitBids();
    
    // Play each trick
    for( int turn = 0; turn < 7; ++turn )
    {
		tricks[turn].setTrump( highBid.getTrump() );
        lead = playTrick( &tricks[turn], lead );
        
        // Give the trick to the winning team
        giveTrick( lead, tricks[turn] );
        
    }
    resolveSet();

}
