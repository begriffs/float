#include "intrep.h"

#include <stdbool.h>

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

uint32_t smod_neg(uint32_t n)
{
	return n ^ (1u << 31);
}

bool smod_lt(uint32_t x, uint32_t y)
{
	uint32_t xneg = (1u << 31) & x,
			 yneg = (1u << 31) & y,
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

enum CMP smod_cmp(uint32_t x, uint32_t y)
{
	uint32_t xs = (1u << 31) & x,
			 ys = (1u << 31) & y;
	uint32_t xmag = (~(1u << 31)) & x,
			 ymag = (~(1u << 31)) & y;
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

/* both add1_o and sub1_o */
static unsigned smod_arith1_o(bool x, bool y, bool c)
{
	return
		(!x && !y &&  c) ||
		(!x &&  y && !c) ||
		( x &&  y &&  c) ||
		( x && !y && !c);
}
static unsigned smod_add1_c(bool x, bool y, bool c)
{
	return (x && y) || (x && !y && c) || (y && c);
}

static unsigned smod_sub1_c(bool x, bool y, bool c)
{
	return (!x && y) || (!x && !y && c) || (y && c);
}

#define signo(x) (x & (1u << 31))

uint32_t smod_sub(uint32_t x, uint32_t y)
{
	uint32_t xneg = signo(x),
			 yneg = signo(y);
	bool xb, yb, cb = false;
	uint32_t result = 0;

	if (!xneg && yneg)
	{
		return smod_add(x, smod_neg(y));
	} else if (xneg && !yneg)
	{
		return smod_neg(smod_add(smod_neg(x), y));
	} else if (xneg && yneg)
	{
		return smod_sub(smod_neg(y), smod_neg(x));
	} else /* both positive */
	{
		switch (smod_cmp (x, y))
		{
		case LT: return smod_neg(smod_sub(y, x));
		case EQ: return 0;
		case GT:
			 for (int i = 0; i < 31; i++)
			 {
				 xb = x & (1 << i);
				 yb = y & (1 << i);
				 result |= (smod_arith1_o(xb, yb, cb) << i);
				 cb = smod_sub1_c(xb, yb, cb);
			 }
			 return result;
		}
	}
}

uint32_t smod_add(uint32_t x, uint32_t y)
{
	uint32_t xneg = (1u << 31) & x,
			 yneg = (1u << 31) & y;
	bool xb, yb, cb = false;
	uint32_t result = 0;

	if (xneg == yneg)
	{
		for (int i = 0; i < 31; i++)
		{
			xb = x & (1 << i);
			yb = y & (1 << i);
			result |= (smod_arith1_o(xb, yb, cb) << i);
			cb = smod_add1_c(xb, yb, cb);
		}
		return result | xneg;
	}
	else if (!xneg && yneg)
		return smod_sub(x, smod_neg(y));
	else /* y positive, x negative */
		return smod_sub(y, smod_neg(x));
}

uint32_t smod_mul(uint32_t x, uint32_t y)
{
	(void) x;
	(void) y;
	return 0;
}
