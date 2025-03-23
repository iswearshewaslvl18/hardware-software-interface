// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "pixel.h"
#include "pixels.h"
#define GET_PIXEL(a, i ,j) (*(*((a) + (i)) + (j)))

void swap_r(struct pixel *r1, struct pixel *r2, int width)
{
	for (int i = 0; i < width; ++i) {
		struct pixel temp = r1[i];
		r1[i] = r2[i];
		r2[i] = temp;
	}
}

void reverse_pic(struct picture *pic)
{
	int i = 0;
	for (i = 0; i < pic->height / 2; i++) {
		swap_r(pic->pix_array[i], pic->pix_array[pic->height - i - 1], pic->width);
	}
}

void color_to_gray(struct picture *pic)
{
	for (int i = 0; i < pic->height; ++i){
		for (int j = 0; j < pic->width; ++j) {
			GET_PIXEL(pic->pix_array, i, j).R *= 0.3;
			GET_PIXEL(pic->pix_array, i, j).G *= 0.59;
			GET_PIXEL(pic->pix_array, i, j).B *= 0.11;
		}
	}
}
