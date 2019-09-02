#include <libgcorewar.h>

char	x_step(double time, char init, char new_position)
{
	static	double	start = 0;

	if (init)
	{
		if (!new_position || (g_x.position == new_position && !g_x.init))
			return (1);
		/*if (!STEP_TIME)
		{
			g_x.position = new_position;
			g_x.model[13] = g_str_champions[new_position - 1]->translate[13];
			g_x.color = g_str_champions[new_position - 1]->color;
			g_x.color.w = 1.0f;
			g_x.draw = 1;
			g_x.init = 0;
			return (1);
		}*/
		if (g_x.init)
			g_x.color.w = 0.0f;
		g_x.draw = 1;
		start = time;
		return (0);
	}
	else if (!g_x.init && (time - start) < STEP_TIME * X_SHOW_TIME)
	{
		g_x.color.w = 1.0f - (time - start) / (STEP_TIME * X_SHOW_TIME);
		return (0);
	}
	else if ((time - start) > STEP_TIME * X_SHOW_TIME && (time - start) < STEP_TIME - STEP_TIME * X_SHOW_TIME
					&& (g_x.color.w != 0 || g_x.position != new_position))
	{
		g_x.position = new_position;
		g_x.model[13] = g_str_champions[new_position - 1]->translate[13];
		g_x.color = g_str_champions[new_position - 1]->color;
		g_x.color.w = 0.0f;
		return (0);
	}
	else if ((time - start) > STEP_TIME - STEP_TIME * X_SHOW_TIME && (time - start) <= STEP_TIME)
	{
		g_x.color.w = (time - start - (STEP_TIME - STEP_TIME * X_SHOW_TIME)) / (STEP_TIME * X_SHOW_TIME);
		return (0);
	}
	else if ((time - start) > STEP_TIME)
	{
		g_x.draw = 1;
		g_x.color.w = 1.0f;
		g_x.init = 0;
		return (1);
	}
	return (0);
}