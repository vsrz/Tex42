
#include "PlayerCollection.h"


PlayerCollection::PlayerCollection(void)
{
    turn = -1;
}


PlayerCollection::~PlayerCollection(void)
{
}

/**
 *	Returns an integer representing the position that the player
 * is found in the vector.
 */
int PlayerCollection::indexOf( Player *player )
{
    int i = -1;
    for( std::vector<Player*>::iterator it = players.begin();
         it != players.end();
         ++it )
     {
         ++i;
         if( *it == player ) return i;
     }

     return -1;
}

/**
 * Haven't thought of a better way to implement this right now
 * but the order that you push the players into the collection is
 * the order they are sitting at the table.
 */
void PlayerCollection::addPlayer( Player *p )
{
    if( players.size() < 4 )
    {
        players.push_back( p );
		
    }
	
}

/**
 * Returns a pointer to the player that is next up. This does not actually
 * increment the player iterator
 */
Player* PlayerCollection::nextPlayer( void )
{
    if( turn == -1 || turn + 1 == players.size() ) return players[0];
    return players[turn + 1];
}

/**
 * Returns the player and advances the turn
 */
Player* PlayerCollection::getNextPlayer( void )
{
	turn++;
    if( turn == players.size() )
    {
        turn = 0;
    }
	return players[turn];
}

/**
 * Returns the player that just played a turn
 */
Player* PlayerCollection::getCurrentPlayer( void )
{
	if( turn == - 1 ) return players[players.size() - 1];
    return players[turn];
}


/**
 *  Sets the player who will be returned when nextPlayer() is called
 */
void PlayerCollection::setNextPlayer( Player *player )
{
    turn = indexOf( player ) - 1;
}

int PlayerCollection::playerCount( void )
{
    return (int) players.size();
}

/**
 * Returns true if there's a player in the seat
 */
 bool PlayerCollection::contains( Player *player )
 {
     return indexOf( player ) >= 0;
 }

/**
 * Returns the address to a player in the collection
 */
Player* PlayerCollection::operator [] ( const int index )
{
    return players[index];
}
