#include <stdint.h>

char *tobinary(int n, char *buf);

int32_t smod_neg(int32_t n);
short   smod_cmp(int32_t x, int32_t y);
int32_t smod_add(int32_t x, int32_t y);
int32_t smod_mul(int32_t x, int32_t y);

int32_t ones_neg(int32_t n);
short   ones_cmp(int32_t x, int32_t y);
int32_t ones_add(int32_t x, int32_t y);
int32_t ones_mul(int32_t x, int32_t y);
