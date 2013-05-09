
#include "TrickTests.h"
#include "PlayerAI.h"
#include "Domino.h"


void TrickTests::RunAllTests( void )
{
    TrickWinner();
    TrickCount();
}

void TrickTests::TrickCount( void )
{
    name = "Trick value tests";
    beginTest();
    

    Domino fiveFive( 5,5 );
    Domino fiveSix( 5,6 );
    Domino oneOne( 1,1 );
    Domino deuceTrey( 2,3 );
    Domino deuceFour( 4,2 );
    Domino blankBlank( 0,0 );
    Domino fiveBlank( 0,5 );
    Trick trick( Bid( 30, 5 ) );

    PlayerAI a[4];

    for( int i = 0; i < 4; ++i )
    {
        std::string s("Player ");
        char pn = 49 + i ;
        s += pn;
        a[i].setName( s );
    }

    trick.addDomino( fiveFive );
    trick.addDomino( deuceFour );
    trick.addDomino( deuceTrey );
    trick.addDomino( oneOne );
    std::cout << "Value of " << trick << " is 16.";
    assert( trick.getValue() == 16 );
    std::cout << " Ok." << std::endl;

    Trick trick1( Bid( 30, 1 ) );
    trick1.addDomino( deuceFour );
    trick1.addDomino( fiveSix );
    trick1.addDomino( blankBlank );
    trick1.addDomino( oneOne );
    std::cout << "Value of " << trick1 << " is 1.";
    assert( trick1.getValue() == 1 );
    std::cout << " Ok." << std::endl;

    Trick trick2( Bid( 30, 1 ) );
    trick2.addDomino( deuceFour );
    trick2.addDomino( fiveSix );
    trick2.addDomino( blankBlank );
    trick2.addDomino( fiveBlank );
    std::cout << "Value of " << trick2 << " is 6.";
    assert( trick2.getValue() == 6 );
    std::cout << " Ok." << std::endl;



    endTest();




}
void TrickTests::TrickWinner( void )
{
    name = "Test trick winner logic";
    beginTest();
    
    Domino fiveFive( 5,5 );
    Domino fiveSix( 5,6 );
    Domino oneOne( 1,1 );
    Domino deuceTrey( 2,3 );
    Domino deuceFour( 4,2 );
    PlayerAI a[4];
    for( int i = 0; i < 4; ++i )
    {
        std::string s("Player ");
        char pn = 49 + i ;
        s += pn;
        a[i].setName( s );
    }

    int trump = 5;
    std::cout << "Set trump to fives.";
    Trick trick( trump );
    assert( trick.getTrump() == trump );
    std::cout << " Ok." << std::endl;

    std::cout << "Player 1 plays " << fiveFive;
    trick.addDomino( fiveFive );
    assert( trick.contains( fiveFive ) );
    assert( trick.getWinner() == 0 );
    std::cout << " Ok." << std::endl;

    std::cout << "Player 2 plays " << fiveSix;
    trick.addDomino( fiveSix );
    assert( trick.contains( fiveSix ) );
    assert( trick.getWinner() == 0 );
    std::cout << " Ok." << std::endl;

    std::cout << "Player 3 plays " << deuceTrey;
    trick.addDomino( deuceTrey );
    assert( trick.contains( deuceTrey ) );
    assert( trick.getWinner() == 0 );
    std::cout << " Ok." << std::endl;

    std::cout << "Player 4 plays " << deuceFour;
    trick.addDomino( deuceFour );
    assert( trick.contains( deuceFour ) );
    assert( trick.getWinner() == 0 );
    std::cout << " Ok." << std::endl;

    std::cout << "Player 1 wins the trick ";
    assert( trick.getWinner() == 0 );
    std::cout << std::endl;

    trump = 2;
    std::cout << "Change the trump to deuces. Player 4 should win.";
    trick.setTrump( trump );
    assert( trick.getWinner() == 3 );
    std::cout << " Ok." << std::endl;

    trump = 3;
    std::cout << "Change the trump to treys. Player 3 should win.";
    trick.setTrump( trump );
    assert( trick.getWinner() == 2 );
    std::cout << " Ok." << std::endl;

    trump = 1;
    std::cout << "Change the trump to aces. Player 1 should win.";
    trick.setTrump( trump );
    assert( trick.getWinner() == 0 );
    std::cout << " Ok." << std::endl;

    trump = 6;
    std::cout << "Change the trump to sixes. Player 2 should win.";
    trick.setTrump( trump );
    assert( trick.getWinner() == 1 );
    std::cout << " Ok." << std::endl;




    endTest();
}

