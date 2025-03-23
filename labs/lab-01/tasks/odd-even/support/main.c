// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>

#include "odd_even.h"

int main(void)
{
	int i, n;
	scanf("%d", &n);
	int *v = (int*) malloc(sizeof(*v) * n);
	if(!v) {
		printf("EROARE");
	}
	for ( i = 0 ; i < n; i++) {
		scanf("%d", v + i);
	}
	check_parity(v, n);
	free(v);
	return EXIT_SUCCESS;
}
