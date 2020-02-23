#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intrep.h"

int main(void)
{
	assert(smod_lt(1,2));

	assert(smod_cmp(1, 2) == LT);
	assert(smod_cmp(2, 1) == GT);
	assert(smod_cmp(2, 2) == EQ);

	assert(smod_cmp(smod_neg(1), smod_neg(2)) == GT);
	return EXIT_SUCCESS;
}
