#include "darwin.h"

#define POP_SIZE 20
#define NUM_GENES 10

int main()
{
	int i;
	Population p;
	init(&p, POP_SIZE, NUM_GENES);
	for(i = 0; i < POP_SIZE; i++)
	{
		setup(p.pop[i]);
		print(p.pop[i]);
		printf("%f\n", fitness(p.pop[i]));
	}
	
	evolve(&p);

	for(i = 0; i < POP_SIZE; i++)
	{
		printf("%f\n", fitness(p.pop[i]));
	}

	deinit(&p);
}
