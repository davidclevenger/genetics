#ifndef __DARWIN_HPP__
#define __DARWIN_HPP__

#include <cstdlib>
#include <stdio.h>
#include <time.h>

class individual
{
    public:
        individual(int);    //n_genes
        ~individual();
        int numGenes();
        void set(int,int);  //idx, val
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
        //TODO individual get(int); //idx
    private:
        void init();
        int num_pop;
        int num_genes;
        individual** pop;
};
#endif
