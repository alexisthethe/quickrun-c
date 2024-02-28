#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "board.h"

#ifdef _WIN32
    #define OS "nt"
#elif __unix__ || __APPLE__
    #define OS "posix"
#endif 

void board(char x, char o, unsigned char *u1, unsigned char *u2, char *a)
{
    int i;
    if (OS=="nt")
        system("cls");
    if (OS=="posix")
        system("clear");
    printf("\tTic-Tac-Toe\n\n");
        printf("\n\n");
        printf("%s:- (%c)\n%s:-  (%c)\n\n\n",u1,x,u2,o);

        printf("  %c |  %c | %c\n",a[0],a[1],a[2]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("    |    |    \n");
        printf("  %c |  %c | %c\n",a[3],a[4],a[5]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("  %c |  %c | %c\n",a[6],a[7],a[8]);
        printf("    |    |    \n");
    }