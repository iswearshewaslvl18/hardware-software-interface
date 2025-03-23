// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "find_max.h"

void *find_max(void *arr, int n, size_t element_size,
				int (*compare)(const void *, const void *))
{
	void *max_elem = arr;

	qsort(arr, n, sizeof(*arr), compare);
	max_elem = &(arr[n - 1]);
	return max_elem;
}

int compare(const void *a, const void *b)
{
	return *(int *)a > *(int *)b ? 1 : 0;
}
