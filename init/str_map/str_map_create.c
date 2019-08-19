#include <libgcorewar.h>

static void	str_map_string_create(void)
{
	const float d_x = (BORDER_CENTER_VERTICAL_X + 1.0f - BORDER_LENGTH) / (STRING_MAP_ROW_LENGTH + 1);
	const float d_y = (BORDER_CENTER_HORISONTAL_Y_1 + 1.0f - BORDER_LENGTH)
			/ (MEM_SIZE / STRING_MAP_ROW_LENGTH + (MEM_SIZE % STRING_MAP_ROW_LENGTH > 0) + 1);
	size_t i;
	char* tmp;
	float tmp1;
	float tmp2;

	i = 0;
	while (i < MEM_SIZE)
	{
		tmp = my_itoabase(g_map[i], 16, 1);
		if (!tmp)
			exit_error("itoa error");
		tmp1 = -1.0f + BORDER_LENGTH + (i % STRING_MAP_ROW_LENGTH + 1) * d_x;
		tmp2 = BORDER_CENTER_HORISONTAL_Y_1 - (i / STRING_MAP_ROW_LENGTH + 1) * d_y;
		g_str_map[i] = string_get_elem(string_create(tmp, tmp1,
		 tmp2, STRING_MAP_FONTSIZE, vec2(1.0f, 1.0f), g_window));
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
	g_str_map = (t_string**)malloc(sizeof(t_string*) * MEM_SIZE);
	str_map_string_create();
}

