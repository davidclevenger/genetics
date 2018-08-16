#include <assert.h>
#include "darwin.h"

#define POP_SIZE 1000
#define NUM_GENES 50

int main()
{
	int i;
	Population p;
	init(&p, POP_SIZE, NUM_GENES);
	for(i = 0; i < POP_SIZE; i++)
	{
		setup(p.pop[i]);
	}
	
	evolve(&p);
//	sortPop(&p);

	for(i = 1; i < POP_SIZE; i++)
	{
		if( fitness(p.pop[i-1]) < fitness(p.pop[i]) )
		{
			fprintf(stderr, "Sorting failure.\n");
			assert(0);
		}
	}

	deinit(&p);
}
