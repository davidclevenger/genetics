#ifndef __INDIVIDUAL_H__
#define __INDIVIDUAL_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	unsigned char* genes;
	double raw_fitness;
	double rel_fitness;
	int num_genes;
	int block_size;

} Individual;

/*
	Individual memory utility
*/

void individual_init(Individual*, int); // ind, _num_genes
void individual_deinit(Individual*); // ind
void set_gene(Individual*, int); // ind, idx
void clear_gene(Individual*, int); // ind, idx
int get_gene(Individual*, int); // ind, idx

/*
	Individual functional
*/

void setup(Individual*); // ind
double fitness(Individual*); // ind
int cmp(Individual*, Individual*); // lhs, rhs

/*
	Individual misc
*/

void print(Individual*); // genes, num_genes, block_size

#endif

