
#ifndef DOMINOCOLLECTION_H
#define DOMINOCOLLECTION_H

#pragma once

#include <vector>
#include <iostream>

#include "Domino.h"



class DominoCollection {

protected:
	std::vector<Domino> dominoes;

public:
	DominoCollection( void ) {}
	DominoCollection( const Domino &d ) { dominoes.push_back( d ); }
	DominoCollection( const std::vector<Domino> &d ) { dominoes = d; }
	~DominoCollection( void ) {} 

	Domino removeDomino( void );
	Domino drawDomino( void );
	Domino getDomino( Domino d );

	void addDomino( Domino d );
	void addDominoes( DominoCollection dominoes );
    void shuffle( void );
	bool isEmpty( void );
	void print( std::ostream & out );

    int size( void );
	int getSize( void );
    int countDominoes( const Domino d );
	bool contains( const Domino d );
    int containsSuit( int suit );
    int getTotalScore( void );

	DominoCollection & operator = ( const DominoCollection dc );
	bool operator == ( const DominoCollection dc ) const;
	bool operator != ( const DominoCollection dc ) const;

    void generateDoubleSixSet( void );

};

std::ostream & operator << ( std::ostream & out, DominoCollection d );
#endif

