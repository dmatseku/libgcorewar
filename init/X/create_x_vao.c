#include <libgcorewar.h>

static void create_carriage_verts(GLfloat *const res, size_t width)
{
	float x = -((float)width) / g_w_width;
	float y = -((float)width) / g_w_height;
	float x1 = ((float)width) / g_w_width;
	float y1 = ((float)width) / g_w_height;

	if (!res)
	{
		exit_error("malloc error");
		return ;
	}
	res[0] = x;
	res[1] = y;
	res[2] = 0.0f;
	res[3] = 1.0f;
	res[4] = x;
	res[5] = y1;
	res[6] = 0.0f;
	res[7] = 0.0f;
	res[8] = x1;
	res[9] = y;
	res[10] = 1.0f;
	res[11] = 1.0f;
	res[12] = x1;
	res[13] = y1;
	res[14] = 1.0f;
	res[15] = 0.0f;
}

static GLuint* create_carriage_indices(void)
{
	GLuint *const res = (GLuint*)malloc(sizeof(GLuint) * 6);

	if (!res)
	{
		exit_error("malloc error");
		return (0);
	}
	res[0] = 0;
	res[1] = 1;
	res[2] = 2;
	res[3] = 1;
	res[4] = 2;
	res[5] = 3;
	return (res);
}

void	create_x_vao(size_t width)
{
	GLfloat*	verts;
	GLuint*		indices;

	indices = create_carriage_indices();
	verts = (GLfloat*)malloc(sizeof(GLfloat) * 16);
	create_carriage_verts(verts, width);
	glGenVertexArrays(1, &(g_x.vao));
	glGenBuffers(1, &(g_x.vbo));
	glGenBuffers(1, &(g_x.ebo));
	glBindVertexArray(g_x.vao);
	glBindBuffer(GL_ARRAY_BUFFER, g_x.vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_x.ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 6, indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
	free(verts);
	free(indices);
}