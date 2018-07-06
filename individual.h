#ifndef __INDIVIDUAL_H__
#define __INDIVIDUAL_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	unsigned char* genes
	double raw_fitness;
	double rel_fitness;
	int num_genes;
	int block_size;

} Individual

void individual_init(Individual*, int) // ind, _num_genes
void individual_deinit(Individual*) // ind

#endif

