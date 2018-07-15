#include "darwin.h"

void init(Population* p, int _num_pop, int _num_genes)
{
	int i;

	srand(time(NULL));

	if(_num_pop <= 0 || _num_genes <= 0)
	{
		printf("Error: (init) - invalid parameters\n");
		return;
	}

	p->pop				= NULL;
	p->total_fitness 	= 0.0;
	p->num_pop 			= _num_pop;
	p->num_genes 		= _num_genes;

	if(p->num_genes % 8 == 0) //well aligned
	{
		p->mem_needed = ( p->num_genes >> 3 ) * p->num_pop;
	}
	else
	{
		p->mem_needed = (( p->num_genes + 8 ) >> 3) * p->num_pop;
	}

	p->pop = (Individual**)malloc((p->num_pop) * sizeof(Individual*));
	if(p->pop == NULL)
	{
		fprintf(stderr, "Malloc failure: (init)\n");
		return;
	}

	for(i = 0; i < p->num_pop; i++)
	{
		p->pop[i] = NULL;
		p->pop[i] = (Individual*)malloc(sizeof(Individual));
		if(p->pop[i] == NULL)
		{
			fprintf(stderr, "Malloc error: (init)\n");
			return;
		}
	}

	generate(p);
}

void deinit(Population* p)
{
	int i;
	for(i = 0; i < p->num_pop; i++)
	{
		if(p->pop[i] != NULL)
		{
			individual_deinit(p->pop[i]);
			free(p->pop[i]);
		}
	}

	if(p->pop != NULL)
	{
		free(p->pop);
	}
}

void generate(Population* p)
{
	int i;
	for(i = 0; i < p->num_pop; i++)
	{
		individual_init(p->pop[i], p->num_genes);
	}
}

void sortPop(Population* p)
{
	bsort(p);
}

#define TRUE 1
#define FALSE 0

void bsort(Population* p)
{
	int i, sorted;
	Individual tmp;
	sorted = TRUE;

	while(!sorted)
	{
	sorted = TRUE;
		for(i = 0; i < p->num_pop-1; i++)
		{
			if(cmp(p->pop[i], p->pop[i+1]) == -1)
			{
				tmp = *(p->pop[i]);
				*(p->pop[i+1]) = *(p->pop[i]);
				*(p->pop[i+1]) = tmp;
				sorted = FALSE;
			}
		}
	}
}

#undef TRUE
#undef FALSE

