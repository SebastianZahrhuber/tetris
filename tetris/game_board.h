#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <stdbool.h>
#include "types.h"

extern bool gb_is_valid_position(const position pos);
extern void gb_add_tetrimino(const tetrimino block);
extern void gb_render(void);
extern void gb_remove_full_bottom_line(void);
extern void gb_reset_removed_lines(void);
extern void gb_clear_game_board(void);
extern void render_block(const block block);
extern void render_block_border(position pos);
extern void render_quad(const position pos, const color color);

#endif
