#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#define size 10
#define generations 100
#define cSusceptible 0
#define cExposed 1
#define cInfective 2
#define cRecovered 3
#define cDead 4
extern struct cell
{
    int status;
    int infectedDays;
    int exposedDays;
    int recoveredDays;
    int age;
    int chance_e_to_i;
    int chance_s_to_e;
    int chance_i_to_d;
    int chane_i_to_r;
    int infectedNeigh; // change name
} Cell;

extern int infectedCount;
extern int exposedCount;
extern int deadCount;
extern int totalDeadCount;
extern int recoveredCount;
extern int susceptibleCount;
extern int day;
extern int chance_s_to_e;
extern int chance_e_to_i;
extern int chance_i_to_r;
extern int chance_i_to_d;

// random indexes for where the initial infectives will be placed
extern int random_index_1;
extern int random_index_2;
extern int random_index_3;
extern int random_index_4;

// cell structure

extern struct cell currentWorld[size][size];
extern struct cell newWorld[size][size];
