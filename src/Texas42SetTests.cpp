#include "Texas42SetTests.h"
#include "PlayerAI.h"
#include "DominoCollection.h"
#include "PlayerCollection.h"
#include "Trick.h"
#include "Team.h"


Texas42SetTests::Texas42SetTests( void )
{
	name = "Texas 42 Set Tests";

}


void Texas42SetTests::RunAllTests( void )
{
	GetBids();
    TrickWinnerTests();
	RunSet();
    RunSet();
    RunSet();
    RunSet();
    RunSet();
    RunSet();
    RunSet();
}

void Texas42SetTests::RunSet( void )
{
	name = "Run a test set";
	beginTest();

	
    p1.setName( "Player 1" );
    p2.setName( "Player 2" );
    p3.setName( "Player 3" );
	p4.setName( "Player 4" );

	Team team1;
	Team team2;

    players.addPlayer( &p1 );
    players.addPlayer( &p2 );
    players.addPlayer( &p3 );
    players.addPlayer( &p4 );

	team1.addPlayer( &p1 );
	team1.addPlayer( &p3 );
	team2.addPlayer( &p2 );
	team2.addPlayer( &p4 );

	doubleSixSet.generateDoubleSixSet();

	Player* openingBidder = &p1;
	Texas42Set set( &players, doubleSixSet, openingBidder, &team1, &team2 );

	std::cout << "Draw hands.";
	set.drawHands( openingBidder );
	assert( p1.getHand().getSize() == 7 );
	std::cout << " Ok." << std::endl;

	std::cout << "Solicit bids from players.";
	Player *winningBidder = set.solicitBids();
	Player *lead = winningBidder;
	std::cout << " Ok." << std::endl;

	if( team1.contains( winningBidder ) )
	{
		std::cout << *winningBidder << " on Team 1 has won the bid for " << set.getBid() << ". ";
	}
	else
	{
		std::cout << *winningBidder << " on Team 2 has won the bid for " << set.getBid() << ". ";
	}
	std::cout << "Trump is " << set.getBid().getTrump() << std::endl;
	
	Trick tricks[7];

	for( int turn = 0; turn < 7; ++turn )
	{
		tricks[turn].setTrump( set.getBid().getTrump() );
		std::cout << "Trick " << turn+1 << ": Lead Player is: " << *lead << std::endl;
		lead = set.playTrick( &tricks[turn], lead );
        set.giveTrick( lead, tricks[turn] );
		std::cout << tricks[turn] <<  "Winner: " << *lead << std::endl;

	}

	set.resolveSet();
	
	std::cout << "Resolve set. Team 1 scored: " << team1.dominoes.getTotalScore();
	std::cout << " Team 2 Scored: " << team2.dominoes.getTotalScore() << std::endl;

	if( team1.contains( winningBidder ) )
	{
		if( team1.dominoes.getTotalScore() >= set.getBid().getBid() )
		{
			std::cout << "Team 1 made their bid!";
		}
		else
		{
			std::cout << "Team 2 set Team 1's bid!";
		}
	}
	else
	{
		if( team2.dominoes.getTotalScore() >= set.getBid().getBid() )
		{
			std::cout << "Team 2 made their bid!";
		}
		else
		{
			std::cout << "Team 1 set Team 2's bid!";
		}
	}
	std::cout << std::endl;

	endTest();





}

