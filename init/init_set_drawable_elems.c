#include <libgcorewar.h>

static void	create_strings(void)
{
	float d_y;

	g_str_corewar = string_get_elem(string_create("COREWAR",
			1.0f - MENU_WIDTH / 2,
			0.5f + SPLITER_Y_1 / 2,
			STRING_COREWAR_FONTSIZE, vec4(1.0f, 1.0f, 1.0f, 1.0f), g_window));
	g_str_corewar->active = 0;
	d_y = (SPLITER_Y_1 - SPLITER_Y_2 - SPLITER_HEIGHT) / 3;
	g_str_step_counter = string_get_elem(string_create("0",
			1.0f - MENU_WIDTH / 2,
			SPLITER_Y_1 - d_y * 2,
			STRING_STEP_FONTSIZE, vec4(1.0, 1.0, 1.0, 1.0), g_window));
	g_str_step = string_get_elem(string_create("STEP:",
			1.0f - MENU_WIDTH / 2,
			SPLITER_Y_1 - d_y,
	STRING_STEP_FONTSIZE, vec4(1.0, 1.0, 1.0, 1.0), g_window));
	g_str_dead = string_get_elem(string_create("LIVE CARRIAGES:",
		1.0f - MENU_WIDTH / 2,
		SPLITER_Y_3 - (SPLITER_Y_3 - SPLITER_Y_4 - SPLITER_HEIGHT) / 3,
		STRING_DEAD_FONTSIZE, vec4(1.0, 1.0, 1.0, 1.0), g_window));
	g_str_step_counter->active = 0;
	g_str_step->active = 0;
	g_str_dead->active = 0;
}

static void	create_menu_field(void)
{
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_v_frame, .args = vec4(1.0f - MENU_WIDTH, 1.0f, -1.0f, 1.0f)});
	g_v_frame[0].color = MENU_COLOR;
}

static void	create_spliters(void)
{
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_v_frame + 1,
		.args = vec4(1.0f - MENU_WIDTH, 1.0f, SPLITER_Y_1, SPLITER_Y_1 + SPLITER_HEIGHT)});
	g_v_frame[1].color = SPLITER_COLOR;
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_v_frame + 2,
		.args = vec4(1.0f - MENU_WIDTH, 1.0f, SPLITER_Y_2, SPLITER_Y_2 + SPLITER_HEIGHT)});
	g_v_frame[2].color = SPLITER_COLOR;
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_v_frame + 3,
		.args = vec4(1.0f - MENU_WIDTH, 1.0f, SPLITER_Y_3, SPLITER_Y_3 + SPLITER_HEIGHT)});
	g_v_frame[3].color = SPLITER_COLOR;
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_v_frame + 4,
		.args = vec4(1.0f - MENU_WIDTH, 1.0f, SPLITER_Y_4, SPLITER_Y_4 + SPLITER_HEIGHT)});
	g_v_frame[4].color = SPLITER_COLOR;
}

void	init_set_drawable_elems(t_champ* champions, t_arena* arena, t_carriage** carriages)
{
	g_carriage_lst = 0;
	create_frame_shader_program();
	create_menu_field();
	create_spliters();
	create_strings();
	str_champions_create(champions);
	str_map_create(arena->cell, arena->owner);
	create_carriage();
	g_counts = (unsigned int*)malloc(sizeof(unsigned int) * g_number_of_champions);
	g_lines = (t_line*)malloc(sizeof(t_line) * (4 + g_number_of_champions));
	my_memset(g_counts, 0, sizeof(unsigned int) * g_number_of_champions);
	carriage_list_update(carriages);
	str_xlogins_create();
	create_x();
	str_counters_create();
	draw_arena();
}