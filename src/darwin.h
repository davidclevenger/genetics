#ifndef __DARWIN_H__
#define __DARWIN_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "individual.h"

typedef struct
{

	Individual** pop;
	
	double total_fitness;
	int num_pop;
	int num_genes;
	int mem_needed;
	char pad[4];

} Population;

/*	Population memory utility */

void init(Population*, int, int); // p, _num_pop, _num_genes
void deinit(Population*); // p

/*	Population functional */

void generate(Population*); // p

#endif

