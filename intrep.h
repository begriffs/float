#include <stdint.h>
#include <stdbool.h>

char *tobinary(int n, char *buf);

enum CMP { LT = -1, EQ, GT };

bool     smod_lt(int32_t x, int32_t y);
int32_t  smod_neg(int32_t n);
enum CMP smod_cmp(int32_t x, int32_t y);
int32_t  smod_add(int32_t x, int32_t y);
int32_t  smod_mul(int32_t x, int32_t y);

int32_t  ones_neg(int32_t n);
enum CMP ones_cmp(int32_t x, int32_t y);
int32_t  ones_add(int32_t x, int32_t y);
int32_t  ones_mul(int32_t x, int32_t y);
