#include <libgcorewar.h>

static void	init_carriage(void)
{
	char			i;

	i = 0;
	while (i < g_number_of_champions)
	{
		if (g_carriage_array[i].alive && g_carriage_array[i].prev_position != g_carriage_array[i].position)
		{
			g_carriage_array[i].x = g_carriage_array[i].model[12];
			g_carriage_array[i].y = g_carriage_array[i].model[13];
		}
		i++;
	}
}

static void	complete_carriage(void)
{
	char			i;

	i = 0;
	while (i < g_number_of_champions)
	{
		if (g_carriage_array[i].alive && g_carriage_array[i].prev_position != g_carriage_array[i].position)
		{
			g_carriage_array[i].alive = (g_carriage_array[i].position >= 0);
			if (g_carriage_array[i].alive)
				my_memcpy(g_carriage_array[i].model, g_str_map[g_carriage_array[i].position]->model,
						  16 * sizeof(float));
			else
			{
				free(g_carriage_array[i].model);
				g_carriage_array[i].model = g_carriage_array[i].death_model;
				string_create("XX", g_carriage_array[i].model[12], g_carriage_array[i].model[13],
						STRING_MAP_FONTSIZE, g_str_champions[i]->color, g_window);
			}
		}
		i++;
	}
}

static void	step_carriage(double start, double time)
{
	char			i;

	i = 0;
	while (i < g_number_of_champions)
	{
		if (g_carriage_array[i].alive && g_carriage_array[i].prev_position != g_carriage_array[i].position)
		{
			if (g_carriage_array[i].position >= 0)
			{
				g_carriage_array[i].model[12] = g_carriage_array[i].x +
				   (g_str_map[g_carriage_array[i].position]->model[12]
					- g_carriage_array[i].x) / STEP_TIME * (time - start);
				g_carriage_array[i].model[13] = g_carriage_array[i].y +
				   (g_str_map[g_carriage_array[i].position]->model[13]
					- g_carriage_array[i].y) / STEP_TIME * (time - start);
			}
			else
			{
				g_carriage_array[i].model[12] = g_carriage_array[i].x +
				   (g_carriage_array[i].death_model[12]
					- g_carriage_array[i].x) / STEP_TIME * (time - start);
				g_carriage_array[i].model[13] = g_carriage_array[i].y +
				   (g_carriage_array[i].death_model[13]
					- g_carriage_array[i].y) / STEP_TIME * (time - start);
			}
		}
		i++;
	}
}

char	str_step_carriage(char init, double time)
{
	static	double	start;

	if (init)
	{
		init_carriage();
		start = time;
		return (0);
	}
	else if (time - start > STEP_TIME)
	{
		complete_carriage();
		return (1);
	}
	step_carriage(start, time);
	return (0);
}

