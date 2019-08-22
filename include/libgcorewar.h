#ifndef LIBGCOREWAR_H
#define LIBGCOREWAR_H
#define apple

#define GLEW_STATIC
#ifndef apple
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
#else
#define WINDOW_WIDTH 2400
#define WINDOW_HEIGHT 1250
#define FONT_PATH "../Oswald-Regular.ttf"
#define FRAMES_COUNT 5

#define MENU_WIDTH 0.35f
#define MENU_COLOR vec4(0.21568627451f, 0.21568627451f, 0.21568627451f, 0.0f)

#define SPLITER_HEIGHT 0.005f
#define	SPLITER_COLOR vec4(0.28235294117f, 0.28235294117f, 0.28235294117f, 0.0f)

#define SPLITER_Y_1 0.75f
#define SPLITER_Y_2 0.5f
#define SPLITER_Y_3 -0.6f
#define SPLITER_Y_4 -0.85f

#define STRING_COREWAR_FONTSIZE 170

#define STRING_STEP_FONTSIZE 100
#define	STRING_STEP_INIT_TIME 1.5f
#define STRING_STEP_INIT_DTIME 0.3f

#define STRING_CHAMPION_SPLITSIZE 0.05f
#define STRING_CHAMPION_FONTSIZE 90
#define STRING_CHAMPION_MAX_LENGTH 11
#define STRING_CHAMPION_INIT_TIME 1.6f

#define STRING_MAP_ROW_LENGTH 75
#define STRING_MAP_FONTSIZE 35

#define STRING_DEAD_FONTSIZE 60
#define STRING_DEAD_INIT_TIME 1.0f

#define STRING_STATIC_INIT_TIME 1.0f
#endif

#define STEP_TIME 1.0f

#define FUNC_STATES_COUNT 3

#define MEM_SIZE 4096

#define MAX_CARRIAGES 10

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <libmatrix.h>
#include <libglstring.h>
#include <lgs.h>
#include <stdio.h>

typedef struct	s_v_carriage t_v_carriage;

typedef struct          s_champ
{
	char                id;
	char                *name;
	size_t              size;
	char                *comm;
	uint_fast8_t        *exec;
	struct s_champ      *next;
}                       t_champ;
typedef struct          s_arena
{
	int                 check;
	int                 cydeath;
	int                 sumlive;
	uint_fast8_t        owner[MEM_SIZE];
	uint_fast8_t        cell[MEM_SIZE];
}                       t_arena;

typedef struct          s_carriage
{
	char				id;
	char				carry;
	char				alive;
	uint_fast8_t        exec;
	int                 cylive;
	int                 cyexec;
	int                 positn;
	int                 amskip;
	uint_fast8_t        reg[0];
	struct s_carriage   *next;
}                       t_carriage;

struct			s_v_carriage
{
    int				position;
	int				prev_position;
	GLuint			picture;
	float*			model;
	float*			death_model;
	char			alive;
	float			x;
	float			y;
	GLuint			vao;
	GLuint			vbo;
	GLuint			ebo;
};

typedef struct	s_v_frame
{
	GLuint		vao;
	GLuint		vbo;
	GLuint		ebo;
	t_vector	color;
}				t_v_frame;

typedef struct	s_create_frame_vao_args
{
	t_vector		args;
	t_v_frame*		vao;
}				t_create_frame_vao_args;

t_string*		g_str_dead;

t_string*		g_str_corewar;

unsigned char*	g_map;

t_string**		g_str_map;

float			g_map_opacity;

t_string*		g_str_step_counter;

t_string*		g_str_step;

GLuint			g_frame_shader_program;

GLuint			g_carriage_shader_program;

t_v_carriage*	g_carriage_array;

size_t			g_carriage_width;

size_t			g_carriage_height;

t_v_frame		g_v_frame[FRAMES_COUNT];

GLFWwindow*		g_window;

int				g_w_width;

int				g_w_height;

char			g_number_of_champions;

t_string**		g_str_champions;


size_t	my_strlen(char const * str);

void	exit_error(char *str);

GLchar const *const	get_frame_shader_vert(void);

GLchar const *const get_frame_shader_frag(void);

void	create_frame_shader_program(void);

void	create_carriage_shader_program(void);

void	create_frame_vao(t_create_frame_vao_args args);

void	init_set_drawable_elems(t_champ* champions, t_arena* arena, t_carriage* carriages);

void	draw_arena(void);

char	corewar_visual_init(t_champ* champions, t_arena* arena, t_carriage* carriages);

char	str_step_counter_draw_init(char init, double time);

char	str_champions_draw_init(char init, double time);

char	str_static_animation_init(char init, double time);

void	my_bzero(void* array, size_t size);

void	my_memset(void* array, int symbol, size_t size);

char	*my_uitoa(uintmax_t n);

char	*my_base(unsigned char nb);

void	my_strncat(char* str1, char const * str2, size_t n);

void	str_champions_create(t_champ* champions);

GLuint	create_picture_carriege(t_vector color, size_t width, size_t height, size_t frame_length);

void	create_carriage_vao(char i, size_t width, size_t height);

GLchar const *const	get_carriage_shader_frag(void);

GLchar const *const	get_carriage_shader_vert(void);

void	carriages_draw(void);

void	frames_draw(void);

void	str_map_create(unsigned char const * map, unsigned char* owner);

void*	str_map_draw_function(t_string* string, void* param);

void	update_map(unsigned char const * map, unsigned char const * owner);

size_t math_length(void);

void	corewar_visual_step(t_arena* arena, t_carriage* carriages);

void	create_carriage(t_carriage* carriages);

void	my_memcpy(void* src, void* dst, size_t len);

char	str_step_carriage(char init, double time);

void	step_draw(void);

void	carriages_update(t_carriage* carriages);

#endif
