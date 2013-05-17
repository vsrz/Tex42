#include "DominoSprite.h"


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


	
bool DominoSprite::loadTexture( std::string filepath )
{
	loaded = texture.loadFromFile( filepath );
	if( loaded )
		sprite.setTexture( texture );
	return loaded;
	
}

bool DominoSprite::setSize( sf::Uint32 x, sf::Uint32 y )
{
	return setSize( sf::Vector2u( x, y ) );
}

bool DominoSprite::setOrientationHorizontal( bool horizontal )
{
	sf::Uint32 angle = 0;
	if( !loaded )
	{
		return false;
	}

	if( horizontal )
	{
		angle = 90;
	}

	sprite.setRotation( angle );
	return true;
}

bool DominoSprite::setSize( sf::Vector2u size )
{
	if( !loaded )
	{
		return false;
	}
	float x, y;
	x = (float) size.x / (float) texture.getSize().x;
	y = (float) size.y / (float) texture.getSize().y;
	sprite.setScale( x, y );
	return true;

}


bool DominoSprite::setPosition( float x, float y )
{
	return setPosition( sf::Vector2f( x, y ) );
}

bool DominoSprite::setPosition( sf::Vector2f position )
{
	if( !loaded )
	{
		return false;
	}
	sprite.setPosition( position );	
	return true;

}


sf::Sprite* DominoSprite::getSprite( void )
{
	return &sprite;
}

