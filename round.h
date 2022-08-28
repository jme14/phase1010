#ifndef ROUND_H_
#define ROUND_H_

#include "structures.h"
#include "cardstack.h"

void roundOfPlay(gameInfo*);

void incrementTurn(gameInfo*);


char* printCardInfo(Card* card);
char* returnCardColorAsString(Card* card);

#endif // ROUND_H_
