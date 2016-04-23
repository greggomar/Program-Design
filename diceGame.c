/*  Programming Assignment: DiceGame
    Author: Greg O'Marah
    U34240613
    Program Design, Dr. Tindell
*/

// includes
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// function prototypes
int get_seed();
int roll_dice();
int play_game();

int main()
{
    int games_won = 0, games_lost = 0;
    char response = 'y';

    printf("\nWelcome to the Computer Game of Craps\n\n");

    // Generate random number seed
    srand(get_seed());

    // While loop to control game repetition until user enters 'n'
    while (tolower(response) == 'y')

    {   // Call game funtion and increment win/loss counter based on result of each round
        if (play_game())
        {
            ++games_won;
        }
        else
        {
            ++games_lost;
        }
        printf("Play again?\n\n");
        // Get one character and test for y/n response to continue game
        scanf(" %c", &response);
        // Input validation
        while(tolower(response) != 'y' && tolower(response) != 'n')
        {
            printf("Invalid entry, must be y or n\n");
            printf("Play again?\n\n");
            // Get one character if character entered was not valid
            scanf(" %c",&response);
        }
    }
    // Output results of game total wins/losses
    printf("\nWins: %d   Losses: %d\n\n",games_won,games_lost);
    return 0;
}
// Function to generate random number seed
int get_seed()
{   
    int seed = 0;
    // Prompt for and input an integer to be used with srand
    // Input validation
    printf("Please enter an integer between 1 and 30:\n");
    while (1 != scanf(" %d", &seed)) 
    {
        while((getchar()) != '\n') ;
        printf("Your entry must start with a digit; try again\n\n");
    }
    // The seed must be between 1 and 30, inclusive, and input
    // Verifcation should be done (including level0 verification)
    while (seed < 1 || seed > 30)
    {   // Input verifcation
        while((getchar()) != '\n') ; // Clear input buffer
        if (seed < 1) 
        {
            printf("Value must be at least one; try again\n\n");   
        }
        if (seed > 30)
        {
            printf("Value must be at most 30; try again\n\n");   
        }
        printf("Please enter an integer between 1 and 30:\n");
        while (1 != scanf(" %d", &seed)) 
        {
            while((getchar()) != '\n') ;
            printf("Your entry must start with a digit; try again\n\n");
        }
    }
    return seed;
}


int roll_dice()
{
    // Generates two random integers between 1 and 6,
    // Computes the sum, prints "You rolled " + the sum,
    // then returns the sum
    int roll = ((rand() % 6) + 1) + ((rand() % 6) + 1);
    printf("You rolled %d\n", roll);
    return roll;
}


int play_game()
{
    // Plays a single game of Craps:
    int point = 0;
    int sum = roll_dice();
    // After initial roll, if the result is known immediately either
    // announces win and returns 1 or announces loss and returns 0
    if(sum == 7 || sum == 11)
    {
        printf("You win!\n\n");
        return 1;
    }
    if(sum == 2 || sum == 12)
    {
        printf("You lose!\n\n");
        return 0;
    }
    // If it result is not immediate, sets the "point" and rolls
    // the dice until either 7 or the point is rolled, and then
    // announces the result and returns either 0 or 1
    point = sum;
    while(1)
    {
        int sum = roll_dice();
        if(sum == 7)
        {
            printf("You lose!\n\n");
            return 0;
        }
        if(sum == point)
        {
            printf("You win!\n\n");
            return 1;
        }
    }
}