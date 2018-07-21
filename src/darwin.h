#ifndef __DARWIN_H__
#define __DARWIN_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "individual.h"

#define SURVIVE_RATE 0.5
#define ROUND 1e-9
#define MAX_ITER 100
#define MUTATION_RATE 0.1

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
void evaluate(Population*); // p
void sortPop(Population*); // p
int kill(Population*, double); // p, survival_rate
void regenerate(Population*, int); // p, start

void evolve(Population*); // p

/*	General utility */

void bsort(Population*); // p 

#endif

