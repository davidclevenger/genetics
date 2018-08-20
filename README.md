# Genetics - General Purpose Genetic Algorithms
[![Build Status](https://travis-ci.org/davidclevenger/genetics.svg?branch=master)](https://travis-ci.org/davidclevenger/genetics)

## Functionality
The alogorithm works by instantiating an initial set of randomly generated **Individuals**. These Individuals collectively
form a **Population**. A ***required, user-defined*** fitness function determines how fit each individual is. The fittest Individuals in the population crossover their genes and overwrite a weaker individual in the Population. This process until some fitness is reached, or until an iteration limit is eclipsed.

## The Fitness Function
Users must define a function to determine how well an individual performs against some objective function.
The signature is 
```c
double fitness(Individual* individual)
```
### Example
This particular fitness function says the fitness of an individual is the sum of its genes.
```c
double fitness(Individual* individual)
{
  double fit = 0;
  int i;
  for(i = 0; i < individual->num_genes; i++)
  {
    fit += get_gene(individual, i);
  }
  
  return fit;
}
```
