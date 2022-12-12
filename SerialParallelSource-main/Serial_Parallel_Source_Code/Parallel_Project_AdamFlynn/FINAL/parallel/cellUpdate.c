// 1. If cell is healthy & infected neighbors is 1, cell has 'x'% chance of exposed / 2 =% / 3 = % / 4 = 100%.
// 2. If cell is exposed & age is 12 - 40, cell has 'x'% chance of becomming infected - age 40-64 is 'x' % - 70 and above is 'x' %.
// 3. If cell is infected & age is 12 - 30, cell has 'x' % chance of recovering - age 40-64 is 'x' % - 70 and above is 'x' %. if not recovered, cell is dead.
// 4. If cell has been infected before and is now healthy, will have immunity for 60 days - maybe something else to this. (vaccine thing)
#include "header.h"
#include "functions.h"
int chance_s_to_e;
int chance_e_to_i;
int chance_i_to_r;
int chance_i_to_d;
struct cell currentWorld[size][size];
struct cell newWorld[size][size];
void *cellUpdate(void *var)
{
	// getthing thread in variable for use in loop
	long threadID = (intptr_t)var;

	// get each section of the loop for each thread to use
	int rowsPerThread = ((size * size) / TOTAL_THREADS) * threadID;

	while (day < generations)
	{
		srand(time(0));

		for (int i = rowsPerThread; i < size; i++)
		{

			for (int j = rowsPerThread; j < size; j++)
			{

				// calculate random chance every generation
				chance_s_to_e = rand() % 100 + 1;
				chance_e_to_i = rand() % 100 + 1;
				chance_i_to_d = rand() % 200 + 1;
				chance_i_to_r = rand() % 100 + 1;

				// make infected neighbors 0 for each cell at the start
				currentWorld[i][j].infectedNeigh = 0;

				// putting neighbors in variable for easier readability (boundary conditions)
				int left_neighbor = currentWorld[i][((j - 1) + size) % size].status;
				int right_neighbor = currentWorld[i][((j + 1) + size) % size].status;
				int above_neighbor = currentWorld[((i + 1) + size) % size][j].status;
				int below_neighbor = currentWorld[((i - 1) + size) % size][j].status;

				// If cell is infected, cell stays infected for at least 20 days
				if (currentWorld[i][j].status == cInfective && currentWorld[i][j].infectedDays < 20)
				{
					newWorld[i][j].status = cInfective;
				}
				// If cell is recovered, make recovered for 40 days
				if (currentWorld[i][j].status == cRecovered && currentWorld[i][j].recoveredDays < 40)
				{
					newWorld[i][j].status = cRecovered;
				}

				// If cell is dead, make dead in the new world
				if (currentWorld[i][j].status == cDead)
				{
					newWorld[i][j].status = cDead;
				}

				//-----The below if statements check amount of days cells spend in a state----------//

				// recovered days
				if (currentWorld[i][j].status == cRecovered)
				{
					currentWorld[i][j].recoveredDays++;
				}
				// exposed days
				if (currentWorld[i][j].status == cExposed)
				{
					currentWorld[i][j].exposedDays++;
				}
				// infected days
				if (currentWorld[i][j].status == cInfective)
				{
					currentWorld[i][j].infectedDays++;
				}

				//-----The below if statements check amount of infected neighbors a cell has----------//

				if (currentWorld[i][j].status == cSusceptible)
				{
					if (left_neighbor == cInfective)
					{
						currentWorld[i][j].infectedNeigh++;
					}
					else if (right_neighbor == cInfective)
					{
						currentWorld[i][j].infectedNeigh++;
					}
					else if (above_neighbor == cInfective)
					{
						currentWorld[i][j].infectedNeigh++;
					}
					else if (below_neighbor == cInfective)
					{
						currentWorld[i][j].infectedNeigh++;
					}
				}

				//-----The below if statements check amount of infected neighbors between 1-4 and applies different chance of becomming exposed based on number----------//

				// If infected neighbors = 1, cell has 25% chance
				if (currentWorld[i][j].infectedNeigh == 1 && currentWorld[i][j].status == cSusceptible)
				{
					if (chance_s_to_e < 45)
					{
						newWorld[i][j].status = cExposed;
					}
				}
				// If 2, 50% chance
				if (currentWorld[i][j].infectedNeigh == 2 && currentWorld[i][j].status == cSusceptible)
				{
					if (chance_s_to_e < 65)
					{
						newWorld[i][j].status = cExposed;
					}
				}
				// If 3, 80% chance
				if (currentWorld[i][j].infectedNeigh == 3 && currentWorld[i][j].status == cSusceptible)
				{
					if (chance_s_to_e < 90)
					{
						newWorld[i][j].status = cExposed;
					}
				}
				// If 4 = 100% chance
				if (currentWorld[i][j].infectedNeigh == 4 && currentWorld[i][j].status == cSusceptible)
				{
					newWorld[i][j].status = cExposed;
				}

				//-----The below if statements check age of exposed cells and gives chance of becomming infected based on number----------//

				// if 12 - 40, 75% chance
				if (currentWorld[i][j].status == cExposed && currentWorld[i][j].exposedDays > 7 && currentWorld[i][j].age > 11 && currentWorld[i][j].age < 41)
				{
					if (chance_e_to_i < 85)
					{
						newWorld[i][j].status = cInfective;
					}
				}
				// if 40 - 70, 85% chance
				if (currentWorld[i][j].status == cExposed && currentWorld[i][j].exposedDays > 7 && currentWorld[i][j].age > 40 && currentWorld[i][j].age < 71)
				{
					if (chance_e_to_i < 95)
					{
						newWorld[i][j].status = cInfective;
					}
				}
				// if age > 70, 100% chance
				if (currentWorld[i][j].status == cExposed && currentWorld[i][j].exposedDays > 7 && currentWorld[i][j].age > 70)
				{
					newWorld[i][j].status = cInfective;
				}

				//-----The below if statements check age of infected cells and applies different chance of recovering / or passing based on number----------//

				// if age is 12-40, 97% chance of recovery, 3% chance of death
				if (currentWorld[i][j].status == cInfective && currentWorld[i][j].infectedDays > 20 && currentWorld[i][j].age > 11 && currentWorld[i][j].age < 41)
				{
					if (chance_i_to_r < 95)
					{
						newWorld[i][j].status = cRecovered;
					}
					else if (chance_i_to_d < 5)
					{
						newWorld[i][j].status = cDead;
					}
				}
				// if age is 41-70, 93% chance of recovery, 7% chance of death.
				if (currentWorld[i][j].status == cInfective && currentWorld[i][j].infectedDays > 20 && currentWorld[i][j].age > 40 && currentWorld[i][j].age < 71)
				{
					if (chance_i_to_r < 92)
					{
						newWorld[i][j].status = cRecovered;
					}
					else if (chance_i_to_d < 8)
					{
						newWorld[i][j].status = cDead;
					}
				}

				// if age is above 70, 90% chance of recovery, 10% chance of death.
				if (currentWorld[i][j].status == cInfective && currentWorld[i][j].infectedDays > 20 && currentWorld[i][j].age > 71)
				{
					if (chance_i_to_r < 90)
					{
						newWorld[i][j].status = cRecovered;
					}
					else if (chance_i_to_d < 10)
					{
						newWorld[i][j].status = cDead;
					}
				}

				// if cell is recovoered and has been for over 40 days, return to susceptible
				if (currentWorld[i][j].status == cRecovered && currentWorld[i][j].recoveredDays > 40)
				{
					newWorld[i][j].status = cSusceptible;
				}

			} // end of i loop
		}	  // end of j loop

		pthread_mutex_lock(&mutex);

		counter++;

		if (counter == TOTAL_THREADS)
		{

			counter = 0;

			printf("\nDay %d - \n", day);
			//  printing world to console
			//	printWorld(newWorld);
			//  printing generation to file
			genToFile(currentWorld);
			//  printing stats/data to file
			statToFile(currentWorld);
			//   overwriting new world with current world
			overwriteCurrent(currentWorld, newWorld);
			// broadcasting all threads to leave busy waiting
			pthread_cond_broadcast(&con);

			day++;
		}
		else
		{
			while (pthread_cond_wait(&con, &mutex) != 0)
				;
		}

		pthread_mutex_unlock(&mutex);

	} // end of whille

} // end of thread function
