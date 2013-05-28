
#include "Renderer.h"
#include "Player.h"
#include "TextRenderer.h"
#include "PlayerRenderer.h"


PlayerRenderer::PlayerRenderer(void)
{
}


PlayerRenderer::~PlayerRenderer(void)
{
}

void PlayerRenderer::draw( sf::RenderWindow * window )
{
	window->draw( *name.getText() );
}

void PlayerRenderer::update( void )
{
	this->name.setText( player->getName() );
}

void PlayerRenderer::setPlayer( Player* player )
{
	this->player = player;
}

