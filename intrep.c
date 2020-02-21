#include "intrep.h"

char *tobinary(int n, char *buf)
{
	char *ret = buf;
	while (n > 0)
	{
		*buf++ = (n % 2) ? '1' : '0';
		n /= 2;
	}
	*buf = '\0';
	return ret;
}

int32_t smod_neg(int32_t n)
{
	(void) n;
	return 0;
}

short smod_cmp(int32_t x, int32_t y)
{
	(void) x;
	(void) y;
	return 0;
}

int32_t smod_add(int32_t x, int32_t y)
{
	(void) x;
	(void) y;
	return 0;
}

int32_t smod_mul(int32_t x, int32_t y)
{
	(void) x;
	(void) y;
	return 0;
}
