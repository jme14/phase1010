#include "userInput.h"


int getUserInteger()
{
    int input; // return value
    char* roughInput = NULL; // what will be read into

    fgets(roughInput, 100, stdin); // taking user string

    input = strtol(roughInput, NULL, 10); // converting user string to a long integer

    return input; // returning the long integer

}
char* getUserString(int maxLength)
{
    puts("Enter now");

    char* input = NULL; // what will be read into

    fgets(input, maxLength, stdin ); // reading now...

    printf("Is %s correct? Enter 0 for NO and 1 for YES \n", input);

/* this section continues to get string until the user is happy with it  */
    if ( getUserInteger() == 1 )
    {
        return input;
    }
    else
    {
        input = getUserString(maxLength);
        return input;
    }
}
