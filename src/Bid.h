
#ifndef BID_H
#define BID_H

#pragma once

#include <iostream>

class Bid {

private:
	int bid;
    int trump;

public:
	Bid( void ) : bid( 0 ), trump( 0 ) {}
	Bid( int bid, int trump ) : bid( bid ), trump( trump ) {} 
    
    void setBid( int bid );
    void setTrump( int trump );

    int getBid( void );
    int getTrump( void );

    bool operator > ( Bid b );
    bool operator < ( Bid b );

    void printBid( std::ostream & out );

};

std::ostream & operator << ( std::ostream & o, Bid b );

#endif
