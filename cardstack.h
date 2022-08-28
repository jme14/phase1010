#ifndef CARDSTACK_H_
#define CARDSTACK_H_
#include "structures.h"

Deck* push(Deck* theDeck, Card* theCard);

Card* pop (Deck* theDeck);

Card* peek (Deck* theDeck);
#endif // CARDSTACK_H_
