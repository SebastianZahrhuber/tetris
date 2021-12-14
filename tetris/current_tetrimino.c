#include <stdio.h>
#include <windows.h>
#include "types.h"
#include "game_board.h"
#include "game_engine.h"
#include "tetrimino_helper.h"
#include "current_tetrimino.h"

static tetrimino current;
static tetrimino next;
static tetrimino next_preview;
static bool first_tetrimino = true;

static void ct_generate_next_tetrimino(void);

bool cb_try_move(int dx, int dy)
{
	position helper_positions[TM_BLOCK_SIZE];
	bool all_positions_valid = true;

	for (int i = 0; i < TM_BLOCK_SIZE; i++) {
		position pos = current.pos[i];
		pos.x += dx;
		pos.y += dy;
		helper_positions[i] = pos;

		if (!gb_is_valid_position(pos)) {
			all_positions_valid = false;
			break;
		}
	}

	if (!all_positions_valid)
		return false;

	current.center_pos.x += dx;
	current.center_pos.y += dy;
	
	for (int i = 0; i < TM_BLOCK_SIZE; i++) {
		current.pos[i] = helper_positions[i];
	}
	
	return true;
}

bool cb_try_rotation()
{
	position helper_positions[TM_BLOCK_SIZE];
	bool all_positions_valid = true;

	for (int i = 0; i < TM_BLOCK_SIZE; i++) {
		int x_center_diff = current.pos[i].x - current.center_pos.x;
		int y_center_diff = current.pos[i].y - current.center_pos.y;

		position pos = current.pos[i];
		pos.x = current.center_pos.x + y_center_diff;
		pos.y = current.center_pos.y - x_center_diff;
		helper_positions[i] = pos;

		if (!gb_is_valid_position(pos)) {
			all_positions_valid = false;
			break;
		}	
	}

	if (!all_positions_valid)
		return false;

	for (int i = 0; i < TM_BLOCK_SIZE; i++) {
		current.pos[i] = helper_positions[i];
	}

	return true;
}

void ct_render(void)
{
	position block_pos;
	block x_block;
	x_block.color = current.color;

	for (int i = 0; i < TM_BLOCK_SIZE; i++) {
		x_block.pos = current.pos[i];
		render_block(x_block);
	}
}

tetrimino ct_try_new_tetrimino()
{
	for (int i = 0; i < TM_BLOCK_SIZE; i++) {
		position result_tetrimino_pos = next.pos[i];

		// if initial position is invalid -> GAME OVER
		if (!gb_is_valid_position(result_tetrimino_pos)) {
			ge_set_game_over();
			return current;
		}
	}
	
	current = next;

	// after adding new tetrimino, already generating the next one
	ct_generate_next_tetrimino();

	return current;
}

tetrimino ct_get_tetrimino(void)
{
	return current;
}

static void ct_generate_next_tetrimino() {
	th_random_tetrimino(&next);
	color color = th_random_color();
	next.color = color;

	next_preview = next;

	// Sleep for 1.1 seconds on the first run for correct randomizing color values
	if (first_tetrimino) {
		Sleep(1100);
		first_tetrimino = false;
	}
}

void ct_render_tetrimino_preview() {
	position block_pos;
	block x_block;
	x_block.color = next_preview.color;

	for (int i = 0; i < TM_BLOCK_SIZE; i++) {
		x_block.pos = next_preview.pos[i];
		x_block.pos.x += 11;
		x_block.pos.y -= 6;
		render_block(x_block);
	}
}

void ct_initialize_first_tetrimino() {
	ct_generate_next_tetrimino();
	ct_try_new_tetrimino();
}


