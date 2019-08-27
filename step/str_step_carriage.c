#include <libgcorewar.h>

static void	init_carriage(void)
{
	t_carriage_lst* elem;

	elem = g_carriage_lst;
	while (elem)
	{
		if (elem->alive && elem->prev_position != elem->position)
		{
			elem->prev_x = elem->x;
			elem->prev_y = elem->y;
		}
		elem = elem->next;
	}
}

static void	complete_carriage(void)
{
	t_carriage_lst* elem;

	elem = g_carriage_lst;
	while (elem)
	{
		if (elem->alive && elem->prev_position != elem->position)
		{
//			g_carriage_array[i].alive = (g_carriage_array[i].position >= 0);
//			if (g_carriage_array[i].alive)
//			{
			elem->x = g_str_map[elem->position]->translate[12];
			elem->y = g_str_map[elem->position]->translate[13];
//			}
//			else
//			{
//				free(g_carriage_array[i].model);
//				g_carriage_array[i].model = g_carriage_array[i].death_model;
//				string_create("XX", g_carriage_array[i].model[12], g_carriage_array[i].model[13],
//						STRING_MAP_FONTSIZE, g_str_champions[i]->color, g_window);
//			}
		}
		else if (!elem->alive)
			carriage_list_del(&g_carriage_lst, elem);
		elem = elem->next;
	}
}

static void	step_carriage(double start, double time)
{
	t_carriage_lst* elem;

	elem = g_carriage_lst;
	while (elem)
	{
		if (elem->alive && elem->prev_position != elem->position)
		{
			elem->x = elem->prev_x +
			   (g_str_map[elem->position]->translate[12]
				- elem->prev_x) / STEP_TIME * (time - start);
			elem->y = elem->prev_y +
			   (g_str_map[elem->position]->translate[13]
				- elem->prev_y) / STEP_TIME * (time - start);
		}
		elem = elem->next;
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

