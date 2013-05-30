#include <SFML/Graphics.hpp>
#include <vector>
#include "GameWindowTests.h"
#include "GameWindow.h"
#include "RandomNumberGenerator.h"
#include "Tile.h"
#include "PlayerAI.h"
#include "DominoCollection.h"
#include "PlayerRenderer.h"

GameWindowTests::GameWindowTests(void)
{
}


GameWindowTests::~GameWindowTests(void)
{
}

void GameWindowTests::RunAllTests( void )
{
	windowTest();

	//sf::sleep( sf::Time( sf::seconds( 2 ) ) );
}

void GameWindowTests::windowTest( void )
{
	PlayerAI player0, player1, player2, player3;	
	RandomNumberGenerator r;
	DominoCollection set;

	sf::RenderWindow window( sf::VideoMode( 1024, 768 ), "SFML Tests", sf::Style::Titlebar );
	window.clear( sf::Color( 0, 55, 0, 0 ) );
	set.generateDoubleSixSet();
	
	// player0
	player0.setName( "Player One" );
	player0.drawDominoes( set );

	// player1
	player1.drawDominoes( set );
	player1.setName( "Player Two" );

	// player2
	player2.drawDominoes( set );
	player2.setName( "Player Three" );

	// player3
	player3.drawDominoes( set );
	player3.setName( "Player Four" );


	PlayerRenderer g_player0( &player0, 0, &window );
	g_player0.update();
	g_player0.draw( );
	
	PlayerRenderer g_player1( &player1, 1, &window );
	g_player1.update();
	g_player1.draw();

	PlayerRenderer g_player2( &player2, 2, &window );
	g_player2.update();
	g_player2.draw();

	PlayerRenderer g_player3( &player3, 3, &window );
	g_player3.update();
	g_player3.draw();

	window.display();
	sf:sleep( sf::Time( sf::seconds( 5 ) ) );
	
}

