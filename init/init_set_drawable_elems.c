#include <libgcorewar.h>

static void	create_strings(void)
{
	g_str_corewar = string_get_elem(string_create("COREWAR",
			(-1.0 + BORDER_CENTER_VERTICAL_X) / 2,
			0.5f + BORDER_CENTER_HORISONTAL_Y_1 / 2,
			STRING_COREWAR_FONTSIZE, vec4(1.0, 0.0, 0.0, 1.0f), g_window));
	g_str_corewar->active = 0;
	g_str_step_counter = string_get_elem(string_create("STEP: 0",
			0.5f + BORDER_CENTER_VERTICAL_X / 2,
			0.5 + BORDER_CENTER_HORISONTAL_Y_1 / 2,
			STRING_STEP_FONTSIZE, vec4(1.0, 1.0, 1.0, 1.0), g_window));
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

static void	create_pictures(void)
{
	float	d_position_y;
	float	d_position_x;
	char i;
	t_matrix *const restrict matrix = matrix_create(4, 4);

	d_position_y = (BORDER_CENTER_HORISONTAL_Y_2 - (-1.0f + BORDER_LENGTH))
			/ (g_number_of_champions / 2 + g_number_of_champions % 2 + 1);
	d_position_x = 1.0f - BORDER_LENGTH - BORDER_CENTER_VERTICAL_X - BORDER_LENGTH / 3;
	i = 0;
	if (!matrix)
		exit_error("matrix_create error");
	while (i < g_number_of_champions)
	{
		g_carriage_array[i].picture
			= create_picture_carriege(g_str_champions[i]->color, 30, 50);
		create_carriage_vao(i, 30, 50);
		g_carriage_array[i].model = matrix_to_array(matrix);
		g_carriage_array[i].death_position = vec2(d_position_x * (i % 2 + 1), d_position_y * (i / 2));
		if (!g_carriage_array[i].model)
			exit_error("matrix_to_array error");
		i++;
	}
	matrix_free(matrix);
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
	g_carriage_array = (t_v_carriege*)malloc(sizeof(t_v_carriege) * g_number_of_champions);
	if (!g_carriage_array)
		exit_error("set_drawable_elems malloc error");
	create_pictures();
	str_map_create(arena->cell);
	draw_arena();
}