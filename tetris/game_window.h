#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "types.h"

extern void gw_render_sidebar_text(void);
extern void gw_render_game_over_screen(void);
extern void ge_render_pause_screen(void);
extern void gw_render_level(int level, int max_level);
extern void gw_drawLine(position pos1, position pos2);

#endif