#include <libgcorewar.h>

char	x_step(const double time, const char init, const char new_position)
{
	static	double	start = 0;

	if (init)
	{
		if (!-new_position || (g_x.position == -new_position && !g_x.init))
			return (1);
		if (g_x.init)
			g_x.color.w = 0.0f;
		g_x.draw = 1;
		start = time;
		return (0);
	}
	else if (!g_x.init && (time - start) < g_step_time * X_SHOW_TIME)
	{
		g_x.color.w = 1.0f - (time - start) / (g_step_time * X_SHOW_TIME);
		return (0);
	}
	else if ((time - start) > g_step_time * X_SHOW_TIME && (time - start) < g_step_time - g_step_time * X_SHOW_TIME
					&& (g_x.color.w != 0 || g_x.position != new_position))
	{
		g_x.position = -new_position;
		g_x.model.matrix[13] = g_str_champions[-new_position - 1]->position.y;
		g_x.color = g_str_champions[-new_position - 1]->color;
		g_x.color.w = 0.0f;
		return (0);
	}
	else if ((time - start) > g_step_time - g_step_time * X_SHOW_TIME && (time - start) <= g_step_time)
	{
		g_x.color.w = (time - start - (g_step_time - g_step_time * X_SHOW_TIME)) / (g_step_time * X_SHOW_TIME);
		return (0);
	}
	else if ((time - start) > g_step_time)
	{
		g_x.draw = 1;
		g_x.color = g_str_champions[-new_position - 1]->color;
		g_x.model.matrix[13] = g_str_champions[-new_position - 1]->position.y;
		g_x.position = -new_position;
		g_x.init = 0;
		return (1);
	}
	return (0);
}