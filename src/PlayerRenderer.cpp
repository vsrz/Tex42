
#include "Renderer.h"
#include "Player.h"
#include "TextRenderer.h"
#include "PlayerRenderer.h"
#include "Domino.h"

PlayerRenderer::PlayerRenderer(void)
{
	player = NULL;
	seat = -1;
}


PlayerRenderer::~PlayerRenderer(void)
{
}

void PlayerRenderer::setRenderTarget( sf::RenderWindow *window )
{
	this->window = window;
}

void PlayerRenderer::draw( )
{
	if( player != NULL )
	{
		window->draw( *name.getText() );
		for( int x = 0; x < player->getHand().size(); ++x )
		{
			window->draw( hand[x] );
		}
	}
}

void PlayerRenderer::update( void )
{
	if( player != NULL )
	{
		/* load the player's name from the player object */
		this->name.setText( player->getName() );		
		/* load the dominoes that this player possesses */
		DominoCollection phand = player->getHand();
		std::cout << phand << std::endl;
		for( int x = 0; x < phand.size(); ++x )
		{
			sf::Vector2f pos( (float) window->getSize().x, (float) window->getSize().y );
			sf::Vector2f dominoSize( 0.2f,0.2f );
			sf::Vector2f textPos( (float) window->getSize().x, (float) window->getSize().y );

			/* Load the domino image */
			hand[x].setDomino( phand.getDomino( x ) );			

			/* Get the positions of the domino to display */
			if( seat % 2 == 0 )
			{				
				/* Player name position */
				textPos.x *= 0.42f;

				/* south player's dominoes */
				if( seat == 0 )
				{
					if( x > 2 )
					{					
						pos.y *= 0.85f;
						pos.x *= 0.20f;
						pos.x += (hand[x].getTexture()->getSize().y * dominoSize.x) * ( x - 2 );
					} 
					else
					{
						pos.y *= 0.73f;
						pos.x *= 0.43f;
						std::cout << hand[x].getTextureRect().width << std::endl;
						pos.x += hand[x].getTexture()->getSize().y * dominoSize.x * ( x );
					}

					textPos.y *= 0.68f;
				}
				else
				{
					/* north player's dominoes */
					dominoSize.x *= 0.75f;
					dominoSize.y *= 0.75f;

					if( x > 3 )
					{
						pos.y *= 0.05f;
						pos.x *= 0.20f;
						pos.x += (hand[x].getTexture()->getSize().y * dominoSize.x) * ( x - 2 );
					} 
					else
					{
						pos.y *= 0.13f;
						pos.x *= 0.38f;
						pos.x += hand[x].getTexture()->getSize().y * dominoSize.x * ( x );
					}					
					textPos.y *= 0.23f;
				}
			}
			else
			{
				/* east/west player's dominoes */
				dominoSize.x *= 0.75f;
				dominoSize.y *= 0.75f;
				pos.y *= 0.20f;
				pos.y += (hand[x].getTexture()->getSize().x * dominoSize.y) * x;
				
				// 5% gutter on the left side of the screen
				if( seat == 1 )
				{
					pos.x *= 0.95f;
					textPos.x *= 0.88f;
				}
				else
				{
					pos.x *= 0.15f;
					textPos.x *= 0.13f;
				}

				// offset every other domino 
				if( x % 2 == 0 )
				{
					pos.x += 15.f;
				}

				textPos.y *= 0.17f;
				
			}

			
			this->name.setPosition( textPos );
			hand[x].setPosition( pos );
			hand[x].setOrientationHorizontal( true );
			hand[x].setScale( dominoSize );
			

		}
	}
}

void PlayerRenderer::setPlayer( Player* player )
{
	this->player = player;
}

