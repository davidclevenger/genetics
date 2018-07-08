#include "individual.h"

void individual_init(Individual* ind, int _num_genes)
{
	if(ind == NULL)
	{
		return;
	}
	if(_num_genes <= 0)
	{
		fprintf(stderr, "Invalid Paramater Error: (individual_init)\n");
		return;
	}

	ind->genes = NULL;
	ind->raw_fitness = 0;
	ind->rel_fitness = 0;
	ind->num_genes = _num_genes;
	ind->block_size = 0;
	
	/*
	*	Check if number of genes is well aligned with byte width.
	*	If not, add 8 to round up the next byte.
	*/
	if(ind->num_genes % 8 == 0)
	{
		ind->block_size = (ind->num_genes) >> 3;
	}
	else
	{
		ind->block_size = ((ind->num_genes) + 8) >> 3;
	}

	ind->genes = (unsigned char*)malloc(ind->block_size);
	if(ind->genes == NULL)
	{
		fprintf(stderr, "Malloc error: (individual_init)\n");
		return;
	}

	memset(ind->genes, 0, ind->block_size); // zero out block
}

void individual_deinit(Individual* ind)
{
	if(ind->genes != NULL)
	{
		free(ind->genes);
	}
}
