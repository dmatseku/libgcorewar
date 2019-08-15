#include <libgcorewar.h>

static GLfloat* create_frame_verts(float x1, float x2, float y1, float y2)
{
	GLfloat *const res = (GLfloat*)malloc(sizeof(GLfloat) * 8);

	if (!res)
	{
		exit_error("malloc error");
		return (0);
	}
	res[0] = x1;
	res[1] = y1;
	res[2] = x1;
	res[3] = y2;
	res[4] = x2;
	res[5] = y1;
	res[6] = x2;
	res[7] = y2;
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
	verts = create_frame_verts(args.x1, args.x2, args.y1, args.y2);
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

