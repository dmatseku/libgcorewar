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

void	draw_arena(void)
{
	while (1)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();
		draw_frames();
		glfwSwapBuffers(g_window);
	}
}
