#include "Tile.h"
#include "RandomNumberGenerator.h"

Tile::Tile(void)
{
	RandomNumberGenerator r;
	shape.setSize( sf::Vector2f( 12, 20 ) );

}


Tile::~Tile(void)
{
}

void Tile::setSize( sf::Vector2f size )
{
	shape.setSize( size );
}

void Tile::setPosition( sf::Vector2f position )
{
	shape.setPosition( position );
}

void Tile::setColor( sf::Color color )
{
	shape.setOutlineColor( color ) ;
	shape.setOutlineThickness( 1.f );
	shape.setFillColor( sf::Color::Black );
}

sf::Drawable* Tile::getImage( void )
{
	return &shape;
}
