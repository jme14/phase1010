#include "round.h"

void roundOfPlay(gameInfo* gI)
/* this function is called only after the game has been set up */
{
    if ( gI->turn == 0 )
    {
        // this is the player turn
        // STEP 1: show data
        // STEP 2: ask for either faceDown card or faceUp card
        // STEP 3: IF victory condition met, prompt for placing down cards
        // STEP 4: choose final card to discard
    }
    else
    {
        // this is a computer turn
        // STEP 1: determine if faceUp or faceDown is better
        // STEP 2: IF victory condition met, place down cards
        // STEP 3: determine and choose best card to discard
    }

    incrementTurn(gI);
}

void incrementTurn(gameInfo* gI)
{
    int playerCount = gI->playerCount;

    if ( gI->turn < playerCount-1 )
    {
       gI->turn++;
    }
    else
    {
        gI->turn = 0;
    }
}

char* printCardInfo(Card* card) // FREE THIS AFTER EVERY USE
{
    char* printedCardInfo = malloc(sizeof(12));

    if ( card->color != 0 )
    {
        sscanf(printedCardInfo, "|%s %d|", returnCardColorAsString(card), &card->number); //weirdness
    }
    else
    {
        if ( card->number == -1 )
        {
            sscanf(printedCardInfo, "SKIP");
        }
        else if ( card->number == 0 )
        {
            sscanf(printedCardInfo, "WILD");
        }
    }
}
char* returnCardColorAsString(Card* card)
{
    char* colorName = NULL;

    if ( card->color == 1 )
    {
       colorName = "Blue";
    }
    else if ( card->color == 2 )
    {
        colorName = "Green";
    }
    else if ( card->color == 3 )
    {
        colorName = "Red";
    }
    else if ( card->color == 4 )
    {
        colorName = "Yellow";
    }
    else
    {
        puts("ERROR: invalid color");
        exit(0);
    }
    return colorName;
}
void playerScreen(gameInfo* gI)
{
    /* PRINTING THE TABLE DECK */
    puts("-----------------------------------------------------------");
    char* cardPrinter = printCardInfo(peek(gI->tableFaceUpDeck));
    printf("Face Down: X | Face Up: %s ", cardPrinter);

    /* PRINTING THE CARD COUNTS OF OTHER PLAYERS */
    puts("-----------------------------------------------------------");
    for ( int i = 1 ; i < gI->playerCount ; i++ )
    {
        Player currentPlayer = gI->players[i];
        printf(" %s: %d cards |", currentPlayer.name, currentPlayer.faceDownDeckCount);
    }

    /* PRINTING A LIST OF FACE UP CARDS */
    puts("-----------------------------------------------------------");
    puts("PLAYER | SEQUENCE");


}
