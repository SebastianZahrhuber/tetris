#pragma comment(lib,"winmm.lib")
#include <windows.h>
#include "current_tetrimino.h"
#include "game_board.h"
#include "game_window.h"
#include "timer.h"
#include "game_engine.h"

static int removed_lines_speed_limits[] = { 2, 10, 20, 40 };
static int speed_limits_count = 4;
static int removed_lines = 0;
static bool game_over = false;
static bool paused = false;

bool ge_handle_move(int dx, int dy)
{
	if (!cb_try_move(dx, dy)) {
		if (dy == -1) { // reached bottom line (actually a vertical collision)
			tetrimino current = ct_get_tetrimino();
			gb_add_tetrimino(current);
			gb_remove_full_bottom_line();
			ct_try_new_tetrimino();
			return false;
		}
	}
	return true;
}

bool ge_handle_rotation() {
	return cb_try_rotation();
}

bool ge_handle_fall_to_bottom() {
	while (ge_handle_move(0, -1)) {
		// repeat until collision
	}
	return true;
}

void ge_increase_speed(int rem_lines) {
	removed_lines++;
	for (int i = 0; i < speed_limits_count; i++) {
		if (rem_lines == removed_lines_speed_limits[i]) {
			reduce_interval(0.1);
			break;
		}
	} 
}

void ge_get_level(int* level, int* max_level) {
	*max_level = speed_limits_count + 1;

	for (int i = speed_limits_count-1; i >= 0; i--) {
		if (removed_lines >= removed_lines_speed_limits[i]) {
			*level = i + 2;
			return;
		}
	}
	*level = 1;
	return;
}

void ge_set_game_over() {
	game_over = true;
	PlaySound(NULL, NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	timer_stop();
}

void ge_restart_game() {
	game_over = false;
	gb_reset_removed_lines();
	gb_clear_game_board();
}

bool ge_is_game_over() {
	return game_over;
}

void ge_update_paused() {
	paused = !paused;

	if (!paused) {
		PlaySound("C:\\Users\\sebas\\Documents\\FH\\Semester_3\\Softwareentwicklung_mit_klassischen_Sprachen\\Uebung\\Ue06\\tetris_fertig\\tetris\\Soundtrack.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	else {
		PlaySound(NULL, NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
}

bool ge_is_game_paused() {
	return paused;
}

