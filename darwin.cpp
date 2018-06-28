#include "darwin.hpp"

population::individual::individual(int num_genes)
{
	genes = NULL;
    _num_genes = num_genes;
	genes = new int[_num_genes];
	raw_fitness = 0.0;
	rel_fitness = 0.0;
    init();   
}

population::individual::~individual()
{
    if(genes != NULL)
        delete[] genes;
}

//set the genes of a specific individual
void population::individual::set(int idx, int val)
{
    if(idx < _num_genes && (val == 1 || val == 0))
        genes[idx] = val;
}

//compare individuals
bool population::individual::operator<(const individual& rhs) const
{
    return rel_fitness < rhs.rel_fitness; 
}

//random initialization
void population::individual::init()
{
    for(int i = 0; i < _num_genes; i++)
        genes[i] = rand() % 2;
	
	raw_fitness = fitness();
	rel_fitness = 0.0;
}

//test fitness function
double population::individual::fitness()
{
    double sum = 0;
    for(int i = 0; i < _num_genes; i++)
        sum += genes[i];
	
	raw_fitness = sum;
    return sum;
}

//mutate the genes of the individual
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

//reset the individual's genes
void population::individual::reset()
{
	int i;
	for(i = 0; i < _num_genes; i++)
		set(i, 0);
	
	raw_fitness = 0.0;
	rel_fitness = 0.0;
}

//return the gene at index idx of the individual
int population::individual::get(int idx)
{
	if(idx >= 0 && idx < _num_genes)
		return genes[idx];
	return -1; //failure
}

population::population(int num_genes, int num_pop)
{
    srand(time(NULL));
    printf("creating population...\n");
    _num_pop = num_pop;
    _num_genes = num_genes;
	total_fitness = 0.0;
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
            delete pop[i];
        }

	if(pop != NULL)
		delete[] pop;
}

/*
//return the relative fitness of an individual
double population::fitness(int idx)
{
    if(idx > -1 && idx < _num_pop)
    {
        return pop[idx]->rel_fitness;
    }
    return -1;
}
*/

//main driver loop
void population::evolve()
{
	int iter = MAX_ITER;
	int start_idx;
	while(iter >= 0)
	{
		calc_rel_fitness();
		sort_pop();
		start_idx = kill();
		reproduce(start_idx);
		
		iter--;
	}
}

//sort pop by individual's relative fitness (descending)
void population::sort_pop()
{
	std::sort(pop, pop + _num_pop, individual_ptr_cmp);
}

//calculate the relative fitness of every individual
void population::calc_rel_fitness()
{
	total_fitness = 0.0;
	
	int i;
	for(i = 0; i < _num_pop; i++)
		total_fitness += pop[i]->fitness(); //will also set individual's fitness
	
	for(i = 0; i < _num_pop; i++)
		pop[i]->rel_fitness = ( (pop[i]->raw_fitness) / total_fitness );
}

//utility for comparing individual pointers
bool population::individual_ptr_cmp(individual* lhs, individual* rhs)
{
	return !(*lhs < *rhs); //descending order
}

//reset lower fitness individuals
int population::kill()
{
	int kill_count = (int)(( _num_pop * KILL_PCT ) + 0.5 );
	int start_idx = _num_pop - kill_count;
	int i;

	for(i = start_idx; i < _num_pop; i++)
		pop[i]->reset();
	
	return start_idx;
}

//reproduce reset individuals
void population::reproduce(int start_idx)
{
	int i;
	
	for(i = start_idx; i < _num_pop; i++)
	{
		//int p1 = [0, start_idx]
		//int p2 = [0, start idx]

		//while(p1 == p2)
			//p2 = [0, start_idx]

		//crossover(p1, p2, i); //child is current index
	}
}

//cross the genes of two parents to create their child
void population::crossover(int p1, int p2, int c)
{
	int i, mid;

	if(c < _num_pop && p1 < _num_pop && p2 < _num_pop)
	{
		//reset child genes
		pop[c]->reset();
		mid = rand() % _num_genes;
	
		//copy genes from parent1
		for(i = 0; i < mid; i++)
			pop[c]->set(i, pop[p1]->get(i)); 		

		//copy genes from parent2
		for(i = mid; i < _num_genes; i++)
			pop[c]->set(i, pop[p2]->get(i)); 		
	}
	else
	{
		printf("ERROR: OOB gene crossover.\n");
	}
}

