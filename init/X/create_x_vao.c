#include <libgcorewar.h>

static void create_carriage_verts(GLfloat *const res, int width)
{
	t_vec4					left_top;
	t_vec4					left_bottom;
	t_vec4					right_top;
	t_vec4					right_bottom;
	t_mat4					proj;

	if (!res)
	{
		exit_error("malloc error");
		return ;
	}
	proj = mat4_orthographic(-(g_w_width / 2), g_w_width / 2 + g_w_width % 2, -(g_w_height / 2),
							  g_w_height / 2 + g_w_height % 2, 0.001f, 100.0f);

	left_top = mat_vec_4_mult(proj, vec4
	(-(width / 2), width / 2 + width % 2, 1.0f, 1.0f));

	left_bottom = mat_vec_4_mult(proj, vec4
	(-(width / 2), -(width / 2), 1.0f, 1.0f));

	right_top = mat_vec_4_mult(proj, vec4
	(width / 2 + width % 2, width / 2 + width % 2, 1.0f, 1.0f));

	right_bottom = mat_vec_4_mult(proj, vec4
	(width / 2 + width % 2, -(width / 2), 1.0f, 1.0f));

	res[0] = left_bottom.x;
	res[1] = left_bottom.y;
	res[2] = 0.0f;
	res[3] = 1.0f;
	res[4] = left_top.x;
	res[5] = left_top.y;
	res[6] = 0.0f;
	res[7] = 0.0f;
	res[8] = right_bottom.x;
	res[9] = right_bottom.y;
	res[10] = 1.0f;
	res[11] = 1.0f;
	res[12] = right_top.x;
	res[13] = right_top.y;
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

void	create_x_vao(const size_t width)
{
	GLfloat *restrict	verts;
	GLuint const *const restrict indices = create_carriage_indices();

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
	free((void*)indices);
}
