// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>

#include "odd_even.h"

void print_binary(int number, int nr_bits)
{
	char *bits = malloc(sizeof(number) * nr_bits);
	if (!bits) {
		printf("eroare de alocare a memoriei");
	}
	int i;
	for(i = 0; i < nr_bits; i++) {
		*(bits + i) = number & 1;
		number >>= 1;
	}
	printf("0b");
	for ( i = nr_bits - 1; i >= 0; i--) {
		printf("%d", *(bits + i));
	}
	printf("\n");
	free(bits);
}

void check_parity(int *numbers, int n)
{
	int i = 0, curr = 0;
	for (i = 0; i < n; i++) {
		curr = *(numbers + i);
		if (curr & 1) {
			printf("ox%08X\n", curr);
		} else {
			print_binary(curr, 8);
		}
	}
}
