#include "darwin.h"

#define POP_SIZE 1000
#define NUM_GENES 50

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
	init(&p, POP_SIZE, NUM_GENES, FIT_MAX);
	for(i = 0; i < POP_SIZE; i++)
	{
		setup(p.pop[i]);
	}
	
	evolve(&p);
	deinit(&p);

	return 0;
}
