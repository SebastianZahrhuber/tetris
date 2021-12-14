#include "tetrimino_helper.h"

void th_random_tetrimino(tetrimino* result_tetrimino) {
	srand((unsigned)time(NULL));
	int random = rand() % 7;
	position positions[TM_BLOCK_SIZE];
	position position_one;
	position position_two;
	position position_three;
	position position_four;
	position center_pos;

	switch (random) {
	case 0:
		// I
		position_one.x = GB_COLS_MID - 2;
		position_one.y = GB_ROWS_TOP;
		position_two.x = GB_COLS_MID - 1;
		position_two.y = GB_ROWS_TOP;
		position_three.x = GB_COLS_MID;
		position_three.y = GB_ROWS_TOP;
		position_four.x = GB_COLS_MID + 1;
		position_four.y = GB_ROWS_TOP;

		center_pos.x = GB_COLS_MID;
		center_pos.y = GB_ROWS_TOP;
		break;
	case 1:
		// J
		position_one.x = GB_COLS_MID - 1;
		position_one.y = GB_ROWS_TOP;
		position_two.x = GB_COLS_MID - 1;
		position_two.y = GB_ROWS_TOP - 1;
		position_three.x = GB_COLS_MID;
		position_three.y = GB_ROWS_TOP - 1;
		position_four.x = GB_COLS_MID + 1;
		position_four.y = GB_ROWS_TOP - 1;

		center_pos.x = GB_COLS_MID;
		center_pos.y = GB_ROWS_TOP - 1;
		break;
	case 2:
		// L
		position_one.x = GB_COLS_MID - 1;
		position_one.y = GB_ROWS_TOP - 1;
		position_two.x = GB_COLS_MID;
		position_two.y = GB_ROWS_TOP - 1;
		position_three.x = GB_COLS_MID + 1;
		position_three.y = GB_ROWS_TOP - 1;
		position_four.x = GB_COLS_MID + 1;
		position_four.y = GB_ROWS_TOP;

		center_pos.x = GB_COLS_MID;
		center_pos.y = GB_ROWS_TOP - 1;
		break;
	case 3:
		// O
		position_one.x = GB_COLS_MID - 1;
		position_one.y = GB_ROWS_TOP;
		position_two.x = GB_COLS_MID - 1;
		position_two.y = GB_ROWS_TOP - 1;
		position_three.x = GB_COLS_MID;
		position_three.y = GB_ROWS_TOP;
		position_four.x = GB_COLS_MID;
		position_four.y = GB_ROWS_TOP - 1;

		center_pos.x = GB_COLS_MID;
		center_pos.y = GB_ROWS_TOP - 1;
		break;
	case 4:
		// S
		position_one.x = GB_COLS_MID - 1;
		position_one.y = GB_ROWS_TOP - 1;
		position_two.x = GB_COLS_MID;
		position_two.y = GB_ROWS_TOP;
		position_three.x = GB_COLS_MID;
		position_three.y = GB_ROWS_TOP - 1;
		position_four.x = GB_COLS_MID + 1;
		position_four.y = GB_ROWS_TOP;

		center_pos.x = GB_COLS_MID;
		center_pos.y = GB_ROWS_TOP - 1;
		break;
	case 5:
		// T
		position_one.x = GB_COLS_MID - 1;
		position_one.y = GB_ROWS_TOP - 1;
		position_two.x = GB_COLS_MID;
		position_two.y = GB_ROWS_TOP;
		position_three.x = GB_COLS_MID;
		position_three.y = GB_ROWS_TOP - 1;
		position_four.x = GB_COLS_MID + 1;
		position_four.y = GB_ROWS_TOP - 1;

		center_pos.x = GB_COLS_MID;
		center_pos.y = GB_ROWS_TOP - 1;
		break;
	case 6:
		// Z
		position_one.x = GB_COLS_MID - 1;
		position_one.y = GB_ROWS_TOP;
		position_two.x = GB_COLS_MID;
		position_two.y = GB_ROWS_TOP;
		position_three.x = GB_COLS_MID;
		position_three.y = GB_ROWS_TOP - 1;
		position_four.x = GB_COLS_MID + 1;
		position_four.y = GB_ROWS_TOP - 1;

		center_pos.x = GB_COLS_MID;
		center_pos.y = GB_ROWS_TOP - 1;
		break;
	default:
		// I
		position_one.x = GB_COLS_MID - 2;
		position_one.y = GB_ROWS_TOP;
		position_two.x = GB_COLS_MID - 1;
		position_two.y = GB_ROWS_TOP;
		position_three.x = GB_COLS_MID;
		position_three.y = GB_ROWS_TOP;
		position_four.x = GB_COLS_MID + 1;
		position_four.y = GB_ROWS_TOP;

		center_pos.x = GB_COLS_MID;
		center_pos.y = GB_ROWS_TOP;
		break;
	};

	result_tetrimino->pos[0] = position_one;
	result_tetrimino->pos[1] = position_two;
	result_tetrimino->pos[2] = position_three;
	result_tetrimino->pos[3] = position_four;
	result_tetrimino->center_pos = center_pos;
}

color th_random_color() {
	time_t t;
	srand((unsigned)time(&t));
	static color colors[] = { color_red, color_blue, color_green, color_yellow, color_magenta, color_cyan };

	int n_color = sizeof(colors) / sizeof(colors[0]);
	int value = rand() % n_color;
	return colors[value];
}