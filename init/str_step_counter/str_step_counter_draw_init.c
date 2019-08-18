#include <libgcorewar.h>

char	str_step_counter_draw_init(char init, double time)
{
	static	double		start;

	if (init)
	{
		start = time;
		g_str_step_counter->active = 0;
		return (0);
	}
	else if ((time - start) >= STRING_STEP_INIT_TIME)
	{
		g_str_step_counter->active = 1;
		return (1);
	}
	if (((int)((time - start) / STRING_STEP_INIT_DTIME)) % 2)
		g_str_step_counter->active = 1;
	else
		g_str_step_counter->active = 0;
	return (0);
}