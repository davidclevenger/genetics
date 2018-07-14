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

void setup(Individual* ind)
{
	int raw_idx, proc_idx, block_idx;
	if(ind == NULL)
	{
		fprintf(stderr, "Error: (setup)\n");
		return;
	}

	for(raw_idx = 0; raw_idx < ind->num_genes; raw_idx++)
	{
		proc_idx = raw_idx % 8;
		block_idx = raw_idx / 8;

		ind->genes[block_idx] |= ( (rand() % 2) << (7 - proc_idx) ); // TODO: will need to revisit this
	}
}

void set_gene(Individual* ind, int raw_idx)
{
	int proc_idx, block_idx;
	if(ind == NULL)
	{
		fprintf(stderr, "Error: (set_gene)\n");
		return;
	}

	proc_idx = raw_idx % 8;
	block_idx = raw_idx / 8;

	if((block_idx >= ind->block_size) || (raw_idx >= ind->num_genes) || (raw_idx < 0))
	{
		fprintf(stderr, "Parameter Error: (set_gene)\n");
		return;
	}
	
	ind->genes[block_idx] |= ( 1 << (7 - proc_idx) );
}

void clear_gene(Individual* ind, int raw_idx)
{
	int proc_idx, block_idx;
	if(ind == NULL)
	{
		fprintf(stderr, "Error: (clear_gene)\n");
		return;
	}
	proc_idx = raw_idx % 8;
	block_idx = raw_idx / 8;

	if((block_idx >= ind->block_size) || (raw_idx >= ind->num_genes) || (raw_idx < 0))
	{
		fprintf(stderr, "Parameter Error: (clear_gene)\n");
		return;
	}

	ind->genes[block_idx] &= ~(1 << (7- proc_idx));
}

int get_gene(Individual* ind, int raw_idx)
{
	int proc_idx, block_idx;
	if(ind == NULL)
	{
		fprintf(stderr, "Error: (get_gene)\n");
		return -1;
	}

	proc_idx = raw_idx % 8;
	block_idx = raw_idx / 8;

	if((block_idx >= ind->block_size) || (raw_idx >= ind->num_genes) || (raw_idx < 0))
	{
		fprintf(stderr, "Parameter Error: (get_gene) passed %d\n", raw_idx);
		return -1;
	}

	if( (ind->genes[block_idx]) & (1 << (7 - proc_idx)) )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


// arbitrary fitness function to test functionality(obj: maximize sum of genes)
double fitness(Individual* ind)
{
	double out = 0;
	int i;
	for(i = 0; i < ind->num_genes; i++)
	{
		out += get_gene(ind, i);
	}

	return out;
}

int cmp(const void* lhs, const void* rhs)
{
	double lhs_fit, rhs_fit;
	Individual* left = (Individual*)lhs;
	Individual* right = (Individual*)rhs;

	if((left == NULL) || (right == NULL))
	{
		fprintf(stderr, "Error: (cmp)\n");
		return 2; // TODO need to figure what to do with this.
	}

	lhs_fit = fitness(left);
	rhs_fit = fitness(right);

	if(lhs_fit < rhs_fit )
	{
		return -1;
	}
	else if(lhs_fit > rhs_fit)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void print(Individual* ind)
{
	int raw_idx, proc_idx, block_idx;
	if(ind == NULL)
	{
		fprintf(stderr, "Error: (print)\n");
		return;
	}

	printf("genes: ");

	for(raw_idx = 0; raw_idx < ind->num_genes; raw_idx++)
	{
		proc_idx = raw_idx % 8;
		block_idx = raw_idx / 8;
		
		if((ind->genes[block_idx]) & (1 << (7 - proc_idx)) )
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}

	printf("\n");
}

