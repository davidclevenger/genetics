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
    for(int i = 0; i < num_genes; i++)
        genes[i] = rand() % 2;
    //test 
    for(int i = 0; i < num_genes; i++)
        printf("gene %d: %d\n", i, genes[i]);  
}

//test fitness function
double individual::fitness()
{
    double sum = 0;
    for(int i = 0; i < num_genes; i++)
        sum += genes[i];
    return sum;
}

population::population(int n_genes, int n_pop)
{
    srand(time(NULL));
    printf("creating population...\n");
    num_pop = n_pop;
    num_genes = n_genes;
    init();
}

population::~population()
{
    for(int i = 0; i < num_pop; i++)
        if(pop[i])
        {
            printf("%d not null. deleting...\n", i);
            delete pop[i];
        }
}

void population::init()
{
    individual* tmp;
    for(int i = 0; i < num_pop; i++)
    {
        printf("creating ind %d\n", i);
        tmp = new individual(num_genes);
        pop.push_back(tmp);
    }
}

double population::fitness(int idx)
{
    if(idx > -1 && idx < (int)num_pop)
    {
        return pop[idx]->fitness();
    }
    return -1;
}

void population::print()
{
    printf("%d\n",(int)pop.size());
}
