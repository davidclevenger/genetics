#ifndef __DARWIN_H__
#define __DARWIN_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	/*
	*	Individual level members
	*/

	unsigned char* genes;
	double* raw_fitness;
	double* rel_fitness;
	
	/*
	*	Population level members
	*/

	double total_fitness;
	int num_pop;
	int num_genes;
	int mem_needed;
	char pad[4];

} Population;

void init(Population*, int, int); // p, _num_pop, _num_genes
void deinit(Population*); // p

void generate(Population*); // p

#endif

