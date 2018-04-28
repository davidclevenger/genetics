#ifndef __DARWIN_HPP__
#define __DARWIN_HPP__

#include <cstdlib>

class individual
{
    struct chromosome
    {
            chromosome(int);
            ~chromosome();
            int* genes;
    };

    public:
        individual(int);
        ~indvidual();
        int numGenes();
        void set(int,int);
    private:
        chromosome* c;
        int num_genes;
        void init();
};
#endif
