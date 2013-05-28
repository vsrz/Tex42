#include "GameWindow.h"
#include "RandomNumberGenerator.h"

GameWindow::GameWindow(void)
{
	window.create( sf::VideoMode( 1024, 768 ), "Tex42" );
	window.setVerticalSyncEnabled( true );

}


GameWindow::~GameWindow(void)
{
}

void GameWindow::draw( void )
{
	update();
	display();
}

void GameWindow::update()
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

