#ifndef SETUP_H_
#define SETUP_H_

#include "structures.h"
#include "cardstack.h"

gameInfo* initGameInfo(int playerCount);

gameInfo* defineGameInfo();
void initPlayerInfo(gameInfo* gI);

Card** makeDeck();
Deck* shuffleDeck(Card**);
void deal(gameInfo* gI);

#endif // SETUP_H_
