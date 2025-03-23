// SPDX-License-Identifier: BSD-3-Clause

#include <stddef.h>

#include "pointers.h"

int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2) {
		if (*s1 == NULL) {
			return 0;
		}
		s1++;
		s2++;
	}
	return *(const char *)s1 - *(const char *)s2;
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *) dest;
	const unsigned char *s = (const unsigned char *) src;
	while (n--){
		*d++ = *s++;
	}
	return dest;
}

char *my_strcpy(char *dest, const char *src)
{
	char* old = dest;
	while ((*dest = *src) != 0) {
		dest++;
		src++;
	}

	return old;
}
