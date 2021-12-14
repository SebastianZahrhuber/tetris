#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma comment(lib,"winmm.lib")
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include "types.h"
#include "current_tetrimino.h"
#include "game_board.h"
#include "game_engine.h"
#include "game_window.h"
#include "timer.h"

#define WIDTH  800
#define BOARD_WIDTH 400
#define HEIGHT ((BOARD_WIDTH * GB_ROWS) / GB_COLS)
#define TIMER_INTERVAL 0.5

static void window_initialized(GLFWwindow *window);
static void render_window(void);
static void on_key(GLFWwindow* window, int key, int scancode, int action, int mods);
static void on_timer(void);
static void start_game(void);

static void window_initialized(GLFWwindow *window) {
	time_t t;
	srand((unsigned)time(&t));
	glfwSetKeyCallback(window, on_key);
	//ct_initialize_first_tetrimino();
	//timer_start(TIMER_INTERVAL, on_timer);
	start_game();
}

static void on_timer(void) {
	if (!ge_is_game_paused()) {
		on_key(NULL, GLFW_KEY_DOWN, 0, GLFW_PRESS, 0);
	}
}

static void render_window(void) {
	int level = 0;
	int max_level = 0;
	ge_get_level(&level, &max_level);

	timer_fire();
	gb_render();
	gb_render_blocks_borders();
	ct_render();
	
	ct_render_tetrimino_preview();
	gw_render_sidebar_text();
	gw_render_level(level, max_level);

	if (ge_is_game_over()) {
		glClearColor(0.6, 0.6, 0.6, 1);
		glClear(GL_COLOR_BUFFER_BIT); //clear frame buffer
		gw_render_game_over_screen();
	}
	else if (ge_is_game_paused()) {
		ge_render_pause_screen();
	}
}

static void start_game(void) {
	ge_restart_game();
	ct_initialize_first_tetrimino();
	timer_start(TIMER_INTERVAL, on_timer);
	PlaySound("path-to-soundtrack\\Soundtrack.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

}

static void on_key(GLFWwindow *window, int key, int scancode, int action, int mods) {
	UNUSED(window);
	UNUSED(scancode);
	UNUSED(mods);

	int dx = 0;
	int dy = 0;
	char game_action[20];

 	if (ge_is_game_over()) {
		if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_ENTER) {
			start_game();
		}
		return;
	}
	else if (ge_is_game_paused()) {
		if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_ESCAPE) {
			ge_update_paused();
		}
		return;
	}

	switch (key) {
	case GLFW_KEY_DOWN: 
		dy = -1;
		strcpy(game_action, "move");
		break;

	case GLFW_KEY_SPACE:
		strcpy(game_action, "fall_to_bottom");
		break;

	case GLFW_KEY_UP:
		strcpy(game_action, "rotate");
		break;

	case GLFW_KEY_LEFT:
		dx = -1;
		strcpy(game_action, "move");
		break;

	case GLFW_KEY_RIGHT:
		dx = 1;
		strcpy(game_action, "move");
		break;

	case GLFW_KEY_ESCAPE:
		strcpy(game_action, "pause");
		break;
	}

	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && (dx != 0 || dy != 0) && strcmp(game_action, "move") == 0) {
		ge_handle_move(dx, dy);
	}
	else if ((action == GLFW_PRESS || action == GLFW_REPEAT) && strcmp(game_action, "rotate") == 0) {
		ge_handle_rotation();
	}
	else if ((action == GLFW_PRESS || action == GLFW_REPEAT) && strcmp(game_action, "fall_to_bottom") == 0) {
		ge_handle_fall_to_bottom();
	}
	else if ((action == GLFW_PRESS || action == GLFW_REPEAT) && strcmp(game_action, "pause") == 0) {
		ge_update_paused();
	}	
}

int main() {
	if(!glfwInit()) {
		fprintf(stderr, "could not initialize GLFW\n");
		return EXIT_FAILURE;
	}

  GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Tetris", NULL, NULL);
	if(!window) {
		glfwTerminate();
		fprintf(stderr, "could not open window\n");
		return EXIT_FAILURE;
	}

	int width, height;
	glfwGetWindowSize(window, &width, &height);
	glfwSetWindowAspectRatio(window, width, height); //enforce correct aspect ratio
	glfwMakeContextCurrent(window);

	window_initialized(window);
	
	while(!glfwWindowShouldClose(window)) {

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		glClearColor(0.6, 0.6, 0.6, 1);
		glClear(GL_COLOR_BUFFER_BIT); //clear frame buffer
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, (width), 0, height); //orthogonal projection - origin is in lower-left corner
		glScalef((float)(width) / (float)WINDOW_COLS, (float)height / (float)WINDOW_ROWS, 1); //scale logical pixel to screen pixels

		render_window();

		const GLenum error = glGetError();
		if(error != GL_NO_ERROR) fprintf(stderr, "ERROR: %s\n", gluErrorString(error));

		glfwSwapBuffers(window);//push image to display
		// glfwPollEvents();
		glfwWaitEventsTimeout(TIMER_INTERVAL/5); //process all events of the application
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return EXIT_SUCCESS;
}
