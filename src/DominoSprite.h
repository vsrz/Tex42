
#ifndef DOMINOSPRITE_H
#define DOMINOSPRITE_H

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Domino.h"

class DominoSprite : public sf::Sprite
{
private:
	sf::Texture texture;
	bool loaded;
public:
	DominoSprite(void);
	~DominoSprite(void);
	
	
	bool isLoaded( void );
	
	void loadTexture( std::string filepath );
	void setSize( sf::Uint32 x, sf::Uint32 y );
	void setSize( sf::Vector2u size );
	void setDomino( Domino domino );
	
	void setOrientationHorizontal( bool horizontal );
};

#endif
