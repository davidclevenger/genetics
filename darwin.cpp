#include "darwin.hpp"

void individual::set(int idx, int val)
{
    if(idx < num_genes && (val == 1 || val == 0))
        genes[idx] = val;
}

individual::individual(int n_genes)
{
    num_genes = n_genes;
    genes = new int[n_genes];
    init();   
}

individual::~individual()
{
    if(genes)
        delete genes;
}

int individual::numGenes()
{
    return num_genes;
}

//random initialization
void individual::init()
{
    srand(time(NULL));
    for(int i = 0; i < num_genes; i++)
        genes[i] = rand() % 2;
    //test 
    for(int i = 0; i < num_genes; i++)
        printf("gene %d: %d\n", i, genes[i]);  
}

population::population(int n_genes, int n_pop)
{
    num_pop = n_pop;
    num_genes = n_genes;
    pop = new individual*[n_pop]; 
    init();
}

population::~population()
{
    if(pop)
        for(int i = 0; i < num_pop; i++)
            if(pop[i])
                delete pop[i];
    if(pop)
        delete pop;   
}

void population::init()
{
    for(int i = 0; i < num_pop; i++)
    {
        pop[i] = new individual(num_genes);
    }
}
