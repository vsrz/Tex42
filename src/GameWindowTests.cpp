#include <SFML/Graphics.hpp>
#include <vector>
#include "GameWindowTests.h"
#include "GameWindow.h"
#include "RandomNumberGenerator.h"
#include "Tile.h"

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
	RandomNumberGenerator r;
	GameWindow window;
	std::vector< std::vector<Tile> > tiles;
	std::vector< sf::Drawable* > items;

	tiles.resize( 11 );
	for( int i = 0; i < 11; ++i ) 
	{
		tiles[i].resize( 8 );
		for( int j = 0 ; j < 8; ++j )
		{
			tiles[i][j].setPosition( sf::Vector2f( i * 200, j * 100 ) );
			tiles[i][j].setSize( sf::Vector2f( 200, 100 ) );
			tiles[i][j].setColor( sf::Color( r.nextNumber( 255 ), r.nextNumber( 255 ), r.nextNumber( 255 ) )) ;
			items.push_back( tiles[i][j].getImage() );			
		}
	}

	for( std::vector<sf::Drawable*>::iterator it = items.begin();
        it != items.end();
        ++it ) 
	{
		window.draw( *it );
	}
	
	window.display();
	sf:sleep( sf::Time( sf::seconds( 3 ) ) );
	
}

