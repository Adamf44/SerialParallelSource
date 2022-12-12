#include "header.h"

// prints 2d array of cells to file every generation
void genToFile(struct cell world[size][size])
{
    FILE *genFile;

    genFile = fopen("serial_generations.txt", "ab");
    fprintf(genFile, "Day: %d", day);
    fprintf(genFile, "\n");
    fprintf(genFile, "------------------------------ \n");

    // loop for each generation
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {

            fprintf(genFile, "%2d", world[i][j].status);
        }

        fprintf(genFile, "\n");
    }

    fprintf(genFile, "\n");

    fclose(genFile);
}
