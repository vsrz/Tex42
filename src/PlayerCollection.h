
#ifndef PLAYERCOLLECTION_H
#define PLAYERCOLLECTION_H

#include "PlayerAI.h"
#include "Team.h"
#include <vector>

#pragma once
class PlayerCollection
{
private:
    int turn;
	Team team[2];

protected:
    std::vector<Player*> players;
    int indexOf( Player *player );

public:
    PlayerCollection(void);
    ~PlayerCollection(void);

    void addPlayer( Player *player );
    Player* nextPlayer( void );
	Player* getNextPlayer( void );
	Player* getCurrentPlayer( void );
    void setNextPlayer( Player *player );

	int playerCount( void );
    bool contains( Player *player );

    Player* operator [] ( const int index );
};

#endif
