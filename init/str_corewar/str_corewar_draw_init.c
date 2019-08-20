#include <libgcorewar.h>
#include <lgs.h>

char	str_corewar_draw_init(char init, double time)
{
	static	double		start;

	if (init)
	{
		g_str_corewar->model[0] = 0.0f;
		g_str_corewar->model[5] = 0.0f;
		g_str_corewar->active = 1;
		start = time;
		return (0);
	}
	else if ((time - start) > STRING_COREWAR_INIT_TIME)
	{
		g_str_corewar->model[0] = 1.0;
		g_str_corewar->model[5] = 1.0;
		return (1);
	}
	g_str_corewar->model[0] = (time - start) / STRING_COREWAR_INIT_TIME;
	g_str_corewar->model[5] = g_str_corewar->model[0];
	return (0);
}
