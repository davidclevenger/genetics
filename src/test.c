#include "darwin.h"

#define POP_SIZE 20
#define NUM_GENES 10

int main()
{
	int i; 
	Population p;
	init(&p, POP_SIZE, NUM_GENES);
	setup(p.pop[0]);
	for(i = 0; i < POP_SIZE; i++)
	{
		if( get_gene(p.pop[4], i) == 0 )
		{
			printf("%d is 0!\n", i);
		}
	}

	print(p.pop[0]);
	deinit(&p);
}
