#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

random_gen::random_gen()
{
	srand(int(clock()));
}

int random_gen::bounds(int low, int high)
{
	assert ((low < high) && (high < RAND_MAX));
	return (rand() % (high - low + 1) + (low));
}

void random_gen::reset()
{
	srand(int(clock()));
}
