
#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TextRenderer
{

private:
	sf::Text text;
	sf::Font font;

public:
	TextRenderer(void);
	~TextRenderer(void);

	void loadFont( std::string filepath );
	void setSize( sf::Uint32 size );
	void setPosition( sf::Vector2f position );
	void setPosition( float x, float y );
	void setText( std::string );
	sf::Text* getText( void );
};

#endif
