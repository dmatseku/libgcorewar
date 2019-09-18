#include <libgcorewar.h>
#include <libglKH.h>

void	key_left(void* args)
{
	(void)args;
	g_step_time += DELTA_STEP;
	if (g_step_time > 20.0f)
		g_step_time = 20.0f;
}

void	key_right(void* args)
{
	(void)args;
	g_step_time -= DELTA_STEP;
	if (g_step_time < 0.0f)
		g_step_time = 0.0f;
}

char	key_right_condition(void)
{
	return (!g_glkeys_states[GLFW_KEY_LEFT]);
}

