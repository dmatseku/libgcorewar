#include <libgcorewar.h>

char	str_map_draw_init(char init, double time)
{
	static double	start;

	if (init)
	{
		start = time;
		return (0);
	}
	else if (time - start > STRING_MAP_INIT_TIME)
	{
		g_map_opacity = 1.0f;
		return (1);
	}
	g_map_opacity = (time - start) / STRING_MAP_INIT_TIME;
	return (0);
}