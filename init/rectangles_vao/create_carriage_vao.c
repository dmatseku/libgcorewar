#include <libgcorewar.h>
static GLfloat* create_carriage_verts(const t_vector verts)
{
	GLfloat *const res = (GLfloat*)malloc(sizeof(GLfloat) * 16);

	if (!res)
	{
		exit_error("malloc error");
		return (0);
	}
	res[0] = verts.x;
	res[1] = verts.z;
	res[2] = 0.0f;
	res[3] = 0.0f;
	res[4] = verts.x;
	res[5] = verts.w;
	res[6] = 0.0f;
	res[7] = 1.0f;
	res[8] = verts.y;
	res[9] = verts.z;
	res[10] = 1.0f;
	res[11] = 0.0f;
	res[12] = verts.y;
	res[13] = verts.w;
	res[14] = 1.0f;
	res[15] = 1.0f;
	return (res);
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

void	create_carriage_vao(char i, size_t width, size_t height)
{
	GLfloat*	verts;
	GLuint*		indices;
	const float	f_width = width;
	const float	f_height = height;


	indices = create_carriage_indices();
	verts = create_carriage_verts(vec4(f_width / g_w_width / -2.0f,
			f_width / g_w_width / 2.0f - 2.0f / g_w_width,
			f_height / g_w_height / -2.0f,
			f_height / g_w_height / 2.0f - 2.0f / g_w_height));
	glGenBuffers(1, &(g_carriage_array[i].vbo));
	glGenBuffers(1, &(g_carriage_array[i].ebo));
	glGenVertexArrays(1, &(g_carriage_array[i].vao));
	glBindVertexArray(g_carriage_array[i].vao);
	glBindBuffer(GL_ARRAY_BUFFER, g_carriage_array[i].vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_carriage_array[i].ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 6, indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * GL_FLOAT));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
	free(verts);
	free(indices);
}

