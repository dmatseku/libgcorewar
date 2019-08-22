#include <libgcorewar.h>

void	step_draw(void)
{
	double	time;
	char	tmp;

	tmp = 0;
	str_step_carriage(1, glfwGetTime());
	while (!tmp && !glfwWindowShouldClose(g_window))
	{
		glClearColor(0.14901960784f, 0.14901960784f, 0.14901960784f, 0.14901960784f);
		glClear(GL_COLOR_BUFFER_BIT/* | GL_DEPTH_BUFFER_BIT*/);
		glfwPollEvents();
		time = glfwGetTime();
		frames_draw();
		tmp = str_step_carriage(0, time);
		string_draw();
		carriages_draw();
		glfwSwapBuffers(g_window);
	}
	glfwSetTime(0);
}
