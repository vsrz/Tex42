
#include "Bid.h"


void Bid::setTrump( int t)
{
    trump = t;
}
    

int Bid::getBid( void )
{
    return bid;
}
    
int Bid::getTrump( void )
{
    return trump;
}
    
bool Bid::operator > ( Bid b )
{
    return bid > b.bid;
}
    
bool Bid::operator < ( Bid b )
{
    return ! ( bid > b.bid );
}
    

void Bid::printBid( std::ostream & out )
{
    out << bid;
}
    
std::ostream & operator << ( std::ostream & o, Bid b )
{
    b.printBid( o );
    return o;
}
