#include "header.h"

// function to print world to console
void printWorld(struct cell world[size][size])
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%2d", world[i][j].status);
        }

        printf("\n");
    }
}