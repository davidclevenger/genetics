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
	deinit(&p);

	return 0;
}
