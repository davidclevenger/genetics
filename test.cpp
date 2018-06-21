#include "darwin.hpp"

using namespace std;

#define POP_SIZE 20

int main()
{
    population p(10,POP_SIZE);
	p.sort_pop();
    for(int i = 0; i < POP_SIZE; i++)
        printf("%d: %f\n",i, p.fitness(i));
}
