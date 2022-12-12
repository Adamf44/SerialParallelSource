#include "header.h"

void statToFile(struct cell world[size][size])
{

    FILE *statFile;
    statFile = fopen("serial_stats.txt", "ab");

    // files for graphs
    FILE *susFile;
    susFile = fopen("sus.txt", "ab");
    FILE *expFile;
    expFile = fopen("exp.txt", "ab");
    FILE *infFile;
    infFile = fopen("inf.txt", "ab");
    FILE *deadFile;
    deadFile = fopen("dead.txt", "ab");
    FILE *recFile;
    recFile = fopen("rec.txt", "ab");

    int infectedCount = 0;
    int exposedCount = 0;
    int deadCount = 0;
    int recoveredCount = 0;
    int susceptibleCount = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (world[i][j].status == cSusceptible)
            {
                susceptibleCount++;
            }
            if (world[i][j].status == cExposed)
            {
                exposedCount++;
            }
            if (world[i][j].status == cInfective)
            {
                infectedCount++;
            }
            if (world[i][j].status == cDead)
            {
                deadCount++;
            }
            if (world[i][j].status == cRecovered)
            {
                recoveredCount++;
            }

        } // end j
    }     // end i

    // overall stats to file
    fprintf(statFile, "Susceptible: %d  Exposed: %d  Infected: %d  Recovered: %d  Dead: %d ", susceptibleCount, exposedCount, infectedCount, recoveredCount, deadCount);
    fprintf(statFile, "\n");

    // individual stats to files for graphs.
    fprintf(susFile, "%d", susceptibleCount);
    fprintf(susFile, "\n");

    fprintf(expFile, "%d", exposedCount);
    fprintf(expFile, "\n");

    fprintf(infFile, "%d", infectedCount);
    fprintf(infFile, "\n");

    fprintf(recFile, "%d", recoveredCount);
    fprintf(recFile, "\n");

    fprintf(deadFile, "%d", deadCount);
    fprintf(deadFile, "\n");

    fclose(susFile);
    fclose(expFile);
    fclose(infFile);
    fclose(deadFile);
    fclose(recFile);

    // format for printing information to console
    /*
        printf("------------------------------ \n");
        printf("Infected: %d\n", infectedCount);
        // printing amount of cells exposed
        printf("Exposed: %d\n", exposedCount);
        // printing amount of cell dead
        printf("Dead: %d\n", deadCount);
        // printing amount of cells recovered
        printf("Recovered: %d\n", recoveredCount);
        // printing amount of cells susceptible
        printf("Susceptible: %d\n", susceptibleCount);
        printf("------------------------------ \n");
        */

    // different format to print to console
    // 2.
    printf("\nSusceptible: %d  Exposed: %d  Infected: %d  Recovered: %d  Dead: %d ", susceptibleCount, exposedCount, infectedCount, recoveredCount, deadCount);

} // end function
