#include "Texas42GameTests.h"
#include "PlayerAI.h"
#include "PlayerCollection.h"

void Texas42GameTests::RunAllTests()
{
    RunAIGame();
}

void Texas42GameTests::RunAIGame()
{
    name = "Game test";
    beginTest();
    DominoCollection dominoSet;
    dominoSet.generateDoubleSixSet();

    PlayerAI player[4];
    PlayerCollection players;

    // Creates AI players for this set
    for( int i = 0; i < 4; ++i )
    {
        player[i].setName( "AI Player" );
        players.addPlayer( &player[i] );
    }

    // Sets partners for them
    for( int i = 0; i < 2; ++i )
    {
        player[i].setPartner( & player[i+2] );
        player[i+2].setPartner( & player[i] );
    }

    Texas42Game game( dominoSet, players );

    game.begin();
    endTest();
}

