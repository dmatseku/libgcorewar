#include <libgcorewar.h>

void	str_counters_create(void)
{
	const float	d_x = MENU_WIDTH / (g_number_of_champions + 1);
	char i;

	i = 0;
	g_counters = (t_string**)malloc(sizeof(t_string*) * g_number_of_champions);
	if (!g_counts || !g_counters)
		exit_error("malloc error");
	while (i < g_number_of_champions)
	{
		g_counters[i] = string_get_elem(string_create("1", vec3(1.0f - MENU_WIDTH + d_x * (i + 1),
				SPLITER_Y_3 - (SPLITER_Y_3 - SPLITER_Y_4 - SPLITER_HEIGHT) / 1.5, 0.0f),
				STRING_COUNTERS_FONTSIZE, vec4(1.0f, 1.0f, 1.0f, 1.0f), g_window));
		create_line_vao(4 + i, g_counters[i]->position.x, g_counters[i]->position.y
		- (float)(g_counters[i]->image_height + COUNTER_LINES_DISTANCE) / g_w_height, COUNTER_LINES_WIDTH);
		g_lines[4 + i].color = g_str_champions[i]->color;
		i++;
	}
}