#include <libgcorewar.h>

void	non_carriages_draw(void)
{

}

void	carriages_draw(void)
{
	t_carriage_lst const *restrict elem;

	elem = g_carriage_lst;
	glUseProgram(g_x_shader_program);
	glBindTexture(GL_TEXTURE_2D, g_v_carriage.picture);
	glBindVertexArray(g_v_carriage.vao);
	while (elem)
	{
		g_v_carriage.model.matrix[12] = elem->x;
		g_v_carriage.model.matrix[13] = elem->y;
		if (elem->player < 1)
		    printf("%d\n", elem->player);
		glUniformMatrix4fv(glGetUniformLocation(g_x_shader_program, "model"),
						   1, GL_FALSE, g_v_carriage.model.matrix);
		glUniform4f(glGetUniformLocation(g_x_shader_program, "ourcolor"),
					g_str_champions[elem->player - 1]->color.x, g_str_champions[elem->player - 1]->color.y,
					g_str_champions[elem->player - 1]->color.z, g_str_champions[elem->player - 1]->color.w);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		elem = elem->next;
	}
	g_v_carriage.model.matrix[12] = 0;
	g_v_carriage.model.matrix[13] = 0;
	glBindVertexArray(0);
}
