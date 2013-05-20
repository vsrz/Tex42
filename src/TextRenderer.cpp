#include "TextRenderer.h"


TextRenderer::TextRenderer(void)
{
	font.loadFromFile( "res\\fonts\\karla.ttf" );
	text.setFont( font );
	text.setColor( sf::Color::White );
	text.setPosition( 100, 100 );
	text.setCharacterSize( 14 );
}


TextRenderer::~TextRenderer(void)
{
}

void TextRenderer::loadFont( std::string filepath )
{
	font.loadFromFile( filepath );
	text.setFont( font );
}

void TextRenderer::setSize( sf::Uint32 size )
{
	text.setCharacterSize( size );
}

void TextRenderer::setPosition( sf::Vector2f position)
{
	text.setPosition( position );
}

void TextRenderer::setText( std::string string )
{
	text.setString( string );
}

sf::Text* TextRenderer::getText( void )
{
	return &text;
}

