#include "cardstack.h"

Deck* push(Deck* oldTopCard, Card* cardData)
{
    Deck* newTopCard = malloc(sizeof(Deck));

    newTopCard->next = oldTopCard;
    newTopCard->card = cardData;

    return newTopCard;
}

Card* pop (Deck* theDeck)
{
    Card* theCard = NULL;

    if ( theDeck != NULL )
    {
        theCard = theDeck->card; //extracting card

        Deck* holder = theDeck->next; //holding the next card on the deck
        free(theDeck); //freeing the stack node
        theDeck = holder; //changing the top to be what was previously next
    }
    return theCard;
}

Card* peek (Deck* theDeck)
    // gets data from top card without removing it from the deck
{
    return theDeck->card;
}
