
#include "types.h"
#include "tetrimino_helper.h"
#include "game_window.h"

void gw_render_game_over_screen() {
	color text_color = th_random_color();

	// G
	position g_pos1 = { 2, GB_ROWS - 7 };
	position g_pos2 = { 2, GB_ROWS - 8 };
	position g_pos3 = { 2, GB_ROWS - 9 };
	position g_pos4 = { 2, GB_ROWS - 10 };
	position g_pos5 = { 2, GB_ROWS - 11 };
	position g_pos6 = { 3, GB_ROWS - 7 };
	position g_pos7 = { 4, GB_ROWS - 7 };
	position g_pos8 = { 5, GB_ROWS - 7 };
	position g_pos9 = { 3, GB_ROWS - 11 };
	position g_pos10 = { 4, GB_ROWS - 11 };
	position g_pos11 = { 5, GB_ROWS - 11 };
	position g_pos12 = { 5, GB_ROWS - 10 };
	position g_pos13 = { 5, GB_ROWS - 9 };
	position g_pos14 = { 4, GB_ROWS - 9 };

	// A
	position a_pos1 = { 7, GB_ROWS - 11 };
	position a_pos2 = { 7, GB_ROWS - 10 };
	position a_pos3 = { 7, GB_ROWS - 9 };
	position a_pos4 = { 7, GB_ROWS - 8 };
	position a_pos5 = { 7, GB_ROWS - 7 };
	position a_pos6 = { 8, GB_ROWS - 7 };
	position a_pos7 = { 9, GB_ROWS - 11 };
	position a_pos8 = { 9, GB_ROWS - 10 };
	position a_pos9 = { 9, GB_ROWS - 9 };
	position a_pos10 = { 9, GB_ROWS - 8 };
	position a_pos11 = { 9, GB_ROWS - 7 };
	position a_pos12 = { 8, GB_ROWS - 9 };

	// M
	position m_pos1 = { 11, GB_ROWS - 11 };
	position m_pos2 = { 11, GB_ROWS - 10 };
	position m_pos3 = { 11, GB_ROWS - 9 };
	position m_pos4 = { 11, GB_ROWS - 8 };
	position m_pos5 = { 11, GB_ROWS - 7 };
	position m_pos6 = { 12, GB_ROWS - 8 };
	position m_pos7 = { 13, GB_ROWS - 9 };
	position m_pos8 = { 14, GB_ROWS - 8 };
	position m_pos9 = { 15, GB_ROWS - 7 };
	position m_pos10 = { 15, GB_ROWS - 8 };
	position m_pos11 = { 15, GB_ROWS - 9 };
	position m_pos12 = { 15, GB_ROWS - 10 };
	position m_pos13 = { 15, GB_ROWS - 11 };

	// E
	position e_pos1 = { 17, GB_ROWS - 11 };
	position e_pos2 = { 17, GB_ROWS - 10 };
	position e_pos3 = { 17, GB_ROWS - 9 };
	position e_pos4 = { 17, GB_ROWS - 8 };
	position e_pos5 = { 17, GB_ROWS - 7 };
	position e_pos6 = { 18, GB_ROWS - 7 };
	position e_pos7 = { 19, GB_ROWS - 7 };
	position e_pos8 = { 18, GB_ROWS - 9 };
	position e_pos9 = { 19, GB_ROWS - 9 };
	position e_pos10 = { 18, GB_ROWS - 11 };
	position e_pos11 = { 19, GB_ROWS - 11 };
	
	// O
	position o_pos1 = { 2, GB_ROWS - 14 };
	position o_pos2 = { 2, GB_ROWS - 15 };
	position o_pos3 = { 2, GB_ROWS - 16 };
	position o_pos4 = { 2, GB_ROWS - 17 };
	position o_pos5 = { 2, GB_ROWS - 18 };
	position o_pos6 = { 3, GB_ROWS - 14 };
	position o_pos7 = { 4, GB_ROWS - 14 };
	position o_pos8 = { 5, GB_ROWS - 14 };
	position o_pos9 = { 3, GB_ROWS - 18 };
	position o_pos10 = { 4, GB_ROWS - 18 };
	position o_pos11 = { 5, GB_ROWS - 18 };
	position o_pos12 = { 5, GB_ROWS - 17 };
	position o_pos13 = { 5, GB_ROWS - 16 };
	position o_pos14 = { 5, GB_ROWS - 15 };

	// V
	position v_pos1 = { 7, GB_ROWS - 14 };
	position v_pos2 = { 7, GB_ROWS - 15 };
	position v_pos3 = { 8, GB_ROWS - 16 };
	position v_pos4 = { 8, GB_ROWS - 17 };
	position v_pos5 = { 9, GB_ROWS - 17 };
	position v_pos6 = { 9, GB_ROWS - 18 };
	position v_pos7 = { 10, GB_ROWS - 17 };
	position v_pos8 = { 10, GB_ROWS - 16 };
	position v_pos9 = { 11, GB_ROWS - 15 };
	position v_pos10 = { 11, GB_ROWS - 14 };

	// E
	position e2_pos1 = { 13, GB_ROWS - 14 };
	position e2_pos2 = { 13, GB_ROWS - 15 };
	position e2_pos3 = { 13, GB_ROWS - 16 };
	position e2_pos4 = { 13, GB_ROWS - 17 };
	position e2_pos5 = { 13, GB_ROWS - 18 };
	position e2_pos6 = { 14, GB_ROWS - 14 };
	position e2_pos7 = { 15, GB_ROWS - 14 };
	position e2_pos8 = { 14, GB_ROWS - 16 };
	position e2_pos9 = { 15, GB_ROWS - 16 };
	position e2_pos10 = { 14, GB_ROWS - 18 };
	position e2_pos11 = { 15, GB_ROWS - 18 };

	// R
	position r_pos1 = { 17, GB_ROWS - 14 };
	position r_pos2 = { 17, GB_ROWS - 15 };
	position r_pos3 = { 17, GB_ROWS - 16 };
	position r_pos4 = { 17, GB_ROWS - 17 };
	position r_pos5 = { 17, GB_ROWS - 18 };
	position r_pos6 = { 18, GB_ROWS - 14 };
	position r_pos7 = { 19, GB_ROWS - 14 };
	position r_pos8 = { 19, GB_ROWS - 15 };
	position r_pos9 = { 19, GB_ROWS - 16 };
	position r_pos10 = { 18, GB_ROWS - 16 };
	position r_pos11 = { 18, GB_ROWS - 17 };
	position r_pos12 = { 19, GB_ROWS - 18 };

	glPushMatrix();

	// G
	render_quad(g_pos1, text_color);
	render_quad(g_pos2, text_color);
	render_quad(g_pos3, text_color);
	render_quad(g_pos4, text_color);
	render_quad(g_pos5, text_color);
	render_quad(g_pos6, text_color);
	render_quad(g_pos7, text_color);
	render_quad(g_pos8, text_color);
	render_quad(g_pos9, text_color);
	render_quad(g_pos10, text_color);
	render_quad(g_pos11, text_color);
	render_quad(g_pos12, text_color);
	render_quad(g_pos13, text_color);
	render_quad(g_pos14, text_color);

	// A
	render_quad(a_pos1, text_color);
	render_quad(a_pos2, text_color);
	render_quad(a_pos3, text_color);
	render_quad(a_pos4, text_color);
	render_quad(a_pos5, text_color);
	render_quad(a_pos6, text_color);
	render_quad(a_pos7, text_color);
	render_quad(a_pos8, text_color);
	render_quad(a_pos9, text_color);
	render_quad(a_pos10, text_color);
	render_quad(a_pos11, text_color);
	render_quad(a_pos12, text_color);

	// M
	render_quad(m_pos1, text_color);
	render_quad(m_pos2, text_color);
	render_quad(m_pos3, text_color);
	render_quad(m_pos4, text_color);
	render_quad(m_pos5, text_color);
	render_quad(m_pos6, text_color);
	render_quad(m_pos7, text_color);
	render_quad(m_pos8, text_color);
	render_quad(m_pos9, text_color);
	render_quad(m_pos10, text_color);
	render_quad(m_pos11, text_color);
	render_quad(m_pos12, text_color);
	render_quad(m_pos13, text_color);
	
	// E
	render_quad(e_pos1, text_color);
	render_quad(e_pos2, text_color);
	render_quad(e_pos3, text_color);
	render_quad(e_pos4, text_color);
	render_quad(e_pos5, text_color);
	render_quad(e_pos6, text_color);
	render_quad(e_pos7, text_color);
	render_quad(e_pos8, text_color);
	render_quad(e_pos9, text_color);
	render_quad(e_pos10, text_color);
	render_quad(e_pos11, text_color);

	// O
	render_quad(o_pos1, text_color);
	render_quad(o_pos2, text_color);
	render_quad(o_pos3, text_color);
	render_quad(o_pos4, text_color);
	render_quad(o_pos5, text_color);
	render_quad(o_pos6, text_color);
	render_quad(o_pos7, text_color);
	render_quad(o_pos8, text_color);
	render_quad(o_pos9, text_color);
	render_quad(o_pos10, text_color);
	render_quad(o_pos11, text_color);
	render_quad(o_pos12, text_color);
	render_quad(o_pos13, text_color);
	render_quad(o_pos14, text_color);

	// V
	render_quad(v_pos1, text_color);
	render_quad(v_pos2, text_color);
	render_quad(v_pos3, text_color);
	render_quad(v_pos4, text_color);
	render_quad(v_pos5, text_color);
	render_quad(v_pos6, text_color);
	render_quad(v_pos7, text_color);
	render_quad(v_pos8, text_color);
	render_quad(v_pos9, text_color);
	render_quad(v_pos10, text_color);

	// E
	render_quad(e2_pos1, text_color);
	render_quad(e2_pos2, text_color);
	render_quad(e2_pos3, text_color);
	render_quad(e2_pos4, text_color);
	render_quad(e2_pos5, text_color);
	render_quad(e2_pos6, text_color);
	render_quad(e2_pos7, text_color);
	render_quad(e2_pos8, text_color);
	render_quad(e2_pos9, text_color);
	render_quad(e2_pos10, text_color);
	render_quad(e2_pos11, text_color);

	// R
	render_quad(r_pos1, text_color);
	render_quad(r_pos2, text_color);
	render_quad(r_pos3, text_color);
	render_quad(r_pos4, text_color);
	render_quad(r_pos5, text_color);
	render_quad(r_pos6, text_color);
	render_quad(r_pos7, text_color);
	render_quad(r_pos8, text_color);
	render_quad(r_pos9, text_color);
	render_quad(r_pos10, text_color);
	render_quad(r_pos11, text_color);
	render_quad(r_pos12, text_color);

	glPopMatrix();
}

