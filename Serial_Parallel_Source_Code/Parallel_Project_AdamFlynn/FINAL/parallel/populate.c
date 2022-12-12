#include "header.h"

void populate(struct cell world[size][size])
{
	srand(time(0));

	int random_age;

	int i, j;

	// random indexes for where the initial infectives will be placed
	int random_index_1 = rand() % size + 1;
	int random_index_2 = rand() % size + 1;
	int random_index_3 = rand() % size + 1;
	int random_index_4 = rand() % size + 1;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			random_age = rand() % 100 + 1;

			world[i][j].status = cSusceptible;
			world[i][j].age = random_age;
			// starting off with 2 infected at the random indexes
			if (i == random_index_1 && j == random_index_2)
			{
				world[i][j].status = cInfective;
			}
			else if (i == random_index_3 && j == random_index_4)
			{
				world[i][j].status = cInfective;
			}
			else
			{
				world[i][j].status = cSusceptible;
			}
		}
	}
}