#include <assert.h>
#include <stdbool.h>
#include <GLFW/glfw3.h>
#include "timer.h"

static timer_func callback;
static double interval = 1;
static void reset_time(void);
bool is_timer_running = false;


void timer_start(double itvl, timer_func on_tick)
{
	assert(on_tick != NULL);

	interval = itvl;
	callback = on_tick;
	is_timer_running = true;

	reset_time();
}

void timer_fire(void)
{
	if (!is_timer_running)
		return;
	if (glfwGetTime() >= interval) {
		callback();
		reset_time();
	}
}

void timer_stop(void)
{
	is_timer_running = false;
}

static void reset_time()
{
	glfwSetTime(0);
}

void reduce_interval(int diff) {
	if (interval - diff > 0) {
		interval -= diff;
	}
}
