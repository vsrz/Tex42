
#ifndef PLAYERRENDERER_H
#define PLAYERRENDERER_H

#pragma once

#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "TextRenderer.h"
#include "Player.h"
#include "DominoSprite.h"

class PlayerRenderer 
{

private:
	TextRenderer name;
	Player *player;	
	sf::RenderWindow *window;
	DominoSprite hand[7];
	int seat;


public:
	PlayerRenderer( void );
	PlayerRenderer( Player *player, int seat ) : player( player ), seat( seat ) 
		{ PlayerRenderer(); }
	PlayerRenderer( Player *player, int seat, sf::RenderWindow *window ) 
		: player( player ), seat( seat ), window( window ) 
		{ PlayerRenderer(); }

	~PlayerRenderer( void );

	void setRenderTarget( sf::RenderWindow *window );
	void setPlayer( Player *player );
	void draw();
	void update();

};

#endif
