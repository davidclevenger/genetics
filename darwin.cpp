#include "darwin.hpp"

individual::chromosome::chromosome(int n_genes)
{
    genes = new int[num_genes];   
}

individual::chromosome::~chromosome()
{
    if(genes)
        delete genes;
}

void individual::set(int idx, int val)
{
    if(idx < num_genes && (val == 1 || val == 0))
        c->genes[idx] = val;
}

individual::individual(int n_genes)
{
    num_genes = n_genes;
    c = new chromosome(n_genes);
    init();   
}

individual::~individual()
{
    if(c)
        delete c;
}

int individual::numGenes()
{
    return num_genes;
}

//random initialization
void individual::init()
{
    srand(time(NULL));
    for(int i = 0; i < genes; i++)
        genes[i] = rand() % 2;

    //test init
    for(int i = 0; i < genes; i++)
        printf("gene %d: %d\n", i, genes[i]);  
}
