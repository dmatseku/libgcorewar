#ifndef LIBGCOREWAR_H
#define LIBGCOREWAR_H
#define apple

#define GLEW_STATIC
#ifndef apple
#define WINDOW_WIDTH 2400
#define WINDOW_HEIGHT 1250

#define MENU_WIDTH 0.35f

#define SPLITER_HEIGHT 0.005f

#define SPLITER_Y_1 0.75f
#define SPLITER_Y_2 0.5f
#define SPLITER_Y_3 -0.6f
#define SPLITER_Y_4 -0.85f

#define STRING_COREWAR_FONTSIZE 180

#define STRING_STEP_FONTSIZE 110

#define STRING_CHAMPION_SPLITSIZE 0.08f
#define STRING_CHAMPION_FONTSIZE 120
#define STRING_CHAMPION_MAX_LENGTH 11

#define STRING_MAP_ROW_LENGTH 75
#define STRING_MAP_FONTSIZE 35

#define STRING_DEAD_FONTSIZE 60

#define STRING_COUNTERS_FONTSIZE 40

#define COUNTER_LINES_DISTANCE 10
#define COUNTER_LINES_WIDTH 100


#define XLOGINS_FONTSIZE 37
#define XLOGINS_DISTANCE -2

#define X_DISTANCE 10
#else
#define WINDOW_WIDTH 2400
#define WINDOW_HEIGHT 1250

#define MENU_WIDTH 0.35f

#define SPLITER_HEIGHT 0.005f

#define SPLITER_Y_1 0.75f
#define SPLITER_Y_2 0.5f
#define SPLITER_Y_3 -0.6f
#define SPLITER_Y_4 -0.85f

#define STRING_COREWAR_FONTSIZE 180

#define STRING_STEP_FONTSIZE 110

#define STRING_CHAMPION_SPLITSIZE 0.08f
#define STRING_CHAMPION_FONTSIZE 120
#define STRING_CHAMPION_MAX_LENGTH 11

#define STRING_MAP_ROW_LENGTH 64
#define STRING_MAP_FONTSIZE 35

#define STRING_DEAD_FONTSIZE 60

#define STRING_COUNTERS_FONTSIZE 40

#define COUNTER_LINES_DISTANCE 10
#define COUNTER_LINES_WIDTH 100


#define XLOGINS_FONTSIZE 37
#define XLOGINS_DISTANCE -2

#define X_DISTANCE 10
#endif

#define MENU_COLOR vec4(0.21568627451f, 0.21568627451f, 0.21568627451f, 0.0f)

#define	SPLITER_COLOR vec4(0.28235294117f, 0.28235294117f, 0.28235294117f, 0.0f)

#define	STRING_STEP_INIT_TIME 1.5f
#define STRING_STEP_INIT_DTIME 0.3f

#define X_SHOW_TIME 0.3f

#define STRING_CHAMPION_INIT_TIME 1.6f

#define FONT_PATH "../Oswald-Regular.ttf"

#define FRAMES_COUNT 5

#define STEP_TIME 0.5f

#define FUNC_STATES_COUNT 3

#define STRING_STATIC_INIT_TIME 1.0f

#define MEM_SIZE 4096

#define REG_NUMBER 16

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <libmatrix.h>
#include <libglstring.h>
#include <lgs.h>
#include <stdio.h>
#include <stdint.h>

typedef struct	s_v_carriage t_v_carriage;

typedef struct	s_carriage_lst t_carriage_lst;

typedef struct			s_line
{
	GLuint				vao;
	GLuint				vbo;
	t_vector			color;
}						t_line;

typedef struct          s_champ
{
	char                id;
	char                *name;
	size_t              size;
	char                *comm;
	uint_fast8_t        *exec;
	struct s_champ      *next;
}                       t_champ;

typedef struct			s_arena
{
    int					iter[2];
    unsigned int		check;
    int					cydeath;
    unsigned int		sumlive;
    char				lastlive;
    uint_fast8_t		owner[MEM_SIZE];
    uint_fast8_t		cell[MEM_SIZE];
}						t_arena;

typedef struct			s_carriage
{
    unsigned int		id;
    char				player;
    char				alive;
    int					cylive;
    uint_fast8_t		exec;
	unsigned int		cyexec;
    char				typarg[3];
	unsigned int		posit;
	unsigned int		amskip;
    char				carry;
    int_fast32_t		reg[REG_NUMBER];
    struct s_carriage	*next;
    struct s_carriage	*prev;
}						t_carriage;

