#ifndef __DARWIN_HPP__
#define __DARWIN_HPP__

#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <math.h>

#define MAX_ITER 100
#define KILL_PCT 0.5

class population
{
	struct individual
	{

		public:
			individual(int);    //n_genes
			~individual();

			bool operator<(const individual&) const;
			void set(int,int);  //idx, val
			double fitness();   //test fitness function
			void mutate();
			void reset();
			int get(int); //idx
			double raw_fitness;
			double rel_fitness;

		private:
			int* genes;
			int _num_genes;
			void init();
	};

	public:
		population(int,int);//num_genes, num_pop
		~population();
		void evolve();

	private:
		void sort_pop(); //sort pop by fitness
		void calc_rel_fitness();
		static bool individual_ptr_cmp(individual*, individual*);
		int kill();
		void reproduce(int); //start_idx
		void crossover(int, int, int); //idx parent1, idx parent2, idx child 
		double total_fitness;
		int _num_pop;
		int _num_genes;
		individual** pop;
};
#endif

