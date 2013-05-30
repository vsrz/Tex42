
#include "SFMLBasicTests.h"
#include "RandomNumberGenerator.h"
#include "Tile.h"
#include "GameWindow.h"
#include "PlayerRenderer.h"
#include "DominoSprite.h"
#include "TextRenderer.h"
#include "Player.h"
#include "PlayerAI.h"
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

template <typename T> std::string to_string( T value )
{
	std::ostringstream oss;
	oss << value; 
	return oss.str();
}

SFMLBasicTests::SFMLBasicTests(void)
{
	name = "SFML Basic Tests";
}


SFMLBasicTests::~SFMLBasicTests(void)
{
}

void SFMLBasicTests::RunAllTests( void )
{
	//SFMLBasicTest();
	//SFMLDrawingTest();
	//SFMLTestRun();
}

void SFMLBasicTests::SFMLBasicTest( void )
{
	name = "Basic SFML Circle Test";
	beginTest();

	sf::RenderWindow window( sf::VideoMode( 200,200 ), "SFML Test" );
	sf::CircleShape shape( 100.0f );

	shape.setFillColor( sf::Color::Green );

	window.clear();
	window.draw( shape );
	window.display();
	// sf::sleep( sf::Time( sf::seconds( 1 ) ) );
	window.clear();
	window.close();
	endTest();
}

// Loads and draws some images, using its own instance of renderwindow
void SFMLBasicTests::SFMLDrawingTest( void )
{
	name = "SFML Basic Drawing Test";
	beginTest();
	
	// Load drawing test
	sf::RenderWindow window( sf::VideoMode( 1024, 768 ), "SFML Tests", sf::Style::Titlebar );

	// Load the image
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text text, mloc;
	std::string imgfile = "res\\img\\domino_4-0.png";
	bool result;

	result = texture.loadFromFile( imgfile );
	std::cout << "Load image from disk...";
	assert( result == true );
	std::cout << " Ok." << std::endl;

	// Load font for FPS counter
	std::cout << "Load image from disk...";
	result = font.loadFromFile( "res\\fonts\\karla.ttf" );
	assert( result == true );
	text.setFont( font );
	text.setString( "FPS: 1000 ");
	text.setCharacterSize( 12 );
	text.setColor( sf::Color::White );
	std::cout << " Ok." << std::endl;

	// Mouse position
	sf::Text mpos;
	mpos.setFont( font );
	mpos.setPosition( sf::Vector2f( 0,12 ) );
	mpos.setCharacterSize( 12 );

	// Mouse location
	mloc.setFont( font );
	mloc.setPosition( sf::Vector2f( 0, 24 ) );
	mloc.setCharacterSize( 12 );

	// Draw the domino
	texture.setSmooth( true );
	sprite.setTexture( texture );
	bool domrotation = false;
	sf::Uint16 rotation = 90;
	sprite.setScale( .2f, .2f );
	sprite.setPosition( window.getSize().x * 0.5f, window.getSize().x * 0.5f );
	window.clear(sf::Color::Black);
	window.setVerticalSyncEnabled( true );
	Tile tile;

	sf::Event event;
	sf::Clock clock;
	sf::Clock timer;
	bool chpos = false;
	sf::Color bg = sf::Color::Black;
	float dx = 0, dy = 0;
	RandomNumberGenerator r;
	float lastTime = 0;
	while( window.isOpen() )
	{
		sf::Vector2i mousepos = sf::Mouse::getPosition( window );		
		sprite.setRotation( rotation );

		float curTime = clock.restart().asSeconds();
		sf::Uint16 fps = 1 / ( curTime );
		mpos.setString( "X: " + to_string( mousepos.x) + " Y: " + to_string(mousepos.y ) );
		if( (sf::Uint32) timer.getElapsedTime().asSeconds() == 1 )
		{
			text.setString( "FPS: " + to_string( fps ) );
			timer.restart();

		}
		if( domrotation == true )
		{
			domrotation = false;
			rotation = (rotation ==90 ? 270 : 90 );
		}

		if( (sf::Uint32) timer.getElapsedTime().asSeconds() == 1 )
		{
			
		}
		sprite.setPosition( sprite.getPosition().x + dx, sprite.getPosition().y + dy );
		
		window.draw( *tile.getImage() );
		window.draw( text );
		window.draw( sprite );	
		window.draw( mloc );
		window.draw( mpos );
		window.display();
		window.clear( bg );




		while( window.pollEvent( event ))
		{
			switch( event.type )
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if( event.key.code == sf::Keyboard::Escape)
					{
						sf::sleep(sf::Time( sf::microseconds( 100 ) ) );
					}
					if( event.key.code == sf::Keyboard::C )
					{
						float red = r.nextNumber( 255 );
						float green = r.nextNumber( 255 );
						float blue = r.nextNumber( 255 );
						bg = sf::Color( red, green, blue );						
						std::cout << "Colors: " << to_string( red ) << " " << to_string( green ) << " " << to_string( blue ) << std::endl;
					}
					if( event.key.code == sf::Keyboard::B )
					{
						bg = sf::Color::Black;
					}
					if( event.key.code == sf::Keyboard::Right )
					{
						dx = 1;
					}
					if( event.key.code == sf::Keyboard::Down)
					{
						dy = 1;
					}
					if( event.key.code == sf::Keyboard::Up )
					{
						dy = -1;
					}
					if( event.key.code == sf::Keyboard::Left )
					{
						dx = -1;
					}
					if( event.key.code == sf::Keyboard::F )
					{
						domrotation = true;
					}
					break;

				case sf::Event::KeyReleased:
					if( event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Left )
					{
						dx = 0;
					}
					if( event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down )
					{
						dy = 0;
					}
					break;
				case sf::Event::MouseWheelMoved:
					bg = sf::Color( r.nextNumber( 255 ), r.nextNumber( 255 ), r.nextNumber( 255 ) );						
					break;
				case sf::Event::MouseButtonPressed:
					mloc.setString( "X: " + to_string( mousepos.x ) + " Y: " + to_string( mousepos.y ) );
					chpos = true;
					break;
				case sf::Event::MouseButtonReleased:
					chpos = false;
					break;

			}

			lastTime = curTime;
		}
		if(chpos) sprite.setPosition( mousepos.x, mousepos.y );
	}

	window.close();
	endTest();
	
}

void SFMLBasicTests::SFMLTestRun( void )
{
	name = "SFML Test Run";
	beginTest();
	TextRenderer text;
	GameWindow g;
	PlayerAI player;
	DominoSprite domino;
	PlayerRenderer player1;
	player.setName( "Bob" );
	
	domino.loadTexture("res\\img\\domino_4-0.png");
	domino.setSize( 64, 128 );
	domino.setOrientationHorizontal( true );
	domino.setPosition( 200, 400 );
	text.setText( "Test string." );
	//g.draw();
	g.draw( &domino );
	g.draw( text.getText() );
	g.display();
	
	sf::sleep( sf::Time( sf::seconds( 5 ) ) );

	endTest();

}

