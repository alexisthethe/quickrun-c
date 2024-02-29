#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "rules.h"

#ifdef _WIN32
#define OS "nt"
#elif __unix__ || __APPLE__
#define OS "posix"
#endif

void rules()
{
    char link;
    printf("\tTic-Tac-Toe\n\n");
    printf("Welcome to the most played 2D game and a sort of fun using X and O\n\n");
    printf("Rules:-\n");
    printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
    printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
    printf("\n\nEnjoy the game! Be a Winner!\n\n");
    printf("For more clarifications press Y else type any other character:- ");
    scanf("%c", &link);
    if (link == 'y' || link == 'Y')
    {
        print_rules();
    }
}

void print_rules()
{
    printf("Visit http://www.wikihow.com/Play-Tic-Tac-Toe");
}