#ifndef LIBGCOREWAR_H
#define LIBGCOREWAR_H

#define GLEW_STATIC
#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 800
#define FONT_PATH "../clacon.ttf"
#define FRAMES_COUNT 7

#define BORDER_LENGTH 0.03f
#define BORDER_CENTER_VERTICAL_X 0.7f
#define BORDER_CENTER_HORISONTAL_Y_1 0.7f
#define BORDER_CENTER_HORISONTAL_Y_2 -0.6f

#define STRING_COREWAR_FONTSIZE 130
#define STRING_COREWAR_INIT_TIME 0.5

#define STRING_STEP_FONTSIZE 45
#define	STRING_STEP_INIT_TIME 1.5
#define STRING_STEP_INIT_DTIME 0.3

#define STRING_CHAMPION_SPLITSIZE 0.05f
#define STRING_CHAMPION_FONTSIZE 30
#define STRING_CHAMPION_MAX_LENGTH 11
#define STRING_CHAMPION_INIT_TIME 1.6

#define FUNC_STATES_COUNT 3

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <libmatrix.h>
#include <libglstring.h>

typedef struct	s_champ t_champ;

typedef struct	s_v_carriege t_v_carriege;

struct			s_v_carriege
{
	float*			model;
	unsigned char*	picture;
	GLuint			vao;
	GLuint			vbo;
	GLuint			ebo;
};

struct			s_champ
{
	char*		name;
	t_champ*	next;
};

typedef struct	s_frame_vao
{
	GLuint		vao;
	GLuint		vbo;
	GLuint		ebo;
}				t_frame_vao;

typedef struct	s_create_frame_vao_args
{
	t_vector		args;
	t_frame_vao*	vao;
}				t_create_frame_vao_args;

size_t			g_str_corewar;

t_string*		g_str_step_counter;

GLuint			g_frame_shader_program;

GLuint			g_carriage_shader_program;

t_frame_vao		g_frame_vao[FRAMES_COUNT];

t_v_carriege*	g_carriage_array;

GLFWwindow*		g_window;

int				g_w_width;

int				g_w_height;

char			g_number_of_champions;

t_string**		g_str_champions;


size_t	ft_strlen(char const * str);

void	exit_error(char *str);

GLchar const *const	get_frame_shader_vert(void);

GLchar const *const get_frame_shader_frag(void);

void	create_frame_shader_program(void);

void	create_carriage_shader_program(void);

void	create_frame_vao(t_create_frame_vao_args args);

void	init_set_drawable_elems(t_champ* champions);

void	draw_arena(void);

char	corewar_visual_init();

char	str_corewar_draw_init(char init, double time, size_t index);

char	str_step_counter_draw_init(char init, double time);

char	str_champions_draw_init(char init, double time);

void	ft_bzero(void* array, size_t size);

void	my_memset(void* array, int symbol, size_t size);

void	str_champions_create(t_champ* champions);

void	ft_strncat(char* str1, char const * str2, size_t n);

unsigned char*	create_picture_carriege(t_vector color, size_t width, size_t height);

void	create_carriage_vao(char i, size_t width, size_t height);

GLchar const *const	get_carriage_shader_frag(void);

GLchar const *const	get_carriage_shader_vert(void);

#endif
