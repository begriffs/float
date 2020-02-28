#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intrep.h"

static uint32_t i2s(int32_t i)
{
	return i < 0 ? smod_neg(-i) : i;
}

int main(void)
{
	assert(smod_lt(1,2));

	assert(smod_cmp(1, 2) == LT);
	assert(smod_cmp(2, 1) == GT);
	assert(smod_cmp(2, 2) == EQ);

	assert(smod_cmp(i2s(-1), i2s(-2)) == GT);
	
	assert(smod_cmp(smod_add(7, 3), 10) == EQ);
	assert(smod_cmp(smod_add(7, smod_neg(3)), 4) == EQ);
	assert(smod_cmp(smod_add(smod_neg(3), 7), 4) == EQ);
	assert(smod_cmp(smod_add(smod_neg(3), smod_neg(4)), smod_neg(7)) == EQ);

	for (int i = -5; i < 5; i++)
		for (int j = -5; j < 5; j++)
		{
			assert(smod_cmp(i2s(i+j), smod_add(i2s(i), i2s(j))) == EQ);
			assert(smod_cmp(i2s(i-j), smod_sub(i2s(i), i2s(j))) == EQ);
		}

	puts("OK");
	return EXIT_SUCCESS;
}