void Texas42SetTests::TrickWinnerTests( void )
{
    name = "Trick winner tests";
    beginTest();

	
    p1.setName( "Player 1" );
    p2.setName( "Player 2" );
    p3.setName( "Player 3" );
	p4.setName( "Player 4" );

	Team team1;
	Team team2;

    players.addPlayer( &p1 );
    players.addPlayer( &p2 );
    players.addPlayer( &p3 );
    players.addPlayer( &p4 );

	team1.addPlayer( &p1 );
	team1.addPlayer( &p3 );
	team2.addPlayer( &p2 );
	team2.addPlayer( &p4 );

	doubleSixSet.generateDoubleSixSet();

	Player *winner;

    Texas42Set set( &players, doubleSixSet, &p1, &team1, &team2);
    Trick trick( 3 );


    p1.hand.addDomino( Domino( 6, 6 ) );
    p2.hand.addDomino( Domino( 6, 4 ) );
    p3.hand.addDomino( Domino( 1, 4 ) );
    p4.hand.addDomino( Domino( 4, 4 ) );

    std::cout << "Play a trick, player 1 should win.";
    winner = set.playTrick( &trick, &p1 );
    assert( winner == &p1 );
    std::cout << " Ok." << std::endl;
    
    // via trump
    trick.emptyTrick();
    p1.hand.addDomino( Domino( 6, 6 ) );
    p2.hand.addDomino( Domino( 6, 4 ) );
    p3.hand.addDomino( Domino( 1, 4 ) );
    p4.hand.addDomino( Domino( 3, 4 ) );

    std::cout << "Play a trick, player 4 should win.";
    winner = set.playTrick( &trick, &p1 );
    assert( winner == &p4 );
    std::cout << " Ok." << std::endl;
    
    // via catch a trick
    trick.emptyTrick();
    p1.hand.addDomino( Domino( 6, 5 ) );
    p2.hand.addDomino( Domino( 6, 6 ) );
    p3.hand.addDomino( Domino( 1, 4 ) );
    p4.hand.addDomino( Domino( 4, 4 ) );

    std::cout << "Play a trick, player 2 should win.";
    winner = set.playTrick( &trick, &p1 );
    assert( winner == &p2 );
    std::cout << " Ok." << std::endl;
    
    // via high domino
    trick.emptyTrick();
    p1.hand.addDomino( Domino( 3, 5 ) );
    p2.hand.addDomino( Domino( 3, 3 ) );
    p3.hand.addDomino( Domino( 1, 4 ) );
    p4.hand.addDomino( Domino( 4, 4 ) );

    std::cout << "Play a trick, player 2 should win.";
    winner = set.playTrick( &trick, &p4 );
    assert( winner == &p2 );
    std::cout << " Ok." << std::endl;
    

    endTest();

    
}

void Texas42SetTests::GetBids( void )
{
	name = "Get bids from players";
	beginTest();

	
    p1.setName( "Player 1" );
    p2.setName( "Player 2" );
    p3.setName( "Player 3" );
	p4.setName( "Player 4" );

	Team team1;
	Team team2;

    players.addPlayer( &p1 );
    players.addPlayer( &p2 );
    players.addPlayer( &p3 );
    players.addPlayer( &p4 );

	team1.addPlayer( &p1 );
	team1.addPlayer( &p3 );
	team2.addPlayer( &p2 );
	team2.addPlayer( &p4 );

	doubleSixSet.generateDoubleSixSet();

	DominoCollection doubleSix;
	doubleSix.generateDoubleSixSet();
	
	// solicit bid test
	std::cout << "Solicit bids from all players.";
	Texas42Set set( &players, doubleSixSet, &p1, &team1, &team2);
	Player *winner = set.solicitBids();
	assert( winner == &p1 );
	std::cout << " Ok." << std::endl;

	endTest();
	
}

void Texas42SetTests::PlayTrick( void )
{
    name = "Play a mock trick";
	beginTest();

	
    p1.setName( "Player 1" );
    p2.setName( "Player 2" );
    p3.setName( "Player 3" );
	p4.setName( "Player 4" );

	Team team1;
	Team team2;

    players.addPlayer( &p1 );
    players.addPlayer( &p2 );
    players.addPlayer( &p3 );
    players.addPlayer( &p4 );

	team1.addPlayer( &p1 );
	team1.addPlayer( &p3 );
	team2.addPlayer( &p2 );
	team2.addPlayer( &p4 );

	doubleSixSet.generateDoubleSixSet();

	std::cout << "Set the winning bid";
    Bid b( 30, 6 );
    std::cout << " Trump: " << b.getTrump() << " Ok." << std::endl;
    
    Texas42Set set( &players, doubleSixSet, &p1, &team1, &team2 );
    set.setWinningBid( b );
    
//    Trick trick[7];    
    
    std::cout << "Draw hands for the players";
    for( int i = 0; i < 4; ++i )
    {
        players.nextPlayer()->drawDominoes( doubleSixSet );
    }
    std::cout << " Ok." << std::endl;
    
	/*
    int winner = 0;
    for( int i = 0; i < 7; i++ ) 
    {
        std::cout << "Play the trick";
        trick[i].setTrump( 6 );
        winner = set.playTrick( &trick[i], winner );
        std::cout << trick[i] << " Winner: " << winner << " Ok." << std::endl;

    }


	*/
    endTest();
}
