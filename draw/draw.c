#include <libgcorewar.h>

static char	call_init_funcs(char *const restrict states, const double time)
{
	if (states[0] < 0)
	{
		states[0] = str_static_animation_init(1, time);
		return (1);
	}
	if (!states[0])
	{
		states[0] = str_static_animation_init(0, time);
		if (states[0])
		{
			states[1] = str_champions_draw_init(1, time);
			states[2] = str_step_counter_draw_init(1, time);
		}
	}
	if (!states[1])
		states[1] = str_champions_draw_init(0, time);
	if (!states[2])
		states[2] = str_step_counter_draw_init(0, time);
	if (!states[0] || !states[1] || !states[2])
		return (1);
	return (0);
}

void	draw_arena(void)
{
	double	time;
	char	func_states[FUNC_STATES_COUNT];
	char	tmp;

	my_memset(func_states, -1, FUNC_STATES_COUNT);
	g_str_step_counter->active = 0;
	tmp = -1;
	string_draw();
	glfwSetTime(0);
	while (tmp && !glfwWindowShouldClose(g_window))
	{
		glClearColor(0.14901960784f, 0.14901960784f, 0.14901960784f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT/* | GL_DEPTH_BUFFER_BIT*/);
		glfwPollEvents();
		time = glfwGetTime();
		frames_draw();
		if (time > 0.5f)
		{
			tmp = call_init_funcs(func_states, time);
			string_draw();
			lines_draw();
			x_draw();
			if (!tmp && !g_hidden)
				carriages_draw();
		}
		glfwSwapBuffers(g_window);
	}
	glfwSetTime(0);
}
