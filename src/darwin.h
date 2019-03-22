#ifndef __DARWIN_H__
#define __DARWIN_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include "individual.h"

#define SURVIVE_RATE 0.5
#define ROUND 1e-9
#define MAX_ITER 100
#define MUTATION_RATE 0.1

typedef enum fitness_type
{
    FIT_MIN,
    FIT_MAX
} FitnessType;

typedef struct
{

	Individual** pop;
	
	double total_fitness;
	int num_pop;
	int num_genes;
	int mem_needed;
	int fitness_type;

} Population;

/*	Population memory utility */

void init(Population*, int, int, FitnessType); // p, _num_pop, _num_genes, _fitness_type
void deinit(Population*); // p

/*	Population functional */

static void generate(Population*); // p
static void evaluate(Population*); // p
static void sortPop(Population*); // p
static int kill(Population*, double); // p, survival_rate
static void regenerate(Population*, int); // p, start

void evolve(Population*); // p

/*	General utility */

void bsort(Population*); // p 

#endif

