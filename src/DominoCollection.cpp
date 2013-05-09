
#include <iterator>
#include <vector>
#include <cassert>

#include "DominoCollection.h"
#include "RandomNumberGenerator.h"


/**
 * Adds the specified domino into the stack of dominoes
 */
void DominoCollection::addDomino( Domino d ) {
	dominoes.push_back( d );
}

/**
 * Removes the dominoes from source one by one and adds them to this collection
 */
void DominoCollection::addDominoes( DominoCollection source )
{
    for( int i = source.size(); i > 0; --i )
    {
        dominoes.push_back( source.drawDomino() );
    }
}


/**
 * Removes and returns the next domino on the stack of dominoes.
 */
Domino DominoCollection::removeDomino( void )
{
	Domino d(dominoes.back());
	dominoes.pop_back();
	return d;
}

/**
 * Returns the number of dominoes in this collection that are 
 * of the given suit.
 */
int DominoCollection::containsSuit( int suit )
{
    int count = 0;
    if( dominoes.size() == 0 ) return -1;
    for( std::vector<Domino>::iterator it = dominoes.begin();
        it != dominoes.end();
        ++it )
    {
        if( it->getRightPip() == suit || it->getLeftPip() == suit ) count++;
    }
    return count;
}

/**
 * Removes and returns a random domino from the stack
 */	
Domino DominoCollection::drawDomino( void )
{
	RandomNumberGenerator r;
	int index = r.nextNumber( (int) dominoes.size() - 1);
	Domino d( dominoes[index] );
	dominoes.erase( dominoes.begin() + index );
	
	return d;
	

}

/**
 * Shuffles the dominoes in this collection
 */	
void DominoCollection::shuffle( void ) {
	
	std::vector<Domino> d;
	while( ! isEmpty() )
	{
		Domino dom;
		dom = drawDomino();
		d.push_back( dom );

	}
	dominoes = d;
}

/**
 * Returns and removes a specific domino from the collection
 */
Domino DominoCollection::getDomino( Domino d ) {
	throw "Not yet implemented";
}

bool DominoCollection::isEmpty( void )
{
	return dominoes.size() == 0;
}

/**
 * Prints all the dominoes in the stack, in order
 */
void DominoCollection::print( std::ostream & o )
{
	int count = 0;
	
	// loop through each domino in the stack and print it
    for( std::vector<Domino>::iterator it = dominoes.begin();
    		it != dominoes.end();
    		++it )
    {
    	Domino d = *it;
    	o << d;

    	// line-break every 6 dominoes
    	if( ++count % 6 == 0 ) std::cout << std::endl;
    }
    	

}


int DominoCollection::size( void )
{
    return (int) dominoes.size();
}

int DominoCollection::getSize( void )
{
	return (int) dominoes.size();
}

/**
 * Returns the number of dominoes that match the domino given in this set
 */
int DominoCollection::countDominoes( const Domino d )
{
    int count = 0;

	for( std::vector<Domino>::iterator it = dominoes.begin();
		it != dominoes.end();
		++it )
		if( *(it) == d ) count++;

	return count;
}

/**
 * Returns the score (total count) provided by the dominoes in this collection
 */
int DominoCollection::getTotalScore( void )
{
    int count = 0;

    // one point for each trick taken
    count += dominoes.size() / 4;

    // ten counters
    if( countDominoes( Domino( 5, 5 ) ) > 0 ) count += 10;
    if( countDominoes( Domino( 4, 6 ) ) > 0 ) count += 10;

    // five counters
    if( countDominoes( Domino( 0, 5 ) ) > 0 ) count += 5;
    if( countDominoes( Domino( 1, 4 ) ) > 0 ) count += 5;
    if( countDominoes( Domino( 2, 3 ) ) > 0 ) count += 5;

    return count;
}


/**
 * Returns true if the domino exists somewhere in the collection
 */
bool DominoCollection::contains( const Domino d ) 
{
    return countDominoes( d ) > 0 ;

}

DominoCollection & DominoCollection::operator = ( const DominoCollection dc )
{
	if( dc == *this)
		return *this;
	dominoes = dc.dominoes;
	return *this;
}

bool DominoCollection::operator == ( const DominoCollection dc ) const
{
	return dominoes == dc.dominoes;

}

bool DominoCollection::operator != ( const DominoCollection dc ) const
{
	return !( dc == *this );
}


std::ostream & operator << ( std::ostream & out, DominoCollection d )
{
	d.print( out );
	return out;

}

/**
 * Overwrites the current collection with a new set of Double-Six dominoes
 */
void DominoCollection ::generateDoubleSixSet( void )
{
    DominoCollection set;
    for( int i = 6; i > -1; --i )
    {
        for( int j = i; j > -1; --j )
        {
            set.addDomino( Domino( i, j) );
        }
    }
    
    *this = set;
}


