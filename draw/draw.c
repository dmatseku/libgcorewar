#include <libgcorewar.h>

static void	draw_frames(void)
{
	char i;

	i = 0;
	while (i < FRAMES_COUNT)
	{
		glUseProgram(g_frame_shader_program);
		glBindVertexArray(g_frame_vao[i].vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		i++;
	}
	glBindVertexArray(0);
}

static char	call_init_funcs(char* states, double time)
{
	if (states[0] < 0)
	{
		states[0] = str_corewar_draw_init(1, time);
		states[1] = str_champions_draw_init(1, time);
		states[2] = str_step_counter_draw_init(1, time);
		states[3] = str_map_draw_init(1, time);
		return (1);
	}
	if (!states[0])
		states[0] = str_corewar_draw_init(0, time);
	if (!states[1])
		states[1] = str_champions_draw_init(0, time);
	if (!states[2])
		states[2] = str_step_counter_draw_init(0, time);
	if (!states[3])
		states[3] = str_map_draw_init(0, time);
	if (!states[0] || !states[1] || !states[2] || !states[3])
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
		glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT/* | GL_DEPTH_BUFFER_BIT*/);
		glfwPollEvents();
		time = glfwGetTime();
		draw_frames();
		if (time > 0.5f)
		{
			tmp = call_init_funcs(func_states, time);
			string_draw();
			if (!tmp)
				carriages_draw();
		}
		glfwSwapBuffers(g_window);
	}
	glfwSetTime(0);
}
