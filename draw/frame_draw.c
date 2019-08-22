#include <libgcorewar.h>

void	frames_draw(void)
{
	char i;

	i = 0;
	while (i < FRAMES_COUNT)
	{
		glUseProgram(g_frame_shader_program);
		glBindVertexArray(g_v_frame[i].vao);
		glUniform4f(glGetUniformLocation(g_frame_shader_program, "ourcolor"),
				g_v_frame[i].color.x, g_v_frame[i].color.y, g_v_frame[i].color.z, g_v_frame[i].color.w);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		i++;
	}
	glBindVertexArray(0);
}
