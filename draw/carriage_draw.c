#include <libgcorewar.h>

void	carriages_draw(void)
{
	char i;

	i = 1;
	glUseProgram(g_carriage_shader_program);
//	while (i < 1)
//	{
		glBindTexture(GL_TEXTURE_2D, g_carriage_array[i].picture);
		glBindVertexArray(g_carriage_array[i].vao);
		glUniformMatrix4fv(glGetUniformLocation(g_carriage_shader_program, "model"),
						   1, GL_FALSE, g_carriage_array[i].model);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
//		i++;
//	}
}
