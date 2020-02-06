#ifndef GAME_H
#define GAME_H
#include "structs.h"

class Game
{
public:
	enum State
	{
		NONE,
		CLAIMING,
		PLAYING,
		END
	};
	CardSet playCardset[3];
	CardSet landlordCard;
public:
	Game();
	~Game();
	void shuffle();

};

#endif