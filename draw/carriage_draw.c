#include <libgcorewar.h>

void	carriages_draw(void)
{
	char i;

	i = 0;
	glUseProgram(g_x_shader_program);
	while (i < g_number_of_champions)
	{
		glBindTexture(GL_TEXTURE_2D, g_carriage_array[i].picture);
		glBindVertexArray(g_carriage_array[i].vao);
		glUniformMatrix4fv(glGetUniformLocation(g_x_shader_program, "model"),
						   1, GL_FALSE, g_carriage_array[i].model);
		glUniform4f(glGetUniformLocation(g_x_shader_program, "ourcolor"),
					g_str_champions[i]->color.x, g_str_champions[i]->color.y,
					g_str_champions[i]->color.z, g_str_champions[i]->color.w);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		i++;
	}
	glBindVertexArray(0);
}
