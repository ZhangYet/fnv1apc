#include <stdlib.h>

#define FNV1A_32_OFFSET   2166136261UL
#define FNV1A_32_PRIME    16777619
#define fnv1a_32(hash, p, metric, firstspace)   \
	hash = FNV1A_32_OFFSET; \
	for (p = metric; p < firstspace; p++) \
		hash = (hash ^ (unsigned int)*p) * FNV1A_32_PRIME;

unsigned short fnv1a(const char *key, int len)
{
	unsigned int hash;
    const char *end = key + len;
	fnv1a_32(hash, key, key, end);
	return (unsigned short)((hash >> 16) ^ (hash & (unsigned int)0xFFFF));
}
