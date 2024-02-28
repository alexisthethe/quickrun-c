#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "decision.h"

#ifdef _WIN32
    #define OS "nt"
#elif __unix__ || __APPLE__
    #define OS "posix"
#endif 


bool decision(char *x, char *o, unsigned char *u1)
{
    char dec;
    printf("\n\n");
    do {
        printf("Player1 %s choose the X or 0:",u1);
        dec=getchar();
        scanf("%c", &dec);
    } while(dec!='X' && dec!='x' && dec!='0');
    if (dec=='X' || dec=='x') {
        *x='X';
        *o='0';
    }
    else {
        *x='0';
        *o='X';
    }
    return 1;
}