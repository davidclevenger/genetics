#include "darwin.h"

int main()
{
	Population p;
	init(&p, 10, 20);
	setup(p.pop[0]);
	print(p.pop[0]);
	deinit(&p);
}
