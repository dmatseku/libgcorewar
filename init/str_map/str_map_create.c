#include <libgcorewar.h>

static void str_map_string_complement(size_t i, float x, float y, const float d_x)
{
	while (i % STRING_MAP_ROW_LENGTH)
	{
		x += d_x;
		g_str_map[i] = string_get_elem(string_create("XX", x,
			 y,
			 STRING_MAP_FONTSIZE,
			 vec3(0.556862745098039f, 0.556862745098039f, 0.556862745098039f), g_window));
		g_str_map[i]->draw_func = str_map_draw_function;
		if (g_carriage_height < g_str_map[i]->image_height)
			g_carriage_height = g_str_map[i]->image_height;
		if (g_carriage_width < g_str_map[i]->image_width)
			g_carriage_width = g_str_map[i]->image_width;
		i++;
	}
}

static void	str_map_string_create(const float d_x, const float d_y, unsigned char const *const owner)
{
	size_t i;
	char* tmp;
	float x;
	float y;

	i = 0;
	x = 0;
	y = 1.0f - d_y - d_y / 2;
	while (i < MEM_SIZE)
	{
		tmp = my_base(g_map[i]);
		if (!tmp)
			exit_error("itoa error");
		x += d_x;
		if (i % STRING_MAP_ROW_LENGTH == 0)
		{
			x = -1.0f + d_x + d_x / 2;
			if (i > 0)
				y -= d_y;
		}
		g_str_map[i] = string_get_elem(string_create(tmp, x,
			 y,
			 STRING_MAP_FONTSIZE, vec3(0.8f, 0.8f, 0.8f), g_window));
		if (owner[i])
			g_str_map[i]->color = g_str_champions[owner[i] - 1]->color;
		g_str_map[i]->draw_func = str_map_draw_function;
		if (g_carriage_height < g_str_map[i]->image_height)
			g_carriage_height = g_str_map[i]->image_height;
		if (g_carriage_width < g_str_map[i]->image_width)
			g_carriage_width = g_str_map[i]->image_width;
		free(tmp);
		i++;
	}
	str_map_string_complement(i, x, y, d_x);
}

// vec3(0.556862745098039f, 0.556862745098039f, 0.556862745098039f)

void	str_map_create(unsigned char const *const map, unsigned char *const owner)
{
	size_t i;


//	size_t tmp = (MEM_SIZE + (STRING_MAP_ROW_LENGTH - (MEM_SIZE % STRING_MAP_ROW_LENGTH)));
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
	g_str_map = (t_string**)malloc(sizeof(t_string*)
			* (MEM_SIZE + (STRING_MAP_ROW_LENGTH - (MEM_SIZE % STRING_MAP_ROW_LENGTH))));
	str_map_string_create((2.0f - MENU_WIDTH) / (STRING_MAP_ROW_LENGTH + 2),
			2.0f / (MEM_SIZE / STRING_MAP_ROW_LENGTH + (MEM_SIZE % STRING_MAP_ROW_LENGTH > 0) + 2), owner);
	g_map_opacity = 0.0f;
}

