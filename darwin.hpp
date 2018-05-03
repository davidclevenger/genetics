#ifndef __DARWIN_HPP__
#define __DARWIN_HPP__

#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <vector>

class individual
{
    public:
        individual(int);    //n_genes
        ~individual();
        int numGenes();
        void set(int,int);  //idx, val
        double fitness();   //test fitness function
        
    private:
        int* genes;
        int num_genes;
        void init();
};

class population
{
    public:
        population(int,int);//n_genes, n_pop
        ~population();
        double fitness(int); //idx
        void print();
        
    private:
        void init();
        int num_pop;
        int num_genes;
        std::vector<individual*> pop; //TODO should be vector
};
#endif
