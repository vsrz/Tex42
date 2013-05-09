

#include <iostream>
#include "Texas42Game.h"
#include "DominoCollection.h"
#include "PlayerAI.h"

#ifdef RUN_TESTS

#include "Tests.h"
#include "DominoCollectionTests.h"
#include "DominoTests.h"
#include "RandomNumberGeneratorTests.h"
#include "PlayerTests.h"
#include "PlayerCollectionTests.h"
#include "TrickTests.h"
#include "Texas42SetTests.h"

#endif


int main( int argc, char** argv)
{

#ifdef RUN_TESTS

	DominoTests dt;
	DominoCollectionTests dct;
	RandomNumberGeneratorTests r;
    PlayerTests pt;
    PlayerCollectionTests pct;
    TrickTests tt;
    Texas42SetTests tst;

	r.RunAllTests();
	dt.RunAllTests();
	dct.RunAllTests();
    pt.RunAllTests();
    pct.RunAllTests();
    tt.RunAllTests();
    tst.RunAllTests();

#else


    DominoCollection dominoSet;
    dominoSet.generateDoubleSixSet();

    PlayerAI player[4];
    PlayerCollection players;

    // Creates AI players for this set
    player[0].setName( "AI Player 1" );
    players.addPlayer( &player[0] );
    player[1].setName( "AI Player 2" );
    players.addPlayer( &player[1] );
    player[2].setName( "AI Player 3" );
    players.addPlayer( &player[2] );
    player[3].setName( "AI Player 4" );
    players.addPlayer( &player[3] );
    

    // Sets partners for them
    for( int i = 0; i < 2; ++i )
    {
        player[i].setPartner( & player[i+2] );
        player[i+2].setPartner( & player[i] );
    }

    Texas42Game game( dominoSet, players );
    game.begin();
    std::cin.get();
#endif

    return 0;
}
