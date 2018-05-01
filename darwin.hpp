#ifndef __DARWIN_HPP__
#define __DARWIN_HPP__

#include <cstdlib>

class individual
{
    struct chromosome
    {
            chromosome(int);//n_genes
            ~chromosome();
            int* genes;
    };

    public:
        individual(int);    //n_genes
        ~indvidual();
        int numGenes();
        void set(int,int);  //idx, val
    private:
        chromosome* c;
        int num_genes;
        void init();
};

class population
{
    public:
        population(int,int);//n_genes, n_pop
        ~population();
        individual get(int);//
    private:
        init();
        int num_pop;
        int num_genes;
        individual** pop;
};
#endif