void ge_render_pause_screen() {
	color text_color = th_random_color();

	// P
	position p_pos1 = { 1, GB_ROWS - 7 };
	position p_pos2 = { 1, GB_ROWS - 8 };
	position p_pos3 = { 1, GB_ROWS - 9 };
	position p_pos4 = { 1, GB_ROWS - 10 };
	position p_pos5 = { 1, GB_ROWS - 11 };
	position p_pos6 = { 2, GB_ROWS - 7 };
	position p_pos7 = { 3, GB_ROWS - 7 };
	position p_pos8 = { 2, GB_ROWS - 9 };
	position p_pos9 = { 3, GB_ROWS - 9 };
	position p_pos10 = { 3, GB_ROWS - 8 };

	// A
	position a_pos1 = { 5, GB_ROWS - 11 };
	position a_pos2 = { 5, GB_ROWS - 10 };
	position a_pos3 = { 5, GB_ROWS - 9 };
	position a_pos4 = { 5, GB_ROWS - 8 };
	position a_pos5 = { 5, GB_ROWS - 7 };
	position a_pos6 = { 6, GB_ROWS - 7 };
	position a_pos7 = { 7, GB_ROWS - 11 };
	position a_pos8 = { 7, GB_ROWS - 10 };
	position a_pos9 = { 7, GB_ROWS - 9 };
	position a_pos10 = { 7, GB_ROWS - 8 };
	position a_pos11 = { 6, GB_ROWS - 9 };
	position a_pos12 = { 7, GB_ROWS - 7 };

	// U
	position u_pos1 = { 9, GB_ROWS - 11 };
	position u_pos2 = { 9, GB_ROWS - 10 };
	position u_pos3 = { 9, GB_ROWS - 9 };
	position u_pos4 = { 9, GB_ROWS - 8 };
	position u_pos5 = { 9, GB_ROWS - 7 };
	position u_pos6 = { 10, GB_ROWS - 11 };
	position u_pos7 = { 11, GB_ROWS - 11 };
	position u_pos8 = { 12, GB_ROWS - 7 };
	position u_pos9 = { 12, GB_ROWS - 8 };
	position u_pos10 = { 12, GB_ROWS - 9 };
	position u_pos11 = { 12, GB_ROWS - 10 };
	position u_pos12 = { 12, GB_ROWS - 11 };

	// s
	position s_pos1 = { 14, GB_ROWS - 7 };
	position s_pos2 = { 14, GB_ROWS - 8 };
	position s_pos3 = { 14, GB_ROWS - 9 };
	position s_pos4 = { 15, GB_ROWS - 7 };
	position s_pos5 = { 16, GB_ROWS - 7 };
	position s_pos6 = { 15, GB_ROWS - 9 };
	position s_pos7 = { 16, GB_ROWS - 9};
	position s_pos8 = { 14, GB_ROWS - 11 };
	position s_pos9 = { 15, GB_ROWS - 11 };
	position s_pos10 = { 16, GB_ROWS - 11};
	position s_pos11 = { 16, GB_ROWS - 10 };
	position s_pos12 = { 16, GB_ROWS - 11 };

	// E
	position e_pos1 = { 18, GB_ROWS - 11 };
	position e_pos2 = { 18, GB_ROWS - 10 };
	position e_pos3 = { 18, GB_ROWS - 9 };
	position e_pos4 = { 18, GB_ROWS - 8 };
	position e_pos5 = { 18, GB_ROWS - 7 };
	position e_pos6 = { 19, GB_ROWS - 7 };
	position e_pos7 = { 20, GB_ROWS - 7 };
	position e_pos8 = { 19, GB_ROWS - 9 };
	position e_pos9 = { 20, GB_ROWS - 9 };
	position e_pos10 = { 19, GB_ROWS - 11 };
	position e_pos11 = { 20, GB_ROWS - 11 };

	//P
	render_quad(p_pos1, text_color);
	render_quad(p_pos2, text_color);
	render_quad(p_pos3, text_color);
	render_quad(p_pos4, text_color);
	render_quad(p_pos5, text_color);
	render_quad(p_pos6, text_color);
	render_quad(p_pos7, text_color);
	render_quad(p_pos8, text_color);
	render_quad(p_pos9, text_color);
	render_quad(p_pos10, text_color);

	// A
	render_quad(a_pos1, text_color);
	render_quad(a_pos2, text_color);
	render_quad(a_pos3, text_color);
	render_quad(a_pos4, text_color);
	render_quad(a_pos5, text_color);
	render_quad(a_pos6, text_color);
	render_quad(a_pos7, text_color);
	render_quad(a_pos8, text_color);
	render_quad(a_pos9, text_color);
	render_quad(a_pos10, text_color);
	render_quad(a_pos11, text_color);
	render_quad(a_pos12, text_color);

	//// U
	render_quad(u_pos1, text_color);
	render_quad(u_pos2, text_color);
	render_quad(u_pos3, text_color);
	render_quad(u_pos4, text_color);
	render_quad(u_pos5, text_color);
	render_quad(u_pos6, text_color);
	render_quad(u_pos7, text_color);
	render_quad(u_pos8, text_color);
	render_quad(u_pos9, text_color);
	render_quad(u_pos10, text_color);
	render_quad(u_pos11, text_color);
	render_quad(u_pos12, text_color);

	//// S
	render_quad(s_pos1, text_color);
	render_quad(s_pos2, text_color);
	render_quad(s_pos3, text_color);
	render_quad(s_pos4, text_color);
	render_quad(s_pos5, text_color);
	render_quad(s_pos6, text_color);
	render_quad(s_pos7, text_color);
	render_quad(s_pos8, text_color);
	render_quad(s_pos9, text_color);
	render_quad(s_pos10, text_color);
	render_quad(s_pos11, text_color);
	render_quad(s_pos12, text_color);

	//// E
	render_quad(e_pos1, text_color);
	render_quad(e_pos2, text_color);
	render_quad(e_pos3, text_color);
	render_quad(e_pos4, text_color);
	render_quad(e_pos5, text_color);
	render_quad(e_pos6, text_color);
	render_quad(e_pos7, text_color);
	render_quad(e_pos8, text_color);
	render_quad(e_pos9, text_color);
	render_quad(e_pos10, text_color);
	render_quad(e_pos11, text_color);

}

