#include "header.h"

void overwriteCurrent(struct cell WORLD_A[size][size], struct cell WORLD_B[size][size])
{

	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j < size; j++)
		{
			WORLD_A[i][j].status = WORLD_B[i][j].status;
		}
	}
}