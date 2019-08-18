#include <libgcorewar.h>

GLchar const *const	get_carriage_shader_vert(void)
{
	return ((GLchar const *const)
	"#version 450 core\n"
	"\n"
	"layout (location = 0) in vec2   position;\n"
	"\n"
	"layout (location = 1) in vec2   tex;\n"
	"\n"
	"uniform mat4                    model;\n"
	"\n"
	"out vec2                        texture_coords;\n"
	"\n"
	"void main()\n"
	"{\n"
	"    gl_Position = model * vec4(position, 0.0f, 1.0f);\n"
	"    texture_coords = tex;\n"
	"}");
}

GLchar const *const	get_carriage_shader_frag(void)
{
	return ((GLchar const *const)
			"#version 450 core\n"
			"\n"
			"in  vec2            texture_coords;\n"
			"\n"
			"out vec4            color;\n"
			"\n"
			"uniform sampler2D   Texture;\n"
			"\n"
			"void main()\n"
			"{\n"
			"    color = texture(Texture, texture_coords);\n"
			"}");
}