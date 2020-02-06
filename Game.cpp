#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::shuffle()
{
	CardSet cs;
	for (int j = 1; j <= 13; ++j)
		for (int i = 1; i <= 4; ++i)
			cs.push(Card(i << 4, j));
	cs.push(Card(Card::JOKER, Card::_SMALL));
	cs.push(Card(Card::JOKER, Card::_BIG));
	for (int i = 0; i < 30; ++i)
		cs.swap(rand() % 54, rand() % 54);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 17; ++j)
			playCardset[i].push(cs.getCard(i * 17 + j));
		playCardset[i].sort();
	}
	landlordCard.push(cs.getCard(51));
	landlordCard.push(cs.getCard(52));
	landlordCard.push(cs.getCard(53));
	landlordCard.sort();
}
