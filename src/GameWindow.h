
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Tile.h"

class GameWindow
{

protected:
	Tile tiles[50][50];
public:
	sf::RenderWindow window;

	GameWindow(void);
	~GameWindow(void);

	void update( void );
	void draw( sf::Drawable* drawable );
	void draw( void );
	void display( void );




};

#endif
