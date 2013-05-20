
#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#pragma once
class Renderer
{
public:
	Renderer(void);
	~Renderer(void);

	virtual void draw( sf::RenderWindow & window ) = 0;

};

#endif
