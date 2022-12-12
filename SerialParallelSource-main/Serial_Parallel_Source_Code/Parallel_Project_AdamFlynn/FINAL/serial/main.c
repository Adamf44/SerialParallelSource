// Adam Flynn - b00134787
#include "header.h"
#include "functions.h"
struct cell currentWorld[size][size];
struct cell newWorld[size][size];
int day;
int main()
{

	// clock for timing program
	clock_t tStart = clock();

	// populating initial array
	populate(currentWorld);

	// looping through generations and calling functions
	for (int i = 0; i < generations; i++)
	{
		printf("\nDAY: %d - \n", day);
		//  printing world to console
		//	printWorld(currentWorld);
		//  writing gen to file
		genToFile(currentWorld);
		//  writing stats/data to file
		statToFile(currentWorld);
		//  updating current world
		cellUpdate(currentWorld);
		// overwiriting new world with current world
		overwriteWorld(currentWorld, newWorld);
		day++;
	}

	printf("\nTime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}
