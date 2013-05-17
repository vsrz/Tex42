
#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#pragma once
class Renderer
{
private:
	sf::Sprite sprite;
	sf::Vector2f position;

public:
	Renderer(void);
	~Renderer(void);

	virtual void draw( sf::Vector2u position, sf::Vector2f scale ) = 0;
	virtual void animate( sf::Vector2u fromLocation, sf::Vector2u toLocation) = 0;

};

#endif