typedef struct			s_v_x
{
	float*				model;
	GLuint				vao;
	GLuint				vbo;
	GLuint				ebo;
	GLuint				picture;
	char				draw;
	char				init;
	char				position;
	t_vector			color;
}						t_v_x;

struct				s_v_carriage
{
	GLuint			picture;
	float*			model;
	GLuint			vao;
	GLuint			vbo;
	GLuint			ebo;
};

struct					s_carriage_lst
{
	unsigned int		id;
	char				player;
	int					position;
	int					prev_position;
	char				alive;
	float				x;
	float				y;
	float				prev_x;
	float				prev_y;
	t_carriage_lst*		prev;
	t_carriage_lst*		next;
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

void			(*g_update_map)(unsigned char const * map, unsigned char const * owner);
void			(*g_carriages_draw)(void);
t_carriage_lst*	g_carriage_lst;

t_string*		g_str_dead;

t_string*		g_str_corewar;

unsigned char*	g_map;

t_string**		g_str_map;

float			g_map_opacity;

t_string*		g_str_step_counter;

t_string*		g_str_step;

GLuint			g_frame_shader_program;

GLuint			g_x_shader_program;

t_v_carriage	g_v_carriage;

size_t			g_carriage_width;

size_t			g_carriage_height;

t_v_frame		g_v_frame[FRAMES_COUNT];

GLFWwindow*		g_window;

int				g_w_width;

int				g_w_height;

char			g_number_of_champions;

t_string**		g_str_champions;

t_line*			g_lines;

t_string*		g_str_xlogins[4];

t_v_x			g_x;

unsigned int*	g_counts;

t_string**		g_counters;

char			g_hidden;

size_t	my_strlen(char const * str);

void	exit_error(char *str);

GLchar const *const	get_frame_shader_vert(void);

GLchar const *const get_frame_shader_frag(void);

void	create_frame_shader_program(void);

void	create_x_shader_program(void);

void	create_frame_vao(t_create_frame_vao_args args);

void	init_set_drawable_elems(t_champ const * champions,
								t_arena const * arena, t_carriage const ** carriages);

void	draw_arena(void);

char	corewar_visual_init(t_champ const * champions,
							t_arena const * arena,
							t_carriage const ** carriages, char hidden);

char	str_step_counter_draw_init(char init, double time);

char	str_champions_draw_init(char init, double time);

char	str_static_animation_init(char init, double time);

void	my_bzero(void* array, size_t size);

void	my_memset(void* array, int symbol, size_t size);

char	*my_uitoa(uintmax_t n);

char	*my_base(unsigned char nb);

void	my_memcpy(void* src, void const * dst, size_t len);

void	my_strncat(char* str1, char const * str2, size_t n);

void	str_champions_create(t_champ const * champions);

GLuint	create_picture_carriege(size_t width, size_t height, size_t frame_length);

GLuint	create_picture_x(size_t width);

void	create_carriage_vao(size_t width, size_t height);

void	create_x_vao(size_t width);

GLchar const *const	get_carriage_shader_vert(void);

GLchar const *const	get_carriage_shader_frag(void);

GLchar const *const	get_x_shader_vert(void);

GLchar const *const	get_x_shader_frag(void);

void	carriages_draw(void);

void	non_carriages_draw(void);

void	frames_draw(void);

void	lines_draw(void);

void	x_draw(void);

void	str_map_create(unsigned char const * map, unsigned char const * owner);

void*	str_map_draw_function(t_string const * string, void* param);

void	update_map(unsigned char const * map, unsigned char const * owner);

void	non_update_map(unsigned char const * map, unsigned char const * owner);

size_t	math_length(void);

void	corewar_visual_step(t_arena const * restrict arena,
							t_carriage const ** restrict carriages);

void	create_carriage(void);

char	str_step_carriage(char init, double time);

void	step_draw(char new_position);

void	str_xlogins_create(void);

void	create_line_vao(char index, float x, float y, int width);

void	create_x(void);

void	carriage_list_add(t_carriage_lst** lst, t_carriage_lst* elem);

void	carriage_list_del(t_carriage_lst** lst, t_carriage_lst* elem);

void	carriage_list_update(t_carriage const ** carriages);

void	str_counters_create(void);

char	x_step(double time, char init, char new_position);

void	corewar_visual_destroy(void);

#endif
