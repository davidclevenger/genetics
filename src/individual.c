#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "individual.h"

#define RAND_LOW_PRECISION() ((rand() % 10000) / 10000.0)

void individual_init(Individual* ind, int _num_genes_bytes)
{
	if(ind == NULL)
	{
		return;
	}

	if( _num_genes_bytes <= 0 )
	{
		fprintf(stderr, "Invalid Paramater Error: (individual_init)\n");
		return;
	}

	ind->genes = NULL;
	ind->raw_fitness = 0;
	ind->rel_fitness = 0;
	ind->num_genes = _num_genes_bytes * 8;
	ind->block_size = _num_genes_bytes;
	
	/*
	*	Check if number of genes is well aligned with byte width.
	*	If not, add 8 to round up the next byte.
	*/

	ind->genes = (unsigned char*) malloc( ind->block_size );
	if(ind->genes == NULL)
	{
		fprintf(stderr, "Malloc error: (individual_init)\n");
		return;
	}

	memset(ind->genes, 0, ind->block_size); // zero out block
}

void individual_deinit(Individual* ind)
{
	if( ind->genes != NULL )
	{
		free(ind->genes);
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
		fprintf(stderr, "Parameter Error: (get_gene)\n");
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

/* get char from individual offset by *idx* bytes */
char get_char(Individual* ind, int idx)
{
    return ind->genes[idx];
}


/* get int from individual offset by *idx* bytes */
int get_int(Individual* ind, int idx)
{
    unsigned char* off_buf = ind->genes + idx;
    int* dub_buf = (int*) off_buf;
    return *dub_buf;
}

/* get double from individual offset by *idx* bytes */
double get_double(Individual* ind, int idx)
{
    unsigned char* off_buf = ind->genes + idx;
    double* dub_buf = (double*) off_buf;
    return *dub_buf;
}

/* get struct from individual offset by *idx* bytes */
void* get_struct(Individual* ind, int idx)
{
    unsigned char* off_buf = ind->genes + idx;
    return (void*) off_buf;
}

/* randomly generate an individual's genes */
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

void set_raw_fitness(Individual* ind, double fit)
{
	if(ind == NULL)
	{
		fprintf(stderr, "Error: (set_raw_fitness)\n");
		return;
	}

	ind->raw_fitness = fit;
}

void set_rel_fitness(Individual* ind, double sum)
{
	if(ind == NULL)
	{
		fprintf(stderr, "Error: (set_rel_fitness)\n");
		return;
	}

	ind->rel_fitness = ( ind->raw_fitness / sum );
}

void reset(Individual* ind)
{
	int i;
	if(ind == NULL)
	{
		fprintf(stderr, "Error: (reset)\n");
		return;
	}

	for(i = 0; i < ind->num_genes; i++)
	{
		clear_gene(ind, i);
	}
}

// TODO: Add mode paramater
void crossover(Individual* p1, Individual* p2, Individual* child)
{
	int i;
	for(int i = 0; i < (p1->num_genes / 2); i++)
	{
		if(get_gene(p1, i))
		{
			set_gene(child, i);
		}
		else
		{
			clear_gene(child, i);
		}
	}
	for(i = (p1->num_genes / 2); i < p1->num_genes; i++)
	{
		if(get_gene(p2, i))
		{
			set_gene(child, i);
		}
		else
		{
			clear_gene(child, i);
		}
	}
}

void mutate(Individual* ind, double mutation_rate)
{
	int i;
	for(i = 0; i < ind->num_genes; i++)
	{
		if( RAND_LOW_PRECISION() <= mutation_rate)
		{
			if(get_gene(ind, i))
			{
				clear_gene(ind, i);
			}
			else
			{
				set_gene(ind, i);
			}
		}
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

int cmp(const void* lhs, const void* rhs)
{
	return 0;

	double lhs_fit, rhs_fit;
	Individual* left = (Individual*)lhs;
	Individual* right = (Individual*)rhs;

	if((left == NULL) || (right == NULL))
	{
		fprintf(stderr, "Error: (cmp)\n");
		assert(0);
	}

	lhs_fit = left->rel_fitness;
	rhs_fit = right->rel_fitness;

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
