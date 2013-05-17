
#ifndef DOMINOSPRITE_H
#define DOMINOSPRITE_H

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class DominoSprite
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	bool loaded;
public:
	DominoSprite(void);
	~DominoSprite(void);
	
	bool isLoaded( void );
	
	bool loadTexture( std::string filepath );
	bool setSize( sf::Uint32 x, sf::Uint32 y );
	bool setSize( sf::Vector2u size );

	bool setPosition( float x, float y );
	bool setPosition( sf::Vector2f position );

	bool setOrientationHorizontal( bool horizontal );

	sf::Sprite* getSprite( void );
};

#endif
