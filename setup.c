#include "setup.h"

gameInfo* defineGameInfo() // this is the function that asks the user for information for the game ( players, name, difficulty, etc. )
{
    puts("Enter your name");
    char* playerName = getUserString(100);

    puts("Enter computer count (1-5)");
    int playerCount = getUserInteger();
    while (  playerCount < 1 || playerCount > 5 )
    {
        puts("Invalid; must be between 1 and 5");
        playerCount = getUserInteger();
    }

    //puts("Enter difficulty");

    gameInfo* gI = initGameInfo(playerCount);

    gI->players[0].name =  playerName;

    return gI;
}
gameInfo* initGameInfo(int playerCount) //this is the setup of the information which gets passed through the game over and over
{
    gameInfo* gI = malloc(sizeof(gI));

    gI->players = malloc(sizeof(Player)*(playerCount+1)); //creates an array of playerCount length
    gI->playerCount = playerCount+1; // storing player count
    gI->difficulty = 0; // RIGHT NOW assuming easy mode
    gI->phaseValue = 1; // start on round 1

    srand(time(NULL));
    gI->turn = rand()%playerCount; // randomly decides who goes first

    /* DECK INFORMATION */
    gI->tableFaceDownDeck = shuffleDeck(makeDeck());
    gI->tableFaceUpDeck = NULL;

    /* INITIALIZING PLAYER INFORMATION */
    initPlayerInfo(gI);

    /* DEALING CARDS TO ALL PLAYERS */
    deal(gI);

    /* DRAWING FIRST FACE-UP CARD */
    Card* firstFaceUp = pop(gI->tableFaceDownDeck);
    push(gI->tableFaceUpDeck, firstFaceUp);


    if ( gI != NULL && gI->players != NULL)
    {
        return gI;
    }
    else
    {
        puts("malloc error");
        return NULL;
    }
}

void initPlayerInfo(gameInfo* gI)
{
    for ( int i = 0 ; i < gI->playerCount ; i++ ) // for all players...
    {
        Player currentPlayer = gI->players[i]; // current player to modify

        if ( i != 0 ) // for all computers (name changing purposes)
        {
            sscanf(currentPlayer.name, "Computer %d", &i);
        }

        /* initializing all variables of all players */
        currentPlayer.faceDownDeck = NULL;
        currentPlayer.faceDownDeckCount = 10;
        currentPlayer.faceUpDeck = NULL;
        currentPlayer.phaseValue = 1;
        currentPlayer.points = 0;
    }
}

Card** makeDeck()
{
    Card** deck = malloc(sizeof(Card*)*108); //108 is the amount of cards in a normal Phase 10 deck

    int cardCounter = 1; // this helps to number all the cards from 1 - 12

    for ( int i = 0 ; i < 108 ; i++ )
    {
        deck[i] = malloc(sizeof(Card)); // creating all the cards

        if ( i%24 == 0 ) // when transitioning to another color, change cardCounter to 1
        {
            cardCounter = 1;
        }
        if ( i < 24 ) // initializing the BLUE cards
        {
            deck[i]->color = 1; // making the cards blue
            deck[i]->number = cardCounter;
            cardCounter = cardCounter + i%2;
        }
        else if ( i > 23 && i < 48 ) // initializing the GREEN cards
        {
            deck[i]->color = 2;
            deck[i]->number = cardCounter;
            cardCounter = cardCounter + i%2;
        }
        else if ( i > 47 && i < 72 ) // initializing the RED cards
        {
            deck[i]->color = 3; // making the cards red
            deck[i]->number = cardCounter;
            cardCounter = cardCounter + i%2;
        }
        else if ( i > 71 && i < 96 ) // initializing the YELLOW cards
        {
            deck[i]->color = 4;
            deck[i]->number = cardCounter;
            cardCounter = cardCounter + i%2;
        }
        // initializing the "black" cards ( skips and wilds )
        else if ( i > 95 && i < 104 ) // initializing the WILD cards
        {
            deck[i]->color = 0;
            deck[i]->number = 0;
        }
        else if ( i > 103 ) // initializing the SKIPS
        {
            deck[i]->color = 0;
            deck[i]->number = -1;
        }
    }
    return deck;
}

Deck* shuffleDeck(Card** cardArray)
// this function both shuffles the deck and also converts the data structure from an array to a stack
// the array is still in existence though for the purposes of freeing
{
    Deck* topCard = NULL;

    int dealtCards[108]; //keeps list of numbers already dealt

    for ( int i = 0 ; i < 108 ; i++ )
    {
        dealtCards[i] = 0;
    }

    srand(time(NULL));

    int nextCard = 0;

    for ( int i = 0 ; i < 108 ; i++ )
    {
        nextCard = rand()%108;
        if ( dealtCards[nextCard] != 1 ) // in the case where a new number is drawn
        {
            dealtCards[nextCard] = 1; // mark that the number has been drawn
            push(topCard, cardArray[i]);
        }
        else // when number is not new, try again
        {
            i--;
        }
    }
    return topCard;
}

void deal(gameInfo* gI)
{
    int gives = gI->playerCount*10; // giving 10 cards to each player
    Card* dealtCard = NULL;
    for ( int i = 0 ; i < gives ; i++ )
    {
        dealtCard = pop(gI->tableFaceDownDeck); // dealing a card from the face-down deck
        push(gI->players[i%gI->playerCount].faceDownDeck, dealtCard); // adding that card to the specific player's hand
    }
}
