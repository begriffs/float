#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intrep.h"

int main(void)
{
	assert(smod_cmp(1, 2) == LT);
	assert(smod_cmp(2, 1) == GT);
	assert(smod_cmp(2, 2) == EQ);

	assert(smod_cmp(0x80000001, 0x80000002) == GT);
	return EXIT_SUCCESS;
}
