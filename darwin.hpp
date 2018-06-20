#ifndef __DARWIN_HPP__
#define __DARWIN_HPP__

#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <vector>


class population
{
	class individual
	{

		public:
			individual(int);    //n_genes
			~individual();
			bool operator<(const individual&) const;
			void set(int,int);  //idx, val
			double fitness() const;   //test fitness function
			void mutate();

		private:
			int* genes;
			int _num_genes;
			void init();
	};

	public:
		population(int,int);//num_genes, num_pop
		~population();
		double fitness(int); //idx
		void print();

	private:
		int _num_pop;
		int _num_genes;
		individual** pop;
};
#endif
