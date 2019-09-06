#include <libgcorewar.h>

static GLfloat* create_line_verts(const t_vector verts)
{
	GLfloat *const restrict res = (GLfloat*)malloc(sizeof(GLfloat) * 4);

	if (!res)
	{
		exit_error("malloc error");
		return (0);
	}
	res[0] = verts.x;
	res[1] = verts.z;
	res[2] = verts.y;
	res[3] = verts.z;
	return (res);
}

void	create_line_vao(const char index, const float x, const float y, const int width)
{
	GLfloat const *restrict	verts;
	t_vector	coords;

	coords.x = ((float)-width) / g_w_width + x;
	coords.y = ((float)width) / g_w_width + x;
	coords.z = y;
	verts = create_line_verts(coords);
	glGenBuffers(1, &(g_lines[index].vbo));
	glGenVertexArrays(1, &(g_lines[index].vao));
	glBindVertexArray(g_lines[index].vao);
	glBindBuffer(GL_ARRAY_BUFFER, g_lines[index].vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 4, verts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	free((void*)verts);
}