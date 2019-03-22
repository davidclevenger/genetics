#include <assert.h>
#include "darwin.h"

#define POP_SIZE 1000
#define NUM_GENES_BYTES 8

double fitness(Individual* ind)
{
  double fit = 0;
  int i;
  for(i = 0; i < ind->num_genes; i++)
  {
    fit += get_gene(ind, i);
  }
  
  return fit;
}

int main()
{
	int i;
	Population p;
	init(&p, POP_SIZE, NUM_GENES_BYTES, FIT_MAX);
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
	
	return 0;
}
