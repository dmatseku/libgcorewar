#include <libgcorewar.h>
#include <unistd.h>

static GLuint	create_carriage_shader_vertex(void)
{
	char				log[512];
	GLint				success;
	GLuint				vshader;
	GLchar const *const	v_shader_str = get_carriage_shader_vert();

	vshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vshader, 1, &v_shader_str , 0);
	glCompileShader(vshader);
	glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vshader, 512, NULL, log);
		exit_error(log);
	}
	return (vshader);
}

static GLuint	create_carriage_shader_fragment(void)
{
	char				log[512];
	GLint				success;
	GLuint				fshader;
	GLchar const *const	f_shader_str = get_carriage_shader_frag();

	fshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fshader, 1, &f_shader_str, 0);
	glCompileShader(fshader);
	glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fshader, 512, NULL, log);
		exit_error(log);
		return(0);
	}
	return (fshader);
}

void	create_carriage_shader_program(void)
{
	const GLuint vshader = create_carriage_shader_vertex();
	const GLuint fshader = create_carriage_shader_fragment();
	char				log[512];
	GLint				success;

	g_carriage_shader_program = glCreateProgram();
	glAttachShader(g_carriage_shader_program, vshader);
	glAttachShader(g_carriage_shader_program, fshader);
	glLinkProgram(g_carriage_shader_program);
	glGetProgramiv(g_carriage_shader_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(g_carriage_shader_program, 512, NULL, log);
		exit_error(log);
	}
	glDeleteShader(vshader);
	glDeleteShader(fshader);
}