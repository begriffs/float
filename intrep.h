#include <stdint.h>
#include <stdbool.h>

char *tobinary(int n, char *buf);

enum CMP { LT = -1, EQ, GT };

bool     smod_lt(uint32_t x, uint32_t y);
uint32_t  smod_neg(uint32_t n);
enum CMP smod_cmp(uint32_t x, uint32_t y);
uint32_t  smod_add(uint32_t x, uint32_t y);
uint32_t  smod_sub(uint32_t x, uint32_t y);
uint32_t  smod_mul(uint32_t x, uint32_t y);

uint32_t  ones_neg(uint32_t n);
enum CMP ones_cmp(uint32_t x, uint32_t y);
uint32_t  ones_add(uint32_t x, uint32_t y);
uint32_t  ones_mul(uint32_t x, uint32_t y);
