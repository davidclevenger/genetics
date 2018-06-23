#include "darwin.hpp"

using namespace std;

#define POP_SIZE 100

int main()
{
    population p(10, POP_SIZE);
	p.evolve();
}
