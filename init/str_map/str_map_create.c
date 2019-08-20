#include <libgcorewar.h>

static void	str_map_string_create(const float d_x, const float d_y)
{
	size_t i;
	char* tmp;
	float x;

	i = 0;
	x = 0;
	while (i < MEM_SIZE)
	{
		tmp = my_base(g_map[i]);
		if (!tmp)
			exit_error("itoa error");
		x += d_x;
		if (i % STRING_MAP_ROW_LENGTH == 0)
			x = -1.0f + BORDER_LENGTH + d_x / 4;
		g_str_map[i] = string_get_elem(string_create(tmp, x,
			 BORDER_CENTER_HORISONTAL_Y_1 - (i / STRING_MAP_ROW_LENGTH + 1) * d_y,
			 STRING_MAP_FONTSIZE, vec3(0.5f, 0.5f, 0.5f), g_window));
		if (g_map[i] != 0)
			g_str_map[i]->color = vec3(0.6f, 0.6f, 0.0f);
		g_str_map[i]->draw_func = str_map_draw_function;
		if (g_carriage_height < g_str_map[i]->image_height)
			g_carriage_height = g_str_map[i]->image_height;
		if (g_carriage_width < g_str_map[i]->image_width)
			g_carriage_width = g_str_map[i]->image_width;
		free(tmp);
		i++;
	}
}

void	str_map_create(unsigned char const *const map)
{
	size_t i;

	g_map = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	if (!g_map)
		exit_error("str_map malloc error");
	i = 0;
	while (i < MEM_SIZE)
	{
		g_map[i] = map[i];
		i++;
	}
	g_carriage_width = 0;
	g_carriage_height = 0;
	g_str_map = (t_string**)malloc(sizeof(t_string*) * MEM_SIZE);
	str_map_string_create((BORDER_CENTER_VERTICAL_X + 1.0f - BORDER_LENGTH) / (STRING_MAP_ROW_LENGTH),
						  (BORDER_CENTER_HORISONTAL_Y_1 + 1.0f - BORDER_LENGTH)
						  / (MEM_SIZE / STRING_MAP_ROW_LENGTH + (MEM_SIZE % STRING_MAP_ROW_LENGTH > 0) + 1));
	g_map_opacity = 0.0f;
}

