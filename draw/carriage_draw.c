#include <libgcorewar.h>

void	carriages_draw(void)
{
	t_carriage_lst* elem;

	elem = g_carriage_lst;
	glUseProgram(g_x_shader_program);
	glBindTexture(GL_TEXTURE_2D, g_v_carriage.picture);
	glBindVertexArray(g_v_carriage.vao);
	while (elem)
	{
		g_v_carriage.model[12] = elem->x;
		g_v_carriage.model[12] = elem->y;
		glUniformMatrix4fv(glGetUniformLocation(g_x_shader_program, "model"),
						   1, GL_FALSE, g_v_carriage.model);
		glUniform4f(glGetUniformLocation(g_x_shader_program, "ourcolor"),
					g_str_champions[elem->player]->color.x, g_str_champions[elem->player]->color.y,
					g_str_champions[elem->player]->color.z, g_str_champions[elem->player]->color.w);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		elem = elem->next;
	}
	g_v_carriage.model[12] = 0;
	g_v_carriage.model[12] = 0;
	glBindVertexArray(0);
}
