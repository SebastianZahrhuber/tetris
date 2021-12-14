#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <stdbool.h>

extern bool ge_handle_move(int dx, int dy);
extern bool ge_handle_rotation(void);
extern bool ge_handle_fall_to_bottom(void);
extern void ge_increase_speed(int removed_lines);
extern void ge_get_level(int *level, int *max_level);
extern void ge_set_game_over(void);
extern void ge_restart_game(void);
extern bool ge_is_game_over(void);
extern void ge_update_paused();
extern bool ge_is_game_paused(void);

#endif
