//Adam Flynn - b00134787
#include "header.h"
#include "functions.h"
pthread_mutex_t mutex;
pthread_cond_t con;
pthread_t allThreads[4];
int counter;
int day;

int main()
{
	counter = 0;
	day = 0;
	// initialise mutex and condition variable
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&con, NULL);

	// clock for timing program
	clock_t tStart = clock();

	populate(currentWorld);

	// Assign eaceh thread to function.
	for (int i = 0; i < TOTAL_THREADS; i++)
	{

		pthread_create(allThreads + i, NULL, cellUpdate, NULL);
	}

	for (int i = 0; i < TOTAL_THREADS; i++)
	{
		pthread_join(allThreads[i], NULL);
	}

	pthread_cond_destroy(&con);
	pthread_mutex_destroy(&mutex);

	printf("\nTime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}
