#include <libgcorewar.h>

static GLfloat* create_frame_verts(const t_vector verts)
{
	GLfloat *const res = (GLfloat*)malloc(sizeof(GLfloat) * 8);

	if (!res)
	{
		exit_error("malloc error");
		return (0);
	}
	res[0] = verts.x;
	res[1] = verts.z;
	res[2] = verts.x;
	res[3] = verts.w;
	res[4] = verts.y;
	res[5] = verts.z;
	res[6] = verts.y;
	res[7] = verts.w;
	return (res);
}

static GLuint* create_frame_indices(void)
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

void	create_frame_vao(t_create_frame_vao_args args)
{
	GLfloat*	verts;
	GLuint*		indices;

	indices = create_frame_indices();
	verts = create_frame_verts(args.args);
	glGenBuffers(1, &(args.vao->vbo));
	glGenBuffers(1, &(args.vao->ebo));
	glGenVertexArrays(1, &(args.vao->vao));
	glBindVertexArray(args.vao->vao);
	glBindBuffer(GL_ARRAY_BUFFER, args.vao->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 8, verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, args.vao->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 6, indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	free(verts);
	free(indices);
}
