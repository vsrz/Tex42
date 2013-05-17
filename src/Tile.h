
#ifndef TILE_H
#define TILE_H

#pragma once

#include <SFML/Graphics.hpp>

class Tile
{
private:
	sf::Texture texture;
	sf::RectangleShape shape;

public:
	Tile(void);
	~Tile(void);
	
	void setColor( sf::Color color );
	void setSize( sf::Vector2f size );
	void setPosition( sf::Vector2f position );
	sf::Drawable* getImage();

};

#endif
