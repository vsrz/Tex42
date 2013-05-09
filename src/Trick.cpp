
#include "Trick.h"

#include <iostream>

int Trick::getTrump( void )
{
    return bid.getTrump();
}

void Trick::setTrump( int trump )
{
    bid.setTrump( trump );
}

/**
 *  Returns the index of the domino that was played that won the trick
 */
int Trick::getWinner( void )
{
    if(dominoes.size() == 0) 
    {
        return -1;
    }
    
    if(dominoes.size() == 1)
    {
        return 0;
    }

    Domino winningDomino;
    int winningPlayerIndex = 0;
    int currentPlayerIndex = 0;
    int suit;
    for( std::vector<Domino>::iterator it = dominoes.begin();
        it != dominoes.end();
        ++it )
    {
        // always assign the first domino as the winning domino
        if( currentPlayerIndex == 0 ) 
        {
            winningDomino = *it;

            // set the suit of the domino
            suit = winningDomino.getHighPip();

            // override the suit if the domino is trump
            if( winningDomino.isSuit( bid.getTrump() ) )
            {
                suit = bid.getTrump();
            }
             
        } 
        // if not the first domino, check to see if its larger
        else
        {
            // if the current leader is not trump and ours is, we win and set trump as suit
            if( !winningDomino.isSuit( bid.getTrump() ) && it->isSuit( bid.getTrump() ) )
            {
                winningPlayerIndex = currentPlayerIndex;
                winningDomino = *it;
                suit = bid.getTrump();
            }
            
            // if the current leader is a trump suit and so is ours, compare it
            else if( winningDomino.isSuit( bid.getTrump() ) && it->isSuit( bid.getTrump() ) )
            {
                if( it->isLargerThan( winningDomino, bid.getTrump() ) )
                {
                    winningPlayerIndex = currentPlayerIndex;
                    winningDomino = *it;
                }
            }

            // the current leader plays a suit which we followed
            else if( it->isLargerThan( winningDomino, suit ) )
            {
                winningPlayerIndex = currentPlayerIndex;
                winningDomino = *it;
            }
        }
        
        currentPlayerIndex++;
    }

    return winningPlayerIndex;

}

/**
 *  Returns the number of points that this trick is worth
 */
int Trick::getValue( void )
{
    // All tricks are worth at least 1 point
    int value = 1;
    
    for( std::vector<Domino>::iterator it = dominoes.begin();
        it != dominoes.end();
        ++it )
    {    
        value += it->isCounter();
    }

    return value;
}

Trick & Trick::operator = ( const Trick trick )
{
    this->dominoes = trick.dominoes;
    this->bid = trick.bid;
    return *this;
}

/**
 * empties the dominos from the trick
 */
void Trick::emptyTrick( void )
{
    dominoes.clear();
}

/**
 * Return the suit of the trick
 */
int Trick::getSuit( void )
{
    
    // If the lead domino is trump return trump, otherwise return high pip
    if( dominoes.size() > 0 && bid.getTrump() >= 0 )
    {
        if( dominoes[0].isSuit( bid.getTrump() ) )
        {
            return bid.getTrump();
        }
        return dominoes[0].getHighPip();
    }

    // No dominoes have been played in this trick
    return -1;
}

