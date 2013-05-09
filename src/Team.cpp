#include "Team.h"


Team::Team(void)
{
    player[0] = NULL;
    player[1] = NULL;
    marks = 0;
}


Team::~Team(void)
{
}

void Team::addMarks( int marks )
{
	this->marks += marks;
}

int Team::getMarks( void )
{
	return marks;
}

// Returns true if the given player is a member of this team
bool Team::contains( Player *player )
{
	return player == this->player[0] || player == this->player[1];
}

void Team::addPlayer( Player* player )
{
    if( this->player[0] == NULL ) 
	{
		this->player[0] = player;
	}
	else
	{
	    this->player[1] = player;
	}
}

void Team::removePlayer( int playerIndex )
{
    player[playerIndex] = NULL;
}

