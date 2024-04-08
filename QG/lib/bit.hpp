#ifndef BIT_HPP
#define BIT_HPP

#include <bitset>

#define MASK(x) (1LL << x)
#define BIT_STATE(x, i) ((x >> i) && 1)
#define SET_ON(x, i) (x | MASK(i))
#define SET_OFF(x, i) (x & ~MASK(i))
#define NUM_BITSET(x) __builtin_popcount(x)

#endif