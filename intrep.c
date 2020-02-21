#include "intrep.h"

char *tobinary(int n, char *buf)
{
	char *ret = buf, bit;
	if (n == 0 || n == 1)
	{
		*buf++ = (n % 2) ? '1' : '0';
		*buf++ = '\0';
	}
	else
	{
		bit = (n % 2) ? '1' : '0';
		buf = tobinary(n/2, buf+1);
		*buf++ = bit;
	}
	*buf++ = '\0';
	return ret;
}

int32_t smod_neg(int32_t n)
{
	return n ^ (1 << 31);
}

bool smod_lt(int32_t x, int32_t y)
{
	int xneg = (1 << 31) & x,
		yneg = (1 << 31) & y,
		xbit, ybit;
	if (xneg && !yneg)
		return true;
	if (!xneg && yneg)
		return false;

	for (int i = 30; i >= 0; i--)
	{
		xbit = (1 << i) & x;
		ybit = (1 << i) & y;

		if (xbit && !ybit)
			return false;
		if (!xbit && ybit)
			return true;
	}
	return false;
}

enum CMP smod_cmp(int32_t x, int32_t y)
{
	int xs = (1 << 31) & x,
		ys = (1 << 31) & y;
	int32_t xmag = (~(1 << 31)) & x,
	        ymag = (~(1 << 31)) & y;
	enum CMP res;

	if (xs != ys)
		return ys ? GT : LT;

	res = smod_lt(xmag, ymag)
		  ? LT
		  : (xmag == ymag)
		     ? EQ
			 : GT;
	return xs ? (-1)*res : res;
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
