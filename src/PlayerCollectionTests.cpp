
#include <iostream>
#include <string>
#include "PlayerCollectionTests.h"
#include "PlayerAI.h"


void PlayerCollectionTests::RunAllTests( void )
{
    TurnTaking();
}

void PlayerCollectionTests::TurnTaking( void )
{
    name = "Test turn taking";
    beginTest();

    PlayerAI p0("AI Player 1", 0);
    PlayerAI p1("AI Player 2", 1);
    PlayerAI p2("AI Player 3", 2);
    PlayerAI p3("AI Player 4", 3);

    PlayerCollection players;

    std::cout << "Add " << p0 << " to the collection";
    players.addPlayer( &p0 );
    assert( players.contains( &p0 ) );
    std::cout << " Ok." << std::endl;
    
    std::cout << "Add " << p1 << " to the collection";
    players.addPlayer( &p1 );
    assert( players.contains( &p1 ) );
    std::cout << " Ok." << std::endl;

    std::cout << "Add " << p1 << " to the collection";
    players.addPlayer( &p2 );
    assert( players.contains( &p2 ) );
    std::cout << " Ok." << std::endl;

    std::cout << "Add " << p2 << " to the collection";
    players.addPlayer( &p3 );
    assert( players.contains( &p3 ) );
    std::cout << " Ok." << std::endl;

    std::cout << "Start with " << p0 << "'s turn";
    assert( players.getNextPlayer() == &p0 );
    std::cout << " Ok." << std::endl;

    std::cout << "Start with " << p1 << "'s turn";
    assert( players.getNextPlayer() == &p1 );
    std::cout << " Ok." << std::endl;

    std::cout << "Start with " << p2 << "'s turn";
    assert( players.getNextPlayer() == &p2 );
    std::cout << " Ok." << std::endl;

    std::cout << "Start with " << p3 << "'s turn";
    assert( players.getNextPlayer() == &p3 );
    std::cout << " Ok." << std::endl;

    std::cout << "Wrap around for " << p0 << "'s turn";
    assert( players.getNextPlayer() == &p0 );
    std::cout << " Ok." << std::endl;

    std::cout << "Now it's " << p1 << "'s turn";
    assert( players.getNextPlayer() == &p1 );
    std::cout << " Ok." << std::endl;

    std::cout << "Now it's " << p2 << "'s turn";
    assert( players.getNextPlayer() == &p2 );
    std::cout << " Ok." << std::endl;

    std::cout << "Now it's " << p3 << "'s turn";
    assert( players.getNextPlayer() == &p3 );
    std::cout << " Ok." << std::endl;

    std::cout << "Set the turn to " << p1 << ".";
    players.setNextPlayer( &p1 );
    assert( players.getNextPlayer() == &p1 );
    std::cout << " Ok." << std::endl;

    std::cout << "Set the turn to " << p3 << ".";
    players.setNextPlayer( &p3 );
    assert( players.getNextPlayer() == &p3 );
    std::cout << " Ok." << std::endl;

    endTest();



}

