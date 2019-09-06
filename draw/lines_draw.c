#include <libgcorewar.h>

void	lines_draw(void)
{
	char i;

	i = 0;
	while (i < 4 + g_number_of_champions)
	{
		glUseProgram(g_frame_shader_program);
		glBindVertexArray(g_lines[i].vao);
		glUniform4f(glGetUniformLocation(g_frame_shader_program, "ourcolor"),
			g_lines[i].color.x, g_lines[i].color.y, g_lines[i].color.z, g_lines[i].color.w);
		glDrawArrays(GL_LINES, 0, 2);
		i++;
	}
	glBindVertexArray(0);
}
