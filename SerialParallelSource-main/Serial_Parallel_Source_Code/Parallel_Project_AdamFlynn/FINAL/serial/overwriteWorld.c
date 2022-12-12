#include "header.h"

// overwrites 2d array
void overwriteWorld(struct cell world_A[size][size], struct cell world_B[size][size])
{

	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j < size; j++)
		{

			world_A[i][j].status = world_B[i][j].status;
		}
	}
}