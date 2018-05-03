#include "darwin.hpp"

using namespace std;

int main()
{
    population p(10,5);
    for(int i = 0; i < 5; i++)
        printf("%d: %f\n",i, p.fitness(i));
}
