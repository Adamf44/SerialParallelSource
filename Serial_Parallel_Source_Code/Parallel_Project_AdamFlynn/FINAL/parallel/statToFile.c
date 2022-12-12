#include "header.h"
void statToFile(struct cell ar[size][size])
{
    FILE *statFile;
    statFile = fopen("parallel_stats.txt", "ab");
    // files for graphs
    //  susceptible file
    FILE *susFile;
    susFile = fopen("sus.txt", "ab");
    // exposed file
    FILE *expFile;
    expFile = fopen("exp.txt", "ab");
    // infected file
    FILE *infFile;
    infFile = fopen("inf.txt", "ab");
    // dead file
    FILE *deadFile;
    deadFile = fopen("dead.txt", "ab");
    // recovery file
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
            if (ar[i][j].status == cSusceptible)
            {
                susceptibleCount++;
            }
            if (ar[i][j].status == cExposed)
            {
                exposedCount++;
            }
            if (ar[i][j].status == cInfective)
            {
                infectedCount++;
            }
            if (ar[i][j].status == cDead)
            {
                deadCount++;
            }
            if (ar[i][j].status == cRecovered)
            {
                recoveredCount++;
            }
        } // end j
    }     // end i

    // fprintf(statFile, "Susceptible: %d  Exposed: %d  Infected: %d  Recovered: %d  Dead: %d ", susceptibleCount, exposedCount, infectedCount, recoveredCount, deadCount);
    // fprintf(statFile, "\n");
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

    // different format of printing to console
    // 2.
    // printf("Susceptible: %d  Exposed: %d  Infected: %d  Recovered: %d  Dead: %d ", susceptibleCount, exposedCount, infectedCount, recoveredCount, deadCount);

} // end function
