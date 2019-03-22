#include <math.h>

#include "darwin.h"

#define POP_SIZE 100
#define NUM_GENES_BYTES (sizeof(int)*2)

/*
* The goal of this example is to fit the line 'y = 2x - 2'.
* A static array of inputs will be used to judge how well the model picks
* parameters compared to the ideal result.
*
* Input array(x):  [-2, 5, 7, 8, 0, 45, -11]
* Output array(y): [-6, 8, 12, 14, -2, 88, -24] (ideal)
*
*
* Gene Arrangement
* Slope guess(m):       32-bit signed integer
* Y-intercept guess(b):	32-bit signed integer
*
*/


/*
* The fitness function will be the inverse sum of error(SOE) between calculated
* and ideal results ( 1 / (y* - y) ).
*/

double fitness(Individual* ind)
{
	int slope, y_int, i;
  	double soe = 0;

	double inputs[7] = {-2, 5, 7, 8, 0, 45, -11};
	double ideal[7] = {-6, 8, 12, 14, -2, 88, -24};

    slope = get_int(ind, 0);
    y_int = get_int(ind, 4);

	for(i = 0; i < 7; i++)
	{
		soe += fabs((inputs[i] * slope + y_int) - ideal[i]);
	}

  return soe;
}

int main()
{
	int i;
	Population p;
	init(&p, POP_SIZE, NUM_GENES_BYTES, FIT_MIN);
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
