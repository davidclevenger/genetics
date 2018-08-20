#include <math.h>

#include "darwin.h"

#define POP_SIZE 100
#define NUM_GENES 10

/*
* The goal of this example is to fit the line 'y = 2x - 1'.
* A static array of inputs will be used to judge how well the model picks
* parameters compared to the ideal result.
*
* Input array(x):  [-2, 5, 7, 8, 0, 45, -11]
* Output array(y): [-6, 8, 12, 14, -2, 88, -24] (ideal)
*
*
* Gene Arrangement
* Slope guesses(m):			[-2, -1, 0, 1, 2] (bits 0-4)
* Y-intercept guesses(b):	[-2, -1, 0, 1, 2] (bits 5-9)
*
* Over time, the fittest individual(s) should have bits 4 and 6 set.
* All other bits should be unset(0).
*/


/*
* The fitness function will be the inverse sum of squared error(SSE) between calculated
* and ideal results ( 1 / ((y* - y)^2) ).
*/
double fitness(Individual* ind)
{
	int slope, y_int, i;
  	double fit = 0, sse = 0;

	//slopes
  	if(get_gene(ind, 0))
		slope = -2;
	if(get_gene(ind, 1))
		slope = -1;
  	if(get_gene(ind, 2))
		slope = 0;
	if(get_gene(ind, 3))
		slope = 1;
  	if(get_gene(ind, 4))
		slope = 2;
	
	//y-intercepts
  	if(get_gene(ind, 5))
		y_int = -2;
	if(get_gene(ind, 6))
		y_int = -1;
  	if(get_gene(ind, 7))
		y_int = 0;
	if(get_gene(ind, 8))
		y_int = 1;
  	if(get_gene(ind, 9))
		y_int = 2;


	double inputs[7] = {-2, 5, 7, 8, 0, 45, -11};
	double ideal[7] = {-6, 8, 12, 14, -2, 88, -24};

	for(i = 0; i < 7; i++)
	{
		sse += pow( ((inputs[i] * slope + y_int) - ideal[i]), 2);
	}

	fit = 1 / sse;

  return fit;
}

int main()
{
	int i;
	Population p;
	init(&p, POP_SIZE, NUM_GENES);
	for(i = 0; i < POP_SIZE; i++)
	{
		setup(p.pop[i]);
	}
	
	evolve(&p);

	for(i = 0; i < POP_SIZE; i++)
	{
		printf("fitness(%d): %f\t", i, p.pop[i]->raw_fitness);
		print(p.pop[i]);
	}
	deinit(&p);

	return 0;
}
