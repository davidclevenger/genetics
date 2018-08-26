#include "darwin.h"

#define POP_SIZE 10000
#define NUM_GENES 100

// function stub (unused, but required)
double fitness(Individual* ind)
{
	return get_gene(ind, 0); // silence unused parameter warning
}

int main()
{
	int i;
	Population p;
	init(&p, POP_SIZE, NUM_GENES, FIT_MAX);
	
	for(i = 0; i < POP_SIZE; i++)
	{
		setup(p.pop[i]);
	}

	deinit(&p);

	return 0;
}
