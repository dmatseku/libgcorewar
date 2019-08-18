#include <libgcorewar.h>

GLchar const *const	get_frame_shader_vert(void)
{
	return ((GLchar const *const)
	"#version 410 core\n"
	"\n"
	"layout (location = 0) in vec2   position;\n"
	"\n"
	"void main()\n"
	"{\n"
	"    gl_Position = vec4(position, 0.999999f, 1.0f);\n"
	"}");
}

GLchar const *const get_frame_shader_frag(void)
{
	return ((GLchar const *const)
	"#version 410 core\n"
	"\n"
	"out vec4    color;\n"
	"\n"
	"void main()\n"
	"{\n"
	"    color = vec4(0.0, 0.2, 0.1, 1.0);\n"
	"}");
}
