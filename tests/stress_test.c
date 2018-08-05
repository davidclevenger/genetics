#include "darwin.h"

#define POP_SIZE 10000
#define NUM_GENES 100

int main()
{
	int i;
	Population p;
	init(&p, POP_SIZE, NUM_GENES);
	
	for(i = 0; i < POP_SIZE; i++)
	{
		setup(p.pop[i]);
	}

	deinit(&p);
}
