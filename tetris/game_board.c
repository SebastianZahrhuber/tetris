#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include "game_engine.h"
#include "types.h"
#include "game_board.h"

#define MAX_BLOCK_COUNT ((GB_ROWS)*(GB_COLS))

static size_t block_count = 0;
static size_t tetrimino_count = 0;
static block blocks[GB_COLS][GB_ROWS];
static int removed_lines = 0;

bool gb_is_valid_position(const position pos) {
	if (!((pos.x >= 0 && pos.x < GB_COLS) && (pos.y >= 0 && pos.y < GB_ROWS)))
		return false;

	// check collisions for tetriminos
	for (int i = 0; i < GB_COLS; i++) {
		for (int j = 0; j < GB_ROWS; j++) {
			if (blocks[i][j].visible) {
				const position p = blocks[i][j].pos;
				if (pos.x == p.x && pos.y == p.y)
					return false;
			}
		}
	}

	return true;
}

void gb_add_tetrimino(const tetrimino te)
{
	assert(block_count < MAX_BLOCK_COUNT); // Game over

	block new_block;
	new_block.color = te.color;

	for (int i = 0; i < TM_BLOCK_SIZE; i++) {
		assert(gb_is_valid_position(te.pos[i]));

		if (block_count >= MAX_BLOCK_COUNT - 1) {
			ge_set_game_over();
			return;
		}
	}

	for (int i = 0; i < TM_BLOCK_SIZE; i++) {
		int new_x = te.pos[i].x;
		int new_y = te.pos[i].y;
		new_block.pos.x = new_x;
		new_block.pos.y = new_y;
		new_block.visible = true;

		blocks[new_x][new_y] = new_block;
	}
}

void gb_render(void)
{
	for (int i = 0; i < GB_COLS; i++) {
		for (int j = 0; j < GB_ROWS; j++) {
			if (blocks[i][j].visible) {
				render_block(blocks[i][j]);
			}
		}
	}
}

void gb_remove_full_bottom_line() {
	int full_line;

	for (int row = GB_ROWS-1; row >= 0; row--) {
		full_line = true;

		// check if line is full
		for (int i = 0; i < GB_COLS; i++) {
			if (!blocks[i][row].visible) {
				full_line = false;
			}
		}

		// if line is full, remove it from the game board
		if (full_line) {
			for (int i = 0; i < GB_COLS; i++) {
				blocks[i][row].visible = false;
			}

			for (int i = 0; i < GB_COLS; i++) {
				for (int j = row; j < GB_ROWS - 1; j++) {
					block block_to_shift = blocks[i][j];

					if (j == GB_ROWS - 1) {
						blocks[i][j].visible = false;
					}
					else {
						blocks[i][j] = blocks[i][j + 1];
						blocks[i][j].pos.y -= 1;
					}
				}
			}
			removed_lines++;

			//reduce timer
			ge_increase_speed(removed_lines);
		}
	}
}

void gb_render_blocks_borders() {
	for (int i = 0; i < GB_ROWS; i++) {
		for (int j = 0; j < GB_COLS; j++) {
			position pos = { j, i };
			render_block_border(pos);
		}
	}
}

void gb_reset_removed_lines() {
	removed_lines = 0;
}

void gb_clear_game_board() {
	for (int i = 0; i < GB_ROWS; i++) {
		for (int j = 0; j < GB_COLS; j++) {
			blocks[j][i].visible = false;
		}
	}
}

void render_block(const block block) {
	render_quad(block.pos, block.color);
	render_block_border(block.pos);
}

void render_block_border(position pos) {
	glPushMatrix();

	color second_color = color_gray;
	glColor3ubv((unsigned char*)&second_color);
	glLineWidth((GLfloat)3);

	glBegin(GL_LINES);
	glVertex2i(pos.x, pos.y);
	glVertex2i(pos.x, pos.y + 1);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(pos.x, pos.y);
	glVertex2i(pos.x + 1, pos.y);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(pos.x, pos.y + 1);
	glVertex2i(pos.x + 1, pos.y + 1);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(pos.x + 1, pos.y);
	glVertex2i(pos.x + 1, pos.y + 1);
	glEnd();

	glPopMatrix();
}

void render_quad(const position pos, const color col) {
	static_assert(sizeof(col) == 4, "detected unexpected size for colors");

	glColor3ubv((unsigned char*)&col);

	glBegin(GL_QUADS);
	glVertex2i(pos.x, pos.y);
	glVertex2i(pos.x, pos.y + 1);
	glVertex2i(pos.x + 1, pos.y + 1);
	glVertex2i(pos.x + 1, pos.y);
	glEnd();
}

