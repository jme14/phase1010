#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "userInput.h"

typedef struct phase1010card
// this data structure is for an individual card in the game
//
// colors are alphabetical, making it like so:
// 0 : black (the skip and wild cards)
// // wild cards are 0,0
// // skips are 0, -1
// 1 : blue
// 2 : green
// 3 : red
// 4 : yellow
{
    int color;
    int number;
} Card;


typedef struct cardstack // this is the true deck -- this will get shuffled
{
    Card* card;
    struct cardstack* next;
} Deck;

typedef struct playerInfo
{
    char* name;
    Deck* faceDownDeck; // the cards a player holds; not yet discarded
    int faceDownDeckCount; // the amount of cards a player is holding
    Deck* faceUpDeck; // the cards a player has placed down for others to play on
    int phaseValue; // this will be passed into a function and output the goal of the turn for the human player and the optimal move based on the hand for the computer
    int points;

} Player;

typedef struct gameInformation
{
    Player* players; //an array of the info of all the players
    int playerCount; //integer which stores the amount of players
    // THE HUMAN PLAYER IS ALWAYS 0
    int difficulty; // to be determined
    int phaseValue; // starts at round 1 and increments until a winner is found
    Deck* tableFaceUpDeck; // cards played ; might be best represented as a stack
    Deck* tableFaceDownDeck; // cards to be drawn from the table
    int turn; // specifies whos turn it is
} gameInfo;

#endif // STRUCTURES_H_
