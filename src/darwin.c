#include "darwin.h"

void init(Population* p, int _num_pop, int _num_genes)
{
	if(_num_pop <= 0 || _num_genes <= 0)
	{
		printf("Error: (init) - invalid parameters\n");
		return;
	}

	p->pop				= NULL;
	p->raw_fitness 		= NULL;
	p->rel_fitness 		= NULL;
	p->total_fitness 	= 0.0;
	p->num_pop 			= _num_pop;
	p->num_genes 		= _num_genes;

	//total_genes = (p->num_pop) * (p->num_genes);
	
	/*
	if(total_genes % 8 == 0)
	{
		p->mem_needed = total_genes >> 3; //divide by 8
	}
	else
	{
		p->mem_needed = (total_genes + 8) >> 3; //divide by 8, round up
	}
	*/

	if(p->num_genes % 8 == 0) //well aligned
	{
		p->mem_needed = ( p->num_genes >> 3 ) * p->num_pop;
	}
	else
	{
		p->mem_needed = (( p->num_genes + 8 ) >> 3) * p->num_pop;
	}

	printf("%d\n", p->mem_needed);

	p->genes = (unsigned char*)malloc((p->mem_needed) * sizeof(unsigned char));
	if(p->genes == NULL)
	{
		printf("Malloc failure.\n");
		return;
	}

	p->raw_fitness = (double*)malloc((p->num_pop) * sizeof(double));
	if(p->raw_fitness == NULL)
	{
		printf("Malloc failure.\n");
		return;
	}

	p->rel_fitness = (double*)malloc((p->num_pop) * sizeof(double));
	if(p->rel_fitness == NULL)
	{
		printf("Malloc failure.\n");
		return;
	}

	memset(p->genes, 0, p->mem_needed * sizeof(unsigned char)); //zero out entire block
	memset(p->raw_fitness, 0, p->num_pop * sizeof(double));
	memset(p->rel_fitness, 0, p->num_pop * sizeof(double));
}

void deinit(Population* p)
{
	if(p->genes != NULL)
		free(p->genes);

	if(p->raw_fitness != NULL)
		free(p->raw_fitness);

	if(p->rel_fitness != NULL)
		free(p->rel_fitness);
}
