#include "darwin.hpp"

population::individual::individual(int num_genes)
{
	genes = NULL;
    _num_genes = num_genes;
	genes = new int[_num_genes];
    init();   
}

population::individual::~individual()
{
    if(genes != NULL)
        delete[] genes;
}

void population::individual::set(int idx, int val)
{
    if(idx < _num_genes && (val == 1 || val == 0))
        genes[idx] = val;
}

bool population::individual::operator<(const individual& rhs) const
{
    return fitness() < rhs.fitness(); 
}

//random initialization
void population::individual::init()
{
    for(int i = 0; i < _num_genes; i++)
        genes[i] = rand() % 2;
    //test 
    for(int i = 0; i < _num_genes; i++)
        printf("gene %d: %d\n", i, genes[i]);  
}

//test fitness function
double population::individual::fitness() const
{
    double sum = 0;
    for(int i = 0; i < _num_genes; i++)
        sum += genes[i];
    return sum;
}

void population::individual::mutate()
{
    double rnd;
    for(int i = 0; i < _num_genes; i++)
    {
        rnd = rand() / (double) RAND_MAX;
        if(rnd > 0.9) //TODO make 0.9 a parameter
        {
            //flip bit
            genes[i] == 0 ? genes[i] = 1 : genes[i] = 0;
        }       
    }
}

void population::individual::reset()
{
	int i;
	for(i = 0; i < _num_genes; i++)
		set(i, 0);
}

population::population(int num_genes, int num_pop)
{
    srand(time(NULL));
    printf("creating population...\n");
    _num_pop = num_pop;
    _num_genes = num_genes;
	pop = NULL;
	pop = new individual*[_num_pop];
    
	for(int i = 0; i < _num_pop; i++)
	{
		pop[i] = NULL;
		pop[i] = new individual(_num_genes);
	}
}

population::~population()
{
    for(int i = 0; i < _num_pop; i++)
        if(pop[i] != NULL)
        {
            printf("%d not null. deleting...\n", i);
            delete pop[i];
        }
	if(pop != NULL)
		delete[] pop;
}

double population::fitness(int idx)
{
    if(idx > -1 && idx < _num_pop)
    {
        return pop[idx]->fitness();
    }
    return -1;
}

void population::print()
{
    printf("%d\n", _num_pop);
}

void population::sort_pop()
{
	std::sort(pop, pop + _num_pop, individual_ptr_cmp);
}

bool population::individual_ptr_cmp(individual* lhs, individual* rhs)
{
	return !(*lhs < *rhs); //descending order
}
