#include "header.h"
int random_index_1;
int random_index_2;
int random_index_3;
int random_index_4;
int random_index_5;
int random_index_6;
int random_index_7;
int random_index_8;
//  function to populate initial world with 8 infected, giving cells random age & random index
void populate(struct cell world[size][size])
{

	srand(time(0));

	int random_age;

	int i, j;
	random_index_1 = rand() % size + 1;
	random_index_2 = rand() % size + 1;
	random_index_3 = rand() % size + 1;
	random_index_4 = rand() % size + 1;
	random_index_5 = rand() % size + 1;
	random_index_6 = rand() % size + 1;
	random_index_7 = rand() % size + 1;
	random_index_8 = rand() % size + 1;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			random_age = rand() % 100 + 1;

			// giving cells random age
			world[i][j].age = random_age;

			// making cells susceptible
			world[i][j].status = cSusceptible;

			// starting off with 2 infected at the random indexes
			if (i == random_index_1 && j == random_index_2)
			{
				world[i][j].status = cInfective;
			}
			else if (i == random_index_3 && j == random_index_4)
			{
				world[i][j].status = cInfective;
			}
			else if (i == random_index_5 && j == random_index_6)
			{
				world[i][j].status = cInfective;
			}
			else if (i == random_index_7 && j == random_index_8)
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