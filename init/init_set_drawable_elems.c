#include <libgcorewar.h>

static void	create_strings(void)
{
	g_str_corewar = string_get_elem(string_create("COREWAR",
			(-1.0 + BORDER_CENTER_VERTICAL_X) / 2,
			0.5f + BORDER_CENTER_HORISONTAL_Y_1 / 2,
			STRING_COREWAR_FONTSIZE, vec4(1.0, 0.0, 0.0, 1.0f), g_window));
	g_str_corewar->active = 0;
	g_str_step_counter = string_get_elem(string_create("0",
			0.5f + BORDER_CENTER_VERTICAL_X / 2,
			1.0f - BORDER_LENGTH - (1.0f - BORDER_LENGTH - (BORDER_CENTER_HORISONTAL_Y_1 + BORDER_LENGTH)) / 1.5f,
			STRING_STEP_FONTSIZE, vec4(1.0, 1.0, 1.0, 1.0), g_window));
	g_str_step = string_get_elem(string_create("STEP:",
	0.5f + BORDER_CENTER_VERTICAL_X / 2,
	1.0f - BORDER_LENGTH - (1.0f - BORDER_LENGTH - (BORDER_CENTER_HORISONTAL_Y_1 + BORDER_LENGTH)) / 3.0f,
	STRING_STEP_FONTSIZE, vec4(1.0, 1.0, 1.0, 1.0), g_window));
	g_str_step_counter->active = 0;
	g_str_step->active = 0;
}

static void	create_horizontal_frames(float x_border_length)
{

	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao, .args = vec4(-1.0f, 1.0f, -1.0f, -1.0f + x_border_length}));
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao + 1, .args = vec4(-1.0f, 1.0f, 1.0f, 1.0f - x_border_length)});
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao + 2, .args = vec4(-1.0f, 1.0f, BORDER_CENTER_HORISONTAL_Y_1,
			BORDER_CENTER_HORISONTAL_Y_1 + x_border_length)});
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao + 6, .args = vec4(BORDER_CENTER_VERTICAL_X, 1.0f,
		BORDER_CENTER_HORISONTAL_Y_2, BORDER_CENTER_HORISONTAL_Y_2 + x_border_length)});
}

static void	create_vertical_frames(float y_border_length)
{
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao + 3, .args = vec4(-1.0f, -1.0f + y_border_length, -1.0f, 1.0f)});
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao + 4, .args = vec4(1.0f, 1.0f - y_border_length, -1.0f, 1.0f)});
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao + 5, .args = vec4(BORDER_CENTER_VERTICAL_X,
		BORDER_CENTER_VERTICAL_X + y_border_length,
		-1.0f, 1.0f)});
}

void	init_set_drawable_elems(t_champ* champions, t_arena* arena, t_carriage* carriages)
{
	float x_border_length;
	float y_border_length;

	x_border_length = BORDER_LENGTH;
	y_border_length = g_w_height * x_border_length / g_w_width;
	create_frame_shader_program();
	create_carriage_shader_program();
	create_horizontal_frames(x_border_length);
	create_vertical_frames(y_border_length);
	create_strings();
	str_champions_create(champions);
	g_carriage_array = (t_v_carriage*)malloc(sizeof(t_v_carriage) * g_number_of_champions);
	if (!g_carriage_array)
		exit_error("set_drawable_elems malloc error");
	str_map_create(arena->cell);
	create_carriage(carriages);
	draw_arena();
}