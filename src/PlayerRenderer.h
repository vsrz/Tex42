
#ifndef PLAYERRENDERER_H
#define PLAYERRENDERER_H

#pragma once

#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "TextRenderer.h"
#include "Player.h"
class PlayerRenderer : public Renderer
{

private:
	TextRenderer name;
	Player *player;	
public:
	PlayerRenderer( void );
	PlayerRenderer( Player *player ) : player( player ) { PlayerRenderer(); }

	~PlayerRenderer( void );

	void setPlayer( Player *player );
	void draw( sf::RenderWindow * window );
	void update();

};

#endif
