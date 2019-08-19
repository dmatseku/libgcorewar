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
		printf("%f\n", time);
		return (0);
	}
	else if ((time - start) > STRING_COREWAR_INIT_TIME)
	{
		g_str_corewar->model[0] = 1.0;
		g_str_corewar->model[5] = 1.0;
		printf("%f\n", time - start);
		return (1);
	}
	printf("%f\n", time - start);
	g_str_corewar->model[0] = (time - start) / STRING_COREWAR_INIT_TIME;
	g_str_corewar->model[5] = g_str_corewar->model[0];
	return (0);
}
