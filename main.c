/*
This code has been compiled in Code::Blocks 16.01 IDE on Windows 10
Author:- Mishal Shah
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "board.h"
#include "rules.h"
#include "decision.h"
#include "checkforwin.h"

#ifdef _WIN32
#define OS "nt"
#elif __unix__ || __APPLE__
#define OS "posix"
#endif
#define TRUE 1
#define FALSE 0

bool decision(char *x, char *o, unsigned char *u1); // points player to mark X or mark 0
int main()
{
    FILE *p;
    char x, o;
    p = fopen("score.txt", "a+");
    fclose(p);
    char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char u1[50], u2[50];
    int player = 1;
    int choice, score = -1;
    char symbol, re;
    char start, dec;
    int s;
    if (OS == "nt")
        system("color 09");
    rules();
    printf("\n\nType 1 to start the game:-\nType 2 to view leader board:-\n");
    scanf("%d", &s);
    switch (s)
    {
    case 1:
        do
        {
            p = fopen("score.txt", "a+");
            printf("\nEnter name of player1: ");
            scanf("%s", u1);
            fprintf(p, "\n%s", u1);
            printf("Enter name of player2: ");
            scanf("%s", u2);
            fprintf(p, "\t%s", u2);
            fclose(p);
            !strcmp(u1, u2) ? printf("Enter names of different players!\n\n") : FALSE;
        } while (!strcmp(u1, u2));
        decision(&x, &o, u1);
        if (OS == "nt")
            system("color fc");
        board(x, o, u1, u2, a);
        do
        {
            player = ((player % 2) ? 1 : 2);
            if (player == 1)
                printf("%s Type any digit from 1-9 to fill your response:- ", u1);
            else
                printf("%s Type any digit from 1-9 to fill your response:- ", u2);
            scanf("%d", &choice);
            symbol = ((player == 1) ? x : o);
            if (choice == 1 && a[0] == '1')
                a[0] = symbol;
            else if (choice == 2 && a[1] == '2')
                a[1] = symbol;
            else if (choice == 3 && a[2] == '3')
                a[2] = symbol;
            else if (choice == 4 && a[3] == '4')
                a[3] = symbol;
            else if (choice == 5 && a[4] == '5')
                a[4] = symbol;
            else if (choice == 6 && a[5] == '6')
                a[5] = symbol;
            else if (choice == 7 && a[6] == '7')
                a[6] = symbol;
            else if (choice == 8 && a[7] == '8')
                a[7] = symbol;
            else if (choice == 9 && a[8] == '9')
                a[8] = symbol;
            else
            {
                printf("Wrong Selection\n");
                player--;
            }
            score = checkforwin(a);
            player++;
            board(x, o, u1, u2, a);
        } while (score == -1);
        p = fopen("score.txt", "a+");
        if (score == 1)
        {
            if (player == 2)
            {
                printf("\n\nPlayer1 %s Wins!\n\n", u1);
                fprintf(p, "\t%s", u1);
                getchar();
            }
            else
            {
                printf("\n\nPlayer2 %s Wins!\n\n", u2);
                fprintf(p, "\t%s", u2);
                getchar();
            }
            fclose(p);
        }
        else
        {
            printf("\n\nGame Draws!\n\n");
            fprintf(p, "\t%s", "DRAW");
            getchar();
        }
        break;
    case 2:
        if (OS == "nt")
            system("cls");
        if (OS == "posix")
            system("clear");
        printf("\n\n");
        printf("\tLEADERBOARD\n\n");
        char c;
        p = fopen("score.txt", "r");
        while ((c = getc(p)) != EOF)
        {
            printf("%c", c);
        }
        fclose(p);
        getchar();
        break;
    default:
        printf("\n\nShould have typed 1 to play the game!\nHope to see you back soon!\n\n");
        getchar();
        break;
    }
}
