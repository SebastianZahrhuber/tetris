#ifndef CURRENT_BLOCK_H
#define CURRENT_BLOCK_H

#include "types.h"

typedef void (*matrix_handler)(void);

extern bool cb_try_move(int dx, int dy);
extern bool cb_try_rotation(void);
extern void ct_render(void);
extern tetrimino ct_try_new_tetrimino(void);
extern tetrimino ct_get_tetrimino(void);
extern void ct_render_tetrimino_preview(void);
extern void ct_initialize_first_tetrimino(void);

#endif