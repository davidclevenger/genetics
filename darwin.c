#include "darwin.h"

void init(Population* p, int _num_pop, int _num_genes)
{
	int total_genes;

	if(_num_pop <= 0 || _num_genes <= 0)
	{
		printf("Error: (init) - invalid parameters\n");
		return;
	}

	p->genes = NULL;
	p->raw_fitness = NULL;
	p->rel_fitness = NULL;
	p->total_fitness = 0.0;
	p->num_pop = _num_pop;
	p->num_genes = _num_genes;

	total_genes = p->num_pop * p->num_genes;
	if(total_genes % 8 == 0)
	{
		p->mem_needed = total_genes >> 3; //divide by 8
	}
	else
	{
		p->mem_needed = (total_genes + 8) >> 3;
	}

	printf("%d\n", p->mem_needed);

	p->genes = (unsigned char*)malloc(total_genes);
	if(p == NULL)
	{
		printf("Malloc failure\n");
		return;
	}

	memset(p->genes, 0, p->mem_needed * sizeof(unsigned char));

}

void deinit(Population* p)
{
	free(p->genes);
}