void gw_render_sidebar_text() {
	position n_line1_pos1 = { GB_COLS + 1, GB_ROWS - 4 };
	position n_line1_pos2 = { GB_COLS + 1, GB_ROWS - 2 };
	position n_line2_pos1 = { GB_COLS + 1, GB_ROWS - 2 };
	position n_line2_pos2 = { GB_COLS + 3, GB_ROWS - 4 };
	position n_line3_pos1 = { GB_COLS + 3, GB_ROWS - 4 };
	position n_line3_pos2 = { GB_COLS + 3, GB_ROWS - 2 };

	position e_line1_pos1 = { GB_COLS + 4, GB_ROWS - 4 };
	position e_line1_pos2 = { GB_COLS + 4, GB_ROWS - 2 };
	position e_line2_pos1 = { GB_COLS + 4, GB_ROWS - 2 };
	position e_line2_pos2 = { GB_COLS + 5, GB_ROWS - 2 };
	position e_line3_pos1 = { GB_COLS + 4, GB_ROWS - 3 };
	position e_line3_pos2 = { GB_COLS + 5, GB_ROWS - 3 };
	position e_line4_pos1 = { GB_COLS + 4, GB_ROWS - 4 };
	position e_line4_pos2 = { GB_COLS + 5, GB_ROWS - 4 };

	position x_line1_pos1 = { GB_COLS + 6, GB_ROWS - 4 };
	position x_line1_pos2 = { GB_COLS + 7, GB_ROWS - 2 };
	position x_line2_pos1 = { GB_COLS + 6, GB_ROWS - 2 };
	position x_line2_pos2 = { GB_COLS + 7, GB_ROWS - 4 };

	position t_line1_pos1 = { GB_COLS + 8, GB_ROWS - 2 };
	position t_line1_pos2 = { GB_COLS + 10, GB_ROWS - 2 };
	position t_line2_pos1 = { GB_COLS + 9, GB_ROWS - 2 };
	position t_line2_pos2 = { GB_COLS + 9, GB_ROWS - 4 };

	glPushMatrix();

	// N
	gw_drawLine(n_line1_pos1, n_line1_pos2);
	gw_drawLine(n_line2_pos1, n_line2_pos2);
	gw_drawLine(n_line3_pos1, n_line3_pos2);

	// E
	gw_drawLine(e_line1_pos1, e_line1_pos2);
	gw_drawLine(e_line2_pos1, e_line2_pos2);
	gw_drawLine(e_line3_pos1, e_line3_pos2);
	gw_drawLine(e_line4_pos1, e_line4_pos2);

	// X
	gw_drawLine(x_line1_pos1, x_line1_pos2);
	gw_drawLine(x_line2_pos1, x_line2_pos2);

	// T
	gw_drawLine(t_line1_pos1, t_line1_pos2);
	gw_drawLine(t_line2_pos1, t_line2_pos2);

	glPopMatrix();
}

void gw_render_level(int level, int max_level) {
	color block_color = color_gray;

	glPushMatrix();

	for (int i = 0; i < max_level; i++) {
		position level_pos = { GB_COLS + 3 + i, GB_ROWS - 20 };
		render_block_border(level_pos);
	}

	for (int i = 0; i < level; i++) {
		position level_pos = { GB_COLS + 3 + i, GB_ROWS - 20 };
		render_quad(level_pos, block_color);
	}

	// Text L.
	position l_line1_pos1 = { GB_COLS + 1, GB_ROWS - 18 };
	position l_line1_pos2 = { GB_COLS + 1, GB_ROWS - 20 };
	position l_line2_pos1 = { GB_COLS + 1, GB_ROWS - 20 };
	position l_line2_pos2 = { GB_COLS + 2, GB_ROWS - 20 };

	gw_drawLine(l_line1_pos1, l_line1_pos2);
	gw_drawLine(l_line2_pos1, l_line2_pos2);

	glPopMatrix();
}

void gw_drawLine(position pos1, position pos2) {
	glBegin(GL_LINES);
	glVertex2i(pos1.x, pos1.y);
	glVertex2i(pos2.x, pos2.y);
	glEnd();
}