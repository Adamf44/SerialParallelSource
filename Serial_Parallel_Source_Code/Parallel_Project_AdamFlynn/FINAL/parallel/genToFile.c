#include "header.h"
void genToFile(struct cell ar[size][size])
{

    FILE *genFile;

    genFile = fopen("parallel_generations.txt", "ab");
    fprintf(genFile, "------------------------------ \n");
    fprintf(genFile, "Day: %d", day);
    fprintf(genFile, "\n");
    fprintf(genFile, "------------------------------ \n");

    // loop for each generation
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {

            fprintf(genFile, "%3d", ar[i][j].status);
        }

        fprintf(genFile, "\n");
    }
    fprintf(genFile, "\n");

    fclose(genFile);
}
