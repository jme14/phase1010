#include "free.h"


void freeGameInfo(gameInfo* gI)
{
    free(gI->players);
    free(gI);
}

void freeCardArray(Card** deck)
{
    for ( int i = 0 ; i < 108 ; i++ )
    {
        free(deck[i]);
    }
    free(deck);
}

void freeCardStack(Deck* topCard)
{
    Card* freer;
    do
    {
        freer = pop(topCard); //pop auto frees
    }
    while ( freer != NULL );
}
