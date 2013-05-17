#include "GameWindow.h"
#include "RandomNumberGenerator.h"

GameWindow::GameWindow(void)
{
	RandomNumberGenerator r;
	window.create( sf::VideoMode( 1024, 768 ), "Tex42" );
	for( int i = 0; i < 11; ++i ) 
	{
		for( int j = 0 ; j < 8; ++j )
		{
			tiles[i][j].setPosition( sf::Vector2f( i * 200, j * 100 ) );
			tiles[i][j].setSize( sf::Vector2f( 200, 100 ) );
			tiles[i][j].setColor( sf::Color( r.nextNumber( 255 ), r.nextNumber( 255 ), r.nextNumber( 255 ) )) ;
		}
	}

	window.create( sf::VideoMode( 1024, 768 ), "SFML Tests", sf::Style::Titlebar );
	window.setVerticalSyncEnabled( true );
	
}


GameWindow::~GameWindow(void)
{
}

void GameWindow::draw( void )
{
	window.clear( sf::Color::Black );
	for( int i = 0; i < 11; ++i )
	{
		for( int j = 0; j < 8; ++j )
		{
			window.draw( *tiles[i][j].getImage() );
		}
	}
}

void GameWindow::draw( sf::Drawable* drawable)
{
	window.draw( *drawable );	
}

void GameWindow::display()
{
	window.display();
}