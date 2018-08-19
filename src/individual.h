#ifndef __INDIVIDUAL_H__
#define __INDIVIDUAL_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define RAND_LOW_PRECISION() ((rand() % 10000) / 10000.0)

typedef struct
{
	unsigned char* genes;
	double raw_fitness;
	double rel_fitness;
	int num_genes;
	int block_size;

} Individual;

/*	Individual memory utility */

void individual_init(Individual*, int); // ind, _num_genes
void individual_deinit(Individual*); // ind
void set_gene(Individual*, int); // ind, idx
void clear_gene(Individual*, int); // ind, idx
int get_gene(Individual*, int); // ind, idx

/*	Individual functional */

void setup(Individual*); // ind
extern double fitness(Individual*); // ind
void set_raw_fitness(Individual*, double); // ind, fit
void set_rel_fitness(Individual*, double); // ind, sum
void reset(Individual*); // ind 
void crossover(Individual*, Individual*, Individual*); // p1, p2, child
void mutate(Individual*, double); // ind, mutation_rate

/*	Individual misc */

void print(Individual*); // genes, num_genes, block_size
int cmp(const void*, const void*); // lhs, rhs

#endif

