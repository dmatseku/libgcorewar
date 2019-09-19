#include <libgcorewar.h>

void	key_shift(void* args)
{
	size_t i;
	char tmp[3] = "XX\0";

	i = 0;
	(void)args;
	g_hidden = !g_hidden;
	if (!g_hidden)
	{
		g_update_map = update_map;
		g_carriages_draw = carriages_draw;
		while (i < MEM_SIZE)
		{
			my_base(g_map[i], tmp);
			string_update_nospace(g_str_map[i], tmp, g_w_width, g_w_height);
			i++;
		}
	}
	else
	{
		g_update_map = non_update_map;
		g_carriages_draw = non_carriages_draw;
		while (i < MEM_SIZE)
		{
			string_update_nospace(g_str_map[i], tmp, g_w_width, g_w_height);
			i++;
		}
	}
}
