#include <libgcorewar.h>

void	x_draw(void)
{
	if (!g_x.draw)
		return ;
	glUseProgram(g_x_shader_program);
	glBindTexture(GL_TEXTURE_2D, g_x.picture);
	glBindVertexArray(g_x.vao);
	glUniformMatrix4fv(glGetUniformLocation(g_x_shader_program, "model"),
					   1, GL_FALSE, g_x.model.matrix);
	glUniform4f(glGetUniformLocation(g_x_shader_program, "ourcolor"),
			g_x.color.x, g_x.color.y, g_x.color.z, g_x.color.w);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}