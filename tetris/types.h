#ifndef TYPES_H
#define TYPES_H

#include <assert.h>
#include <stdbool.h>
#include <GLFW/glfw3.h>

#define GB_ROWS 22
#define GB_COLS 11
#define GB_ROWS_TOP (GB_ROWS - 1)
#define GB_COLS_MID (GB_COLS / 2)

#define WINDOW_COLS 22
#define WINDOW_ROWS GB_ROWS

#define TM_BLOCK_SIZE 4

#define UNUSED(var) ((void)var)

typedef enum {
	color_black   = 0x000000U,
	color_red     = 0x0000FFU,
	color_green   = 0x00FF00U,
	color_blue    = 0xFF0000U,
	color_yellow  = color_red   | color_green,
	color_magenta = color_red   | color_blue,
	color_cyan    = color_green | color_blue,
	color_white   = color_red   | color_green | color_blue,
	color_gray	  = 0x474747
} color;

typedef struct {
	int x, y;
} position;

typedef struct {
	position pos;
	color color;
	bool visible;
} block;

typedef struct {
	position pos[TM_BLOCK_SIZE];
	color color;
	position center_pos;
} tetrimino;

#endif
