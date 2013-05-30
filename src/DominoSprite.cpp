#include "DominoSprite.h"
#include "utils.h"
#include <string>

DominoSprite::DominoSprite(void)
{
	loaded = false;
}


DominoSprite::~DominoSprite(void)
{

}

bool DominoSprite::isLoaded( void )
{
	return loaded;
}


	
void DominoSprite::loadTexture( std::string filepath )
{
	loaded = texture.loadFromFile( filepath );
	if( loaded )
		setTexture( texture );
	
}

void DominoSprite::setSize( sf::Uint32 x, sf::Uint32 y )
{
	setSize( sf::Vector2u( x, y ) );
}

void DominoSprite::setOrientationHorizontal( bool horizontal )
{
	sf::Uint32 angle = 0;
	if( !loaded )
	{
		throw "DominoSprite has not been loaded";
	}

	if( horizontal )
	{
		angle = 90;
	}

	setRotation( angle );
}

void DominoSprite::setSize( sf::Vector2u size )
{
	float x, y;
	if( !loaded )
	{
		throw "DominoSprite has not been loaded";
	}

	x = (float) size.x / (float) texture.getSize().x;
	y = (float) size.y / (float) texture.getSize().y;
	setScale( sf::Vector2f( x, y ) );

}

// Loads the domino for this sprite
void DominoSprite::setDomino( Domino domino )
{
	std::string filename = "res/img/domino_" + toString(domino.getLowPip());
	filename += "-" + toString(domino.getHighPip()) + ".png";

	loadTexture( filename );
}

