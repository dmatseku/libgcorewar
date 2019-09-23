#include <libgcorewar.h>

char	str_step_counter_draw_init(const char init, const double time)
{
	static double start;

	if (init)
	{
		start = time;
		return (0);
	}
	else if ((time - start) >= STR_ST_IT)
	{
		g_str_step_counter->active = 1;
		g_str_step->active = 1;
		return (1);
	}
	if (((int) ((time - start) / STR_ST_IDT)) % 2)
	{
		g_str_step_counter->active = 1;
		g_str_step->active = 1;
	}
	else
	{
		g_str_step_counter->active = 0;
		g_str_step->active = 0;
	}
	return (0);
}