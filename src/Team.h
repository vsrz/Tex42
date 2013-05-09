/**
 *	Extends a player collection to hold marks, dominoes won,
 *  and members of a team
 */

#ifndef TEAM_H
#define TEAM_H

#pragma once
#include "Player.h"
#include "DominoCollection.h"

class Team
{
private:
	Player *player[2];
	int marks;

public:
    DominoCollection dominoes;
	
    Team(void);
	~Team(void);

	int getMarks( void );
	void addMarks( int marks = 0 );
	void addPlayer( Player* player );
	bool contains( Player* player );
    void removePlayer( int playerIndex );

};

#endif
