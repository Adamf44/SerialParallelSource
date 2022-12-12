// 1. If cell is healthy & infected neighbors is 1, cell has 'x'% chance of exposed / 2 =% / 3 = % / 4 = 100%.
// 2. If cell is exposed & age is 12 - 40, cell has 'x'% chance of becomming infected - age 40-64 is 'x' % - 70 and above is 'x' %.
// 3. If cell is infected & age is 12 - 30, cell has 'x' % chance of recovering - age 40-64 is 'x' % - 70 and above is 'x' %. if not recovered, cell is dead.
// 4. If cell has been infected before and is now healthy, will have immunity for 60 days - maybe something else to this. (vaccine thing)
#include "header.h"
int chance_s_to_e;
int chance_e_to_i;
int chance_i_to_r;
int chance_i_to_d;
void cellUpdate(struct cell world[size][size])
{
	//  loop that searches each cell and applies rules below
	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j < size; j++)

		{
			// calculate random chance every generation
			chance_s_to_e = rand() % 100;
			chance_e_to_i = rand() % 100;
			chance_i_to_d = rand() % 100;
			chance_i_to_r = rand() % 100;

			// make infected neighbors 0 for each cell at the start
			world[i][j].infectedNeigh = 0;

			// putting neighbors in variables for easier readability (boundary conditions)
			int left_neighbor = world[i][((j - 1) + size) % size].status;
			int right_neighbor = world[i][((j + 1) + size) % size].status;
			int above_neighbor = world[((i + 1) + size) % size][j].status;
			int below_neighbor = world[((i - 1) + size) % size][j].status;

			// If cell is infected, cell stays infected for at least 20 days
			if (world[i][j].status == cInfective && world[i][j].infectedDays < 20)
			{
				newWorld[i][j].status = cInfective;
			}
			// If cell is recovered, make recovered for 40 days
			if (world[i][j].status == cRecovered && world[i][j].recoveredDays < 40)
			{
				newWorld[i][j].status = cRecovered;
			}

			// If cell is dead, make dead in the new world
			if (world[i][j].status == cDead)
			{
				newWorld[i][j].status = cDead;
			}

			//-----The below if statements check amount of days cells spend in a state----------//

			// recovered days
			if (world[i][j].status == cRecovered)
			{
				world[i][j].recoveredDays++;
			}
			// exposed days
			if (world[i][j].status == cExposed)
			{
				world[i][j].exposedDays++;
			}
			// infected days
			if (world[i][j].status == cInfective)
			{
				world[i][j].infectedDays++;
			}

			//-----The below if statements check amount of infected neighbors a cell has----------//

			if (world[i][j].status == cSusceptible)
			{
				if (left_neighbor == cInfective)
				{
					world[i][j].infectedNeigh++;
				}
				else if (right_neighbor == cInfective)
				{
					world[i][j].infectedNeigh++;
				}
				else if (above_neighbor == cInfective)
				{
					world[i][j].infectedNeigh++;
				}
				else if (below_neighbor == cInfective)
				{
					world[i][j].infectedNeigh++;
				}
			}

			//-----The below if statements check amount of infected neighbors between 1-4 and applies different chance of becomming exposed based on number----------//

			// If infected neighbors = 1, cell has 25% chance
			if (world[i][j].infectedNeigh == 1 && world[i][j].status == cSusceptible)
			{
				if (chance_s_to_e < 25)
				{
					newWorld[i][j].status = cExposed;
				}
			}
			// If 2, 50% chance
			else if (world[i][j].infectedNeigh == 2 && world[i][j].status == cSusceptible)
			{
				if (chance_s_to_e < 50)
				{
					newWorld[i][j].status = cExposed;
				}
			}
			// If 3, 80% chance
			else if (world[i][j].infectedNeigh == 3 && world[i][j].status == cSusceptible)
			{
				if (chance_s_to_e < 80)
				{
					newWorld[i][j].status = cExposed;
				}
			}
			// If 4 = 100% chance
			else if (world[i][j].infectedNeigh == 4 && world[i][j].status == cSusceptible)
			{
				newWorld[i][j].status = cExposed;
			}

			//-----The below if statements check age of exposed cells and gives chance of becomming infected based on number----------//

			// if 12 - 40, 75% chance
			if (world[i][j].status == cExposed && world[i][j].exposedDays > 7 && world[i][j].age > 11 && world[i][j].age < 41)
			{
				if (chance_e_to_i < 75)
				{
					newWorld[i][j].status = cInfective;
				}
			}
			// if 40 - 70, 85% chance
			if (world[i][j].status == cExposed && world[i][j].exposedDays > 7 && world[i][j].age > 40 && world[i][j].age < 71)
			{
				if (chance_e_to_i < 85)
				{
					newWorld[i][j].status = cInfective;
				}
			}
			// if age > 70, 100% chance
			if (world[i][j].status == cExposed && world[i][j].exposedDays > 7 && world[i][j].age > 70)
			{
				newWorld[i][j].status = cInfective;
			}

			//-----The below if statements check age of infected cells and applies different chance of recovering / or passing based on number----------//

			// if age is 12-40, 97% chance of recovery, 3% chance of death
			if (world[i][j].status == cInfective && world[i][j].infectedDays > 20 && world[i][j].age > 11 && world[i][j].age < 41)
			{
				if (chance_i_to_r < 97)
				{
					newWorld[i][j].status = cRecovered;
				}
				else
				{
					newWorld[i][j].status = cDead;
				}
			}
			// if age is 41-70, 93% chance of recovery, 7% chance of death.
			if (world[i][j].status == cInfective && world[i][j].infectedDays > 20 && world[i][j].age > 40 && world[i][j].age < 71)
			{
				if (chance_i_to_r < 93)
				{
					newWorld[i][j].status = cRecovered;
				}
				else
				{
					newWorld[i][j].status = cDead;
				}
			}

			// if age is above 70, 90% chance of recovery, 10% chance of death.
			if (world[i][j].status == cInfective && world[i][j].infectedDays > 20 && world[i][j].age > 70)
			{
				if (chance_i_to_r < 90)
				{
					newWorld[i][j].status = cRecovered;
				}
				else
				{
					newWorld[i][j].status = cDead;
				}
			}

			// if cell is recovoered and has been for over 40 days, return to susceptible (i.e give cell imunity)
			if (world[i][j].status == cRecovered && world[i][j].recoveredDays > 40)
			{
				newWorld[i][j].status = cSusceptible;
			}
		} // end of j loop
	}	  // end of i loop

} // end of function