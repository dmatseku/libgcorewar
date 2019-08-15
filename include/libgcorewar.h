#ifndef LIBGCOREWAR_H
#define LIBGCOREWAR_H

#define GLEW_STATIC
#define WINDOW_WIDTH 2000
#define WINDOW_HEIGHT 1500
#define FONT_PATH "../clacon.ttf"
#define FRAMES_COUNT 6

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <libmatrix.h>
#include <libglstring.h>

typedef struct	s_frame_vao
{
	GLuint		vao;
	GLuint		vbo;
	GLuint		ebo;
}				t_frame_vao;

typedef struct	s_create_frame_vao_args
{
	float x1;
	float x2;
	float y1;
	float y2;
	t_frame_vao*	vao;
}				t_create_frame_vao_args;

GLuint		g_frame_shader_program;

t_frame_vao		g_frame_vao[FRAMES_COUNT];

GLFWwindow*	g_window;

int			g_w_width;

int			g_w_height;



size_t	ft_strlen(char const * str);

void	exit_error(char *str);

GLchar const *const	get_frame_shader_vert(void);

GLchar const *const get_frame_shader_frag(void);

void	create_frame_shader_program(void);

void	create_frame_vao(t_create_frame_vao_args args);

void	init_set_drawable_elems(void);

void	draw_arena(void);

char	corewar_visual_init();

#endif
