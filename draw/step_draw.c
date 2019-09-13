#include <libgcorewar.h>

void	step_draw(const char new_position)
{
	double	time;
	char	res1;
	char	res2;

	time = glfwGetTime();
	res1 = str_step_carriage(1, time);
	res2 = x_step(time, 1, new_position);
	while ((!res1 || !res2) && !glfwWindowShouldClose(g_window))
	{
		glClearColor(0.14901960784f, 0.14901960784f, 0.14901960784f, 0.14901960784f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		time = glfwGetTime();
		frames_draw();
		if (!res1)
			res1 = str_step_carriage(0, time);
		if (!res2)
			res2 = x_step(time, 0, new_position);
		string_draw();
		g_carriages_draw();
		lines_draw();
		x_draw();
		glfwSwapBuffers(g_window);
	}
	if (glfwWindowShouldClose(g_window))
	{
		glfwTerminate();
		exit(0);
	}
	glfwSetTime(0);
}
